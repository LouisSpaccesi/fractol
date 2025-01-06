/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lospacce < lospacce@student.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:52:26 by lospacce          #+#    #+#             */
/*   Updated: 2025/01/06 16:01:31 by lospacce         ###   ########.fr       */
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
	// double mouse_re;
	// double mouse_im;
	// static double zoom;

	// zoom = 1.0;
	
    (void)data;
	(void)x;
	(void)y; 

    if (button == buttonfront)
	{
	data->zoom *= 1.1;
 	// mouse_re = data->re_min + (x * (data->re_max - data->re_min) / WINDOW_WIDTH);
    // mouse_im = data->im_min + (y * (data->im_max - data->im_min) / WINDOW_HEIGHT);
    // printf("Clic vers l'avant : x = %d, y = %d\n", x, y);
	// printf("\n");
	// printf("%f", data->zoom);
	}
	else if (button == buttonback)
	{
		data->zoom *= 0.9;
		
	    // printf("Clic versd l arrriere: x = %d, y = %d\n", x, y);
		// printf("\n");
		// printf("%f", data->zoom);
	}
	// printf("valeur zoom %f", zoom);
    return 0;
}

