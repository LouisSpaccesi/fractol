/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lospacce < lospacce@student.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:34:45 by lospacce          #+#    #+#             */
/*   Updated: 2025/01/27 19:00:42 by lospacce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	handle_julia(int keysym, t_data *data)
{
	if (keysym == XK_j)
	{
		data->julia_x_iter = -0.4;
		data->julia_y_iter = 0.6;
	}
	if (keysym == XK_u)
	{
		data->julia_x_iter = 0.34;
		data->julia_y_iter = -0.05;
	}
	if (keysym == XK_l)
	{
		data->julia_x_iter = -0.122;
		data->julia_y_iter = 0.744;
	}
	if (keysym == XK_i)
	{
		data->julia_x_iter = -0.8;
		data->julia_y_iter = 0.156;
	}
	if (keysym == XK_a)
	{
		data->julia_x_iter = -1.2;
		data->julia_y_iter = 0.2;
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