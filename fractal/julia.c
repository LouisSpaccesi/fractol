/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lospacce < lospacce@student.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:02:33 by lospacce          #+#    #+#             */
/*   Updated: 2025/01/28 15:46:54 by lospacce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	ft_fractol_julia(double z_re, double z_im, t_data *data, t_julia *julia)
{
	double	z_re2;
	double	z_im2;
	int		iter;

	iter = 0;
	while (z_re * z_re + z_im * z_im <= 4 && iter < data->iteration)
	{
		z_re2 = z_re * z_re - z_im * z_im + julia->julia_x_iter;
		z_im2 = 2 * z_re * z_im + julia->julia_y_iter;
		z_re = z_re2;
		z_im = z_im2;
		iter++;
	}
	return (iter);
}

void	graph_julia(t_img *img, t_data *data, t_julia *julia)
{
	int	iter;

	julia->julia_y = 0;
	while (julia->julia_y < WINDOW_HEIGHT)
	{
		julia->julia_x = 0;
		while (julia->julia_x < WINDOW_WIDTH)
		{
			julia->c_re_julia = (julia->julia_x - WINDOW_WIDTH / 2.0) * 4.0
				/ WINDOW_WIDTH / data->zoom + data->mouse_re;
			julia->c_im_julia = (julia->julia_y - WINDOW_HEIGHT / 2.0) * 4.0
				/ WINDOW_HEIGHT / data->zoom + data->mouse_im;
			iter = ft_fractol_julia(julia->c_re_julia, julia->c_im_julia, data,
					julia);
			data->color = 0x000000;
			if (iter < data->iteration)
				data->color = data->rgb + (iter * 1000 / data->iteration)
					* data->change_color;
			else
				data->color = data->change_center_color;
			img_pix_put(img, julia->julia_x, julia->julia_y, data->color);
			julia->julia_x++;
		}
		julia->julia_y++;
	}
}
