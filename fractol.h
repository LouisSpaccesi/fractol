/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lospacce <lospacce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:14:23 by lospacce          #+#    #+#             */
/*   Updated: 2025/01/27 16:58:12 by lospacce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "./ft_printf/./ft_printf.h"
# include "mlx.h"
# include "stdlib.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <string.h>
#include <math.h>

# define WINDOW_WIDTH 720
# define WINDOW_HEIGHT 520

# define MLX_ERROR 1

# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00
# define BLUE_PIXEL 0xFFFFFF
# define MAX_ITERATION 50

# define ABS(n) ((n) < 0 ? -(n) : (n))

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	double	mouse_im;
	double	mouse_re;
	double	position_mouse_im;
	double	position_mouse_re;
	double	position_im;
	double	position_re;
	double	position_zoom;
	int		color;
	int		iteration;
	int		fractal_type;
	int		change_color;
	int		change_center_color;
	int		rgb;
	double	julia_x_iter;
	double	julia_y_iter;
	double	julia_x;
	double	julia_y;
	double	mandelbrot_x;
	double	mandelbrot_y;
	double	man_c_re;
	double	man_c_im;
	double	burn_c_re;
	double	burn_c_im;
	double	burn_x;
	double	burn_y;
	double	c_re_julia;
	double	c_im_julia;
	double	zoom;
}			t_data;
 
int			ft_zoom(int button, int x, int y, t_data *data);
void		img_pix_put(t_img *img, int x, int y, int color);
int			handle_keypress(int keysym, t_data *data);
int			handle_cross(t_data *data);
int			julia(void);
int			mandelbrot(void);
int			render_mandelbrot(t_data *data);
int			init_mandelbrot(t_data *data);
int			render_julia(t_data *data);
void		graph_julia(t_img *img, t_data *data);
int			burningship(void);


#endif