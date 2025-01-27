/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lospacce < lospacce@student.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:39:33 by lospacce          #+#    #+#             */
/*   Updated: 2025/01/27 12:33:57 by lospacce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_fractol_burningship(double c_re, double c_im, t_data *data)
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
		z_im2 = ABS(2 * z_re * z_im) + c_im;
		z_re = z_re2;
		z_im = z_im2;
		iter++;
	}
	return (iter);
}

void	graph_burningship(t_img *img, t_data *data)
{
	int	iter;

	data->burn_y = 0;
	while (data->burn_y < WINDOW_HEIGHT)
	{
		data->burn_x = 0;
		while (data->burn_x < WINDOW_WIDTH)
		{
			data->burn_c_re = (data->burn_x - WINDOW_WIDTH / 2.0) * 4.0
				/ WINDOW_WIDTH / data->zoom + data->mouse_re;
			data->burn_c_im = (data->burn_y - WINDOW_HEIGHT / 2.0) * 4.0
				/ WINDOW_HEIGHT / data->zoom + data->mouse_im;
			iter = ft_fractol_burningship(data->burn_c_re, data->burn_c_im, data);
			data->color = data->change_center_color;
			if (iter < data->iteration)
				data->color = data->rgb + (iter * 1000 / data->iteration)
					* data->change_color;
			else
				data->color = data->change_center_color;
			img_pix_put(img, data->burn_x, data->burn_y,
				data->color);
			data->burn_x++;
		}
		data->burn_y++;
	}
}

int	render_burningship(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	graph_burningship(&data->img, data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0,
		0);
	return (0);
}

int	init_burningship(t_data *data)
{
	data->zoom = 1.0;
	data->mouse_re = 0.0;
	data->mouse_im = 0.0;
	data->change_center_color = 0x000000;
	data->change_color = 256;
	data->change_center_color = 0x000000;
	data->iteration = 50;
	data->rgb = 0x0000FF;
	data->burn_x = 0;
	data->burn_y = 0;
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
			"Burningship");
	if (data->win_ptr == NULL)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		return (1);
	}
	return (0);
}

int	burningship(void)
{
	t_data	data;

	if (init_burningship(&data))
		return (1);
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp,
			&data.img.line_len, &data.img.endian);
	mlx_hook(data.win_ptr, 17, 0, &handle_cross, &data);
	mlx_mouse_hook(data.win_ptr, ft_zoom, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_loop_hook(data.mlx_ptr, &render_burningship, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	return (0);
}
