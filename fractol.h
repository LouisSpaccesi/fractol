/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lospacce < lospacce@student.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:14:23 by lospacce          #+#    #+#             */
/*   Updated: 2025/01/28 23:57:48 by lospacce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "./ft_printf/./ft_printf.h"
# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# define BUTTONFRONT 4
# define BUTOONBACK 5

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
	void			*mlx_img;
	char			*addr;
	int				bpp;
	int				line_len;
	int				endian;
}					t_img;

typedef struct s_mand
{
	double			mandelbrot_x;
	double			mandelbrot_y;
	double			man_c_re;
	double			man_c_im;
}					t_mand;

typedef struct s_julia
{
	double			julia_x_iter;
	double			julia_y_iter;
	double			julia_x;
	double			julia_y;
	double			c_re_julia;
	double			c_im_julia;
}					t_julia;

typedef struct s_burn
{
	double			burn_c_re;
	double			burn_c_im;
	double			burn_x;
	double			burn_y;
}					t_burn;

typedef struct s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	unsigned long	ticks;
	t_img			img;
	t_mand			mand;
	t_julia			julia;
	t_burn			burn;
	double			mouse_im;
	double			mouse_re;
	double			position_mouse_im;
	double			position_mouse_re;
	double			position_zoom;
	int				color;
	int				iteration;
	int				fractal_type;
	int				change_color;
	int				change_center_color;
	int				rgb;
	double			zoom;
}					t_data;

// keypress
int					handle_keypress(int keysym, t_data *data);
int					handle_cross(t_data *data);
void				handle_arrow(int keysym, t_data *data);
void				handle_julia(int keysym, t_julia *julia);
int					ft_zoom(int button, int x, int y, t_data *data);
void				handle_direction(int keysym, t_data *data);
void				return_before_position(int keysym, t_data *data);

// color
void				img_pix_put(t_img *img, int x, int y, int color);
int					color_ticks(t_data *data);
int					ticksrandom(t_data *data, int min, int max, int iter);

// utils
long long			ft_atoi(const char *nptr);
double				ft_atof(char *nptr);
void				destroy_window(t_data *data);

// init
void				free_window(t_data *data);
int					init_fractal(t_data *data);

// fractal
int					render_fractal(t_data *data);
void				graph_burningship(t_img *img, t_data *data, t_burn *burn);
void				graph_julia(t_img *img, t_data *data, t_julia *julia);
void				graph_mandelbrot(t_img *img, t_data *data, t_mand *mand);

#endif