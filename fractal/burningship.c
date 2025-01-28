/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lospacce < lospacce@student.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:39:33 by lospacce          #+#    #+#             */
/*   Updated: 2025/01/28 15:47:11 by lospacce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	ft_fractol_burningship(double c_re, double c_im, t_data *data)
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
		z_im2 = ABS(2 * z_re * z_im) + c_im;
		z_re = z_re2;
		z_im = z_im2;
		iter++;
	}
	return (iter);
}

void	graph_burningship(t_img *img, t_data *data, t_burn *burn)
{
	int	iter;

	burn->burn_y = 0;
	while (burn->burn_y < WINDOW_HEIGHT)
	{
		burn->burn_x = 0;
		while (burn->burn_x < WINDOW_WIDTH)
		{
			burn->burn_c_re = (burn->burn_x - WINDOW_WIDTH / 2.0) * 4.0
				/ WINDOW_WIDTH / data->zoom + data->mouse_re;
			burn->burn_c_im = (burn->burn_y - WINDOW_HEIGHT / 2.0) * 4.0
				/ WINDOW_HEIGHT / data->zoom + data->mouse_im;
			iter = ft_fractol_burningship(burn->burn_c_re, burn->burn_c_im,
					data);
			data->color = data->change_center_color;
			if (iter < data->iteration)
				data->color = data->rgb + (iter * 1000 / data->iteration)
					* data->change_color;
			else
				data->color = data->change_center_color;
			img_pix_put(img, burn->burn_x, burn->burn_y, data->color);
			burn->burn_x++;
		}
		burn->burn_y++;
	}
}
