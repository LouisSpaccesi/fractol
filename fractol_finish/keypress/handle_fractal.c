/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lospacce < lospacce@student.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:34:45 by lospacce          #+#    #+#             */
/*   Updated: 2025/01/28 15:48:38 by lospacce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	handle_julia_a(int keysym, t_julia *julia)
{
	if (keysym == XK_a)
	{
		julia->julia_x_iter = -1.2;
		julia->julia_y_iter = 0.2;
	}
}

void	handle_julia(int keysym, t_julia *julia)
{
	if (keysym == XK_j)
	{
		julia->julia_x_iter = -0.4;
		julia->julia_y_iter = 0.6;
	}
	if (keysym == XK_u)
	{
		julia->julia_x_iter = 0.34;
		julia->julia_y_iter = -0.05;
	}
	if (keysym == XK_l)
	{
		julia->julia_x_iter = -0.122;
		julia->julia_y_iter = 0.744;
	}
	if (keysym == XK_i)
	{
		julia->julia_x_iter = -0.8;
		julia->julia_y_iter = 0.156;
	}
	handle_julia_a(keysym, julia);
}

void	handle_arrow(int keysym, t_data *data)
{
	if (keysym == XK_equal)
	{
		if (data->iteration < 300)
			data->iteration++;
	}
	if (keysym == XK_minus)
	{
		if (data->iteration > 0)
			data->iteration--;
	}
	if (keysym == XK_Return)
	{
		data->mouse_re = 0.0;
		data->mouse_im = 0.0;
		data->zoom = 1.0;
	}
}

void	return_before_position(int keysym, t_data *data)
{
	if (keysym == XK_s)
	{
		data->position_zoom = data->zoom;
		data->position_mouse_im = data->mouse_im;
		data->position_mouse_re = data->mouse_re;
	}
	if (keysym == XK_g)
	{
		if (data->position_zoom != 0.0)
		{
			data->zoom = data->position_zoom;
			data->mouse_im = data->position_mouse_im;
			data->mouse_re = data->position_mouse_re;
		}
		else
			return ;
	}
}

void	handle_direction(int keysym, t_data *data)
{
	if (keysym == XK_Up)
		data->mouse_im -= 0.2 / data->zoom;
	if (keysym == XK_Left)
		data->mouse_re -= 0.2 / data->zoom;
	if (keysym == XK_Right)
		data->mouse_re += 0.2 / data->zoom;
	if (keysym == XK_Down)
		data->mouse_im += 0.2 / data->zoom;
}
