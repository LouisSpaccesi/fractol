/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lospacce <lospacce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:19:08 by lospacce          #+#    #+#             */
/*   Updated: 2025/01/24 17:22:01 by lospacce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
   
	if (keysym == XK_v)
	    data->change_color++;
	if (keysym == XK_c)
	    data->change_color--;
	if (keysym == XK_Return)
	{
		data->mouse_re = 0.0;
		data->mouse_im = 0.0;
		data->zoom = 1.0;
	}
}

void	handle_julia(int keysym, t_data *data)
{
	if (keysym == XK_j)
	{
		data->julia_x = -0.4;
		data->julia_y = 0.6;
	}
	if (keysym == XK_u)
	{
		data->julia_x = 0.34;
		data->julia_y = -0.05;
	}
	if (keysym == XK_l)
	{
		data->julia_x = -0.122;
		data->julia_y = 0.744;
	}
	if (keysym == XK_i)
	{
		data->julia_x = -0.8;
		data->julia_y = 0.156;
	}
	if (keysym == XK_a)
	{
		data->julia_x = -1.2;
		data->julia_y = 0.2;
	}
}

void	handle_color(int keysym, t_data *data)
{
	if (keysym == XK_space)
	{
		if (data->rgb == 0x0000FF)
			data->rgb = 0x00FF00;
		else if (data->rgb == 0x00FF00)
			data->rgb = 0xFF0000;
		else if (data->rgb == 0xFF0000)
			data->rgb = 0xFFFF00;
		else if (data->rgb == 0xFFFF00)
			data->rgb = 0x0000FF;
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

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
		exit(0);
	}
	if (keysym == XK_1)
		mandelbrot();
	if (keysym == XK_2)
		julia();
	handle_arrow(keysym, data);
	handle_julia(keysym, data);
	handle_color(keysym, data);
	handle_direction(keysym, data);
	return (0);
}
