/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lospacce < lospacce@student.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:25:08 by lospacce          #+#    #+#             */
/*   Updated: 2025/01/31 22:35:27 by lospacce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	free_window(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
}

static int	handle_error(t_data *data)
{
	if (!data->mlx_ptr)
		return (1);
	if (data->win_ptr == NULL)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		return (1);
	}
	return (0);
}

static int	setup_fractal(t_data *data, int argc)
{
	data->zoom = 1.0;
	data->mouse_re = 0.0;
	data->mouse_im = 0.0;
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (1);
	if (data->fractal_type == 2 && argc == 2)
	{
		data->mouse_pressed = 0;
		data->julia.julia_x_iter = -0.4;
		data->julia.julia_y_iter = 0.6;
	}
	data->change_center_color = 0x000000;
	data->change_color = 256;
	data->iteration = 50;
	data->rgb = 0x0000FF;
	if (data->fractal_type == 3)
		data->rgb = 0x0FF00000;
	return (0);
}

int	init_fractal(t_data *data, int argc)
{
	(void)argc;
	if (setup_fractal(data, argc))
		return (1);
	if (data->fractal_type == 1)
	{
		data->mand.mandelbrot_x = 0;
		data->mand.mandelbrot_y = 0;
		data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH,
				WINDOW_HEIGHT, "Mandelbrot");
	}
	if (data->fractal_type == 2)
		data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH,
				WINDOW_HEIGHT, "Julia");
	if (data->fractal_type == 3)
	{
		data->burn.burn_x = 0;
		data->burn.burn_y = 0;
		data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH,
				WINDOW_HEIGHT, "Burningship");
	}
	if (handle_error(data))
		return (1);
	return (0);
}
