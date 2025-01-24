/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lospacce <lospacce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:02:33 by lospacce          #+#    #+#             */
/*   Updated: 2025/01/24 17:01:39 by lospacce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_fractol_julia(double z_re, double z_im, double c_re, double c_im,
		t_data *data)
{
	double	z_re2;
	double	z_im2;
	int		iter;

	iter = 0;
	while (z_re * z_re + z_im * z_im <= 4 && iter < data->iteration)
	{
		z_re2 = z_re * z_re - z_im * z_im + c_re;
		z_im2 = 2 * z_re * z_im + c_im;
		z_re = z_re2;
		z_im = z_im2;
		iter++;
	}
	return (iter);
}

void	graph_julia(t_img *img, t_data *data)
{
	int		x;
	int		y;
	double	z_re;
	double	z_im;
	int		iter;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			z_re = (x - WINDOW_WIDTH / 2.0) * 4.0 / WINDOW_WIDTH / data->zoom
				+ data->mouse_re;
			z_im = (y - WINDOW_HEIGHT / 2.0) * 4.0 / WINDOW_HEIGHT / data->zoom
				+ data->mouse_im;
			iter = ft_fractol_julia(z_re, z_im, data->julia_x, data->julia_y,
					data);
			data->color = 0x000000;
			if (iter < data->iteration)
				data->color = data->rgb + (iter * 1000 / data->iteration)
					* data->change_color;
			img_pix_put(img, x, y, data->color);
			x++;
		}
		y++;
	}
}

int	render_julia(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	graph_julia(&data->img, data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0,
		0);
	return (0);
}

static int	init_julia(t_data *data)
{
	data->zoom = 1.0;
	data->mouse_re = 0.0;
	data->mouse_im = 0.0;
	data->mlx_ptr = mlx_init();
	data->iteration = 50;
	data->change_color = 256;
	data->rgb = 0x0000FF;
	data->julia_x = -0.4;
	data->julia_y = 0.6;
	if (data->mlx_ptr == NULL)
		return (1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
			"Julia");
	if (data->win_ptr == NULL)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		return (1);
	}
	return (0);
}

int	julia(void)
{
	t_data data;

	if (init_julia(&data))
		return (1);
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp,
			&data.img.line_len, &data.img.endian);
	mlx_hook(data.win_ptr, 17, 0, &handle_cross, &data);
	mlx_mouse_hook(data.win_ptr, ft_zoom, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_loop_hook(data.mlx_ptr, &render_julia, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	return (0);
}

