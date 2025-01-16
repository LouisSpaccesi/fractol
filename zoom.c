/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lospacce <lospacce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:52:26 by lospacce          #+#    #+#             */
/*   Updated: 2025/01/16 17:00:17 by lospacce         ###   ########.fr       */
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
	// static double zoom;

	// zoom = 1.0;

	(void)y;
	//int		mlx_mouse_get_pos(t_xvar *xvar, t_win_list *win, int *win_x_return, int *win_y_return);
	double zoom_re = 1.0;
	double zoom_im = 1.0;
//	double zoom_im;
		
	// int mouse = mlx_mouse_get_pos(data->mlx_ptr, data->win_ptr, &x, &y);
	// int mouse = mlx_mouse_move(data->mlx_ptr, data->win_ptr, x, y);
	// printf("%f\n", zoom_re);
	// printf("%d\n", y);

	printf("-----\n");

	zoom_re = (x - WINDOW_WIDTH / 2.0)* 4.0 / WINDOW_WIDTH;
	zoom_im = (y - WINDOW_WIDTH / 2.0 )* 4.0 / WINDOW_WIDTH;
	// printf("%f\n", zoom_re);

	data->mouse_re = zoom_re;
	data->mouse_im = zoom_im;
	printf("%f", data->mouse_re);
	printf("%f", data->mouse_im);

	// mlx_mouse_get_pos(data->mlx_ptr, data->win_ptr, &x, &y);
    if (button == buttonfront)
		data->zoom *= 1.1;
	else if (button == buttonback)
		data->zoom *= 0.9;
    return 0;
}



