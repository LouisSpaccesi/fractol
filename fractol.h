/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lospacce < lospacce@student.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:14:23 by lospacce          #+#    #+#             */
/*   Updated: 2025/01/06 16:07:54 by lospacce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H
#include "mlx.h"
#include "stdlib.h"

#define WINDOW_WIDTH 720
#define WINDOW_HEIGHT 520

#define MLX_ERROR 1

#define RED_PIXEL 0xFF0000
#define GREEN_PIXEL 0xFF00
#define BLUE_PIXEL 0xFFFFFF
#define MAX_ITERATION 50

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp; 
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	int		cur_img;
	double		re_min;
	double		re_max;
	double		im_min;
	double		im_max;
	double		zoom;
	double		left;
	double		right;
	double		offset_left;
	double		offset_right;
}	t_data;

int ft_zoom(int button, int x, int y, t_data *data);

#endif
