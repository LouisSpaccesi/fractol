/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lospacce < lospacce@student.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 23:45:06 by lospacce          #+#    #+#             */
/*   Updated: 2025/02/07 12:49:03 by lospacce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atof(char *nptr)
{
	int		i;
	double	number;
	int		sign;

	sign = 1;
	i = 0;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	number = ft_atoi(nptr + i);
	i = 0;
	while (nptr[i] && nptr[i] != '.')
		i++;
	if (!nptr[i])
		return (sign * (double)number);
	i = ft_strlen(nptr) - i - 1;
	return (sign * (number / pow(10, i)));
}

long long	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	double	result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i])
	{
		if (!((nptr[i] >= '0' && nptr[i] <= '9') || nptr[i] == '.'))
			return (0);
		i++;
	}
	i = 0;
	while ((nptr[i] >= '0' && nptr[i] <= '9') || nptr[i] == '.')
	{
		if (nptr[i] != '.')
			result = (result * 10) + (nptr[i] - 48);
		i++;
	}
	return (result * sign);
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
		return ;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}

void	destroy_window(t_data *data)
{
	if (data->img.mlx_img != NULL)
	{
		mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
		data->img.mlx_img = NULL;
	}
	if (data->win_ptr != NULL)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
}

int	color_ticks(t_data *data)
{
	return ((ticksrandom(data, 0, 255, 23) << 16) | (ticksrandom(data, 0, 255,
				314) << 8) | ticksrandom(data, 0, 255, 756));
}
