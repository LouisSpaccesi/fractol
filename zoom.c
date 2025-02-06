/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lospacce < lospacce@student.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:52:26 by lospacce          #+#    #+#             */
/*   Updated: 2025/02/06 12:49:07 by lospacce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int	ft_zoom(int button, int x, int y, t_data *data)
{
	double	zoom_re;
	double	zoom_im;

	zoom_re = (x - WINDOW_WIDTH / 2.0) * 4.0 / WINDOW_WIDTH / data->zoom
		+ data->mouse_re;
	zoom_im = (y - WINDOW_HEIGHT / 2.0) * 4.0 / WINDOW_HEIGHT / data->zoom
		+ data->mouse_im;
	if (button == BUTOONLEFT)
	{
		data->mouse_pressed = 1;
		if (data->fractal_type == 2)
		{
			data->julia.julia_x_iter = zoom_re;
			data->julia.julia_y_iter = zoom_im;
		}
	}
	if (button == BUTTONFRONT)
	{
		data->zoom *= 1.1;
		data->mouse_re = zoom_re - (zoom_re - data->mouse_re) / 1.1;
		data->mouse_im = zoom_im - (zoom_im - data->mouse_im) / 1.1;
	}
	else if (button == BUTOONBACK)
		data->zoom *= 0.9;
	return (0);
}
