/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lospacce < lospacce@student.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 23:45:06 by lospacce          #+#    #+#             */
/*   Updated: 2025/01/19 12:58:52 by lospacce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	int		result;

	i = 0;
	sign = 1;
	result = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (result * 10) + (nptr[i] - 48);
		i++;
	}
	i++;
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

int return_fractal(t_data *data)
{
	if (data->fractal_type == 1)
	{
		render_mandelbrot(data);
		return (1);
	}
	if (data->fractal_type == 2)
	{
		render_julia(data);
		return (1);
	}
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
		exit(0);
	}
	if(keysym == XK_Up)
	{
		if(data->iteration < 300)
			data->iteration++;	
	}
	if(keysym == XK_Down)
	{
		if(data->iteration > 0)
			data->iteration--;
	}
	if (keysym == XK_Left)
		data->change_color++;
	if (keysym == XK_Right)
		data->change_color--;
	if(keysym == XK_space)
	{
		if (data->rgb == 0x0000FF)
            data->rgb = 0x00FF00;   
   		else if (data->rgb == 0x00FF00)  
            data->rgb = 0xFF0000;  
        else if (data->rgb == 0xFF0000) 
            data->rgb = 0xFFFF00;  
        else if (data->rgb == 0xFFFF00) 
            data->rgb = 0x0000FF;
	}
	return_fractal(data);
	return (0);
}

int	handle_cross(t_data *data)
{
	if (data->win_ptr != NULL)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
		exit(0);
	}
	return (0);
}


