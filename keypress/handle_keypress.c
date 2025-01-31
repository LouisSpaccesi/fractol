/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lospacce < lospacce@student.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:19:08 by lospacce          #+#    #+#             */
/*   Updated: 2025/01/31 23:26:36 by lospacce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	handle_cross(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

int	ticksrandom(t_data *data, int min, int max, int iter)
{
	unsigned long	seed;

	seed = data->ticks * iter;
	return (min + (seed % (max - min - 1)));
}

static void	handle_color(int keysym, t_data *data)
{
	if (keysym == XK_space)
		data->rgb = color_ticks(data);
	if (keysym == XK_c)
		data->change_color = color_ticks(data);
	if (keysym == XK_m)
		data->change_center_color = color_ticks(data);
}

static void	handle_windows(int keysym, t_data *data, int argc)
{
	(void)argc;
	if (keysym == XK_Escape)
	{
		free_window(data);
		exit(0);
	}
	if (keysym == XK_1 || keysym == XK_2 || keysym == XK_3)
	{
		if (keysym == XK_1)
		{
			free_window(data);
			data->fractal_type = 1;
		}
		if (keysym == XK_2)
		{
			free_window(data);
			data->fractal_type = 2;
		}
		if (keysym == XK_3)
		{
			free_window(data);
			data->fractal_type = 3;
		}
		render_fractal(data, argc);
	}
}

int	handle_keypress(int keysym, t_data *data, int argc)
{
	(void)argc;
	handle_windows(keysym, data, argc);
	return_before_position(keysym, data);
	handle_arrow(keysym, data);
	handle_julia(keysym, &data->julia);
	handle_color(keysym, data);
	handle_direction(keysym, data);
	return (0);
}
