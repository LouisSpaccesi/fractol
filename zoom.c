/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lospacce < lospacce@student.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:52:26 by lospacce          #+#    #+#             */
/*   Updated: 2025/01/16 19:36:14 by lospacce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include <mlx.h>
#include "math.h"
#include "fractol.h"
#define buttonfront 4
#define buttonback 5

int ft_zoom(int button, int x, int y, t_data *data)
{

	double long zoom_re;
	double long zoom_im;

	zoom_re = (x - WINDOW_WIDTH / 2.0)* 4.0 / WINDOW_WIDTH / data->zoom + data->mouse_re;
	zoom_im = (y - WINDOW_HEIGHT / 2.0)* 4.0 / WINDOW_HEIGHT / data->zoom + data->mouse_im;
    if (button == buttonfront)
	{
		data->zoom *= 1.1;
		data->mouse_re = zoom_re - (zoom_re - data->mouse_re) / 1.1;
		data->mouse_im = zoom_im - (zoom_im - data->mouse_im) / 1.1;
	}
	else if (button == buttonback)
	{
		data->zoom *= 0.9;
		data->mouse_re = zoom_re - (zoom_re - data->mouse_re) / 0.9;
		data->mouse_im = zoom_im - (zoom_im - data->mouse_im) / 0.9;
	}
    return 0;
}



