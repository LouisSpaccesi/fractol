/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lospacce <lospacce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:11:02 by lospacce          #+#    #+#             */
/*   Updated: 2025/01/27 17:00:27 by lospacce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
#include <math.h>

int	ft_mandelbrot(double c_re, double c_im, t_data *data)
{
	double	z_re;
	double	z_im;
	double	z_re2;
	double	z_im2;
	int		iter;

	z_re = 0;
	z_im = 0;
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

void	graph_mandelbrot(t_img *img, t_data *data)
{
	int iter;

	mand->mand_y = 0;
	while (mand->mand_y < WINDOW_HEIGHT)
	{
		mand->mand_x = 0;
		while (mand->mand_x < WINDOW_WIDTH)
		{
			mand->mand_c_re = (mand->mand_x - WINDOW_WIDTH / 2.0) * 4.0
				/ WINDOW_WIDTH / data->zoom + data->mouse_re;
			mand->mand_c_im = (mand->mand_y - WINDOW_HEIGHT / 2.0) * 4.0
				/ WINDOW_HEIGHT / data->zoom + data->mouse_im;
			iter = ft_mandelbrot(mand->mand_c_re, mand->mand_c_im, data);
			data->color = data->change_center_color;
			if (iter < data->iteration)
				data->color = data->rgb + (iter * 1000 / data->iteration)
					* data->change_color;
			else
				data->color = data->change_center_color;
			img_pix_put(img, mand->mand_x, mand->mand_y, data->color);
			mand->mand_x++;
		}
		mand->mand_y++;
	}
}

int	render_mandelbrot(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	graph_mandelbrot(&data->img, data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0,
		0);
	return (0);
}

int	init_mandelbrot(t_data *data)
{
	data->zoom = 1.0;
	data->mouse_re = 0.0;
	data->mouse_im = 0.0;
	data->change_center_color = 0x000000;
	data->change_color = 256;
	data->iteration = 50;
	data->rgb = 0x0000FF;
	data->mand_x = 0;
	data->mand_y = 0;
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
			"Mandelbrot");
	if (data->win_ptr == NULL)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		return (1);
	}
	return (0);
}

int	mandelbrot(void)
{
	t_data	data;
	t_mand	mand;

	if (init_mandelbrot(&data, &mand))
		return (1);
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp,
			&data.img.line_len, &data.img.endian);
	mlx_hook(data.win_ptr, 17, 0, &handle_cross, &data);
	mlx_mouse_hook(data.win_ptr, ft_zoom, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_loop_hook(data.mlx_ptr, &render_mandelbrot, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	return (0);
}
