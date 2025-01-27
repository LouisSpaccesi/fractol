/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lospacce < lospacce@student.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:19:08 by lospacce          #+#    #+#             */
/*   Updated: 2025/01/26 19:15:46 by lospacce         ###   ########.fr       */
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
	if (keysym == XK_v)
		data->change_color++;
	if (keysym == XK_c)
		data->change_color--;
	if(keysym == XK_m)
		data->change_center_color = (data->iteration * 123) % 0xFFFFFF;
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

void return_before_position(int keysym, t_data *data)
{
	if(keysym == XK_s)
	{
		data->position_zoom = data->zoom;
		data->position_mouse_im = data->mouse_im;
		data->position_mouse_re = data->mouse_re;
	}
	if(keysym == XK_g)
	{
		if(data->position_zoom != 0.0)
		{
			data->zoom = data->position_zoom;
			data->mouse_im = data->position_mouse_im;
			data->mouse_re = data->position_mouse_re;
		}
		else
			return ;
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
	if (keysym == XK_1)
	{
		mlx_destroy_display(data->mlx_ptr);
		mandelbrot();
	}
	if (keysym == XK_2)
	{
		mlx_destroy_display(data->mlx_ptr);
		julia();
	}
	if (keysym == XK_3)
	{
		mlx_destroy_display(data->mlx_ptr);
		burningship();
	}
	return_before_position(keysym, data);
	handle_arrow(keysym, data);
	handle_julia(keysym, data);
	handle_color(keysym, data);
	handle_direction(keysym, data);
	return (0);
}
