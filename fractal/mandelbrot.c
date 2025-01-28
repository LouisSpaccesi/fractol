/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lospacce < lospacce@student.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:11:02 by lospacce          #+#    #+#             */
/*   Updated: 2025/01/28 15:47:04 by lospacce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	ft_fractol_mandelbrot(double c_re, double c_im, t_data *data)
{
	double	z_re;
	double	z_im;
	double	z_re2;
	double	z_im2;
	int		iter;

	z_re = 0;
	z_im = 0;
	iter = 0;
	while (z_re * z_re + z_im * z_im <= 4 && iter < data->iteration)
	{
		z_re2 = z_re * z_re - z_im * z_im + c_re;
		z_im2 = 2 * z_re * z_im + c_im;
		z_re = z_re2;
		z_im = z_im2;
		iter++;
	}
	return (iter);
}

void	graph_mandelbrot(t_img *img, t_data *data, t_mand *mand)
{
	int	iter;

	mand->mandelbrot_y = 0;
	while (mand->mandelbrot_y < WINDOW_HEIGHT)
	{
		mand->mandelbrot_x = 0;
		while (mand->mandelbrot_x < WINDOW_WIDTH)
		{
			mand->man_c_re = (mand->mandelbrot_x - WINDOW_WIDTH / 2.0) * 4.0
				/ WINDOW_WIDTH / data->zoom + data->mouse_re;
			mand->man_c_im = (mand->mandelbrot_y - WINDOW_HEIGHT / 2.0) * 4.0
				/ WINDOW_HEIGHT / data->zoom + data->mouse_im;
			iter = ft_fractol_mandelbrot(mand->man_c_re, mand->man_c_im, data);
			data->color = data->change_center_color;
			if (iter < data->iteration)
				data->color = data->rgb + (iter * 1000 / data->iteration)
					* data->change_color;
			else
				data->color = data->change_center_color;
			img_pix_put(img, mand->mandelbrot_x, mand->mandelbrot_y,
				data->color);
			mand->mandelbrot_x++;
		}
		mand->mandelbrot_y++;
	}
}
