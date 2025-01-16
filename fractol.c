/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lospacce < lospacce@student.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:11:02 by lospacce          #+#    #+#             */
/*   Updated: 2025/01/16 19:50:36 by lospacce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include <mlx.h>
#include "math.h"
#include "fractol.h"

int		ft_fractol(double c_re, double c_im)
{
	double	z_re;
	double	z_im;
	double	z_re2;
	double	z_im2;
	int		iter;
	
	z_re = 0;
	z_im = 0;
	iter = 0;

	while (z_re * z_re + z_im * z_im <= 4 && iter < MAX_ITERATION)
	{
		z_re2 = z_re * z_re - z_im * z_im + c_re;
		z_im2 = 2 * z_re * z_im + c_im;
		z_re = z_re2;
		z_im = z_im2;
		iter++;
	}
	return (iter);
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char    *pixel;

	if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
		return;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}

void	render_fractal(t_img *img, t_data *data)
{
	int x;
	int y;
	int color;
	double	c_re;
	double c_im;
	int iter;

	y = 0;
	while(y < WINDOW_HEIGHT)
	{
		x = 0;
		while(x < WINDOW_WIDTH)
		{
			c_re = (x - WINDOW_WIDTH / 2.0) * 4.0 / WINDOW_WIDTH / data->zoom + data->mouse_re;
            c_im = (y - WINDOW_HEIGHT / 2.0) * 4.0 / WINDOW_HEIGHT / data->zoom + data->mouse_im;
			iter = ft_fractol(c_re, c_im);
			color = 0x000000;
			if (iter < MAX_ITERATION)
				color = 0x0000FF + (iter * 600 / MAX_ITERATION) * 256;
			img_pix_put(img, x, y, color);
			x++;
		}
		y++;
	}
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
		exit(0);
	}
	// if(keysym == XK_Left)
	// {
	// 	data->offset_left;
	// }
	// else if (keysym == XK_Right)
	// 	printf("OK");
	return (0);
}

int handle_cross(t_data *data)
{
	if(data->win_ptr != NULL)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
		exit(0);
	}
	return (0);
}

int	render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	render_fractal(&data->img, data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}

int	main(void)
{
	t_data	data;

	data.zoom = 1.0;
	data.mouse_re = 0.0;
	data.mouse_im = 0.0;
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
	{
		free(data.mlx_ptr);
		return (1);
	}
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "Mandelbrot");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (1);
	}
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, &data.img.line_len, &data.img.endian);
	mlx_hook(data.win_ptr, 17, 0, &handle_cross, &data);
	mlx_mouse_hook(data.win_ptr, ft_zoom, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	return (0);
}
