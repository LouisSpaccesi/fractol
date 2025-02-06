/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lospacce <lospacce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:55:00 by lospacce          #+#    #+#             */
/*   Updated: 2025/02/06 16:04:10 by lospacce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	set_instruction(void)
{
	ft_printf("\n");
	ft_printf("|| --------------------------------------------- ||\n|");
	ft_printf("| Switch 1, 2 or 3 for Mandelbrot, Julia        ||\n|");
	ft_printf("| or Burningship                                ||\n|");
	ft_printf("| ----------------------------------------------||\n|");
	ft_printf("| Direction with arrow                          ||\n|");
	ft_printf("| ----------------------------------------------||\n|");
	ft_printf("| Switch - or + to change nb of iteration       ||\n|");
	ft_printf("| ----------------------------------------------||\n|");
	ft_printf("| Use j,u,l,i or a to change Julia Fractal      ||\n|");
	ft_printf("| ----------------------------------------------||\n|");
	ft_printf("| Use c to change the color gradient            ||\n|");
	ft_printf("| ----------------------------------------------||\n|");
	ft_printf("| Use space to change the color                 ||\n|");
	ft_printf("| ----------------------------------------------||\n|");
	ft_printf("| Use Enter to put in the center                ||\n|");
	ft_printf("| ----------------------------------------------||\n|");
	ft_printf("| Use s for save position and g to return       ||\n|");
	ft_printf("| the position                                  ||\n|");
	ft_printf("| ----------------------------------------------||\n|");
	ft_printf("| Use m to change the color of the center       ||\n|");
	ft_printf("| ----------------------------------------------||");
	ft_printf("\n");
}

static int	put_image(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	if (data->fractal_type == 1)
		graph_mandelbrot(&data->img, data, &data->mand);
	if (data->fractal_type == 2)
		graph_julia(&data->img, data, &data->julia);
	if (data->fractal_type == 3)
		graph_burningship(&data->img, data, &data->burn);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0,
		0);
	data->ticks++;
	return (0);
}

int	render_fractal(t_data *data, int argc)
{
	if ((data->fractal_type == 1 || data->fractal_type == 2
			|| data->fractal_type == 3) && init_fractal(data, argc))
		return (1);
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH,
			WINDOW_HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	mlx_hook(data->win_ptr, ClientMessage, NoEventMask, &handle_cross, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_hook(data->win_ptr, ButtonPress, ButtonPressMask, &ft_zoom, data);
	if (data->fractal_type == 1 || data->fractal_type == 2
		|| data->fractal_type == 3)
		mlx_loop_hook(data->mlx_ptr, &put_image, data);
	mlx_loop(data->mlx_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	return (0);
}

static int	julia_parameter(int argc, char **argv, t_data *data)
{
	if (argc == 4)
	{
		data->julia.julia_x_iter = ft_atof(argv[2]);
		data->julia.julia_y_iter = ft_atof(argv[3]);
		if ((data->julia.julia_x_iter > 3 || data->julia.julia_x_iter < -3)
			|| (data->julia.julia_y_iter > 3 || data->julia.julia_y_iter < -3)
			|| ((ft_isalpha(argv[2])) || (ft_isalpha(argv[3]))))
		{
			ft_printf("\n\033[1;91m Invalid parameter ❌\n\033[0m\n");
			return (0);
		}
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		nb;

	if (argc < 2 || argc > 4)
	{
		return ((ft_printf("\n\033[1);91mChoose 1 for Mandelbrot, "
					"2 for Julia or 3 for burningship 💫\n\033[0m\n")));
	}
	if (argv[1][0] == '.')
		return (ft_printf("\n\033[1;91mChoose a valid number ❌\n\033[0m\n"));
	if ((argv[1][0] != '2' && argv[2]))
		return (ft_printf("\n\033[1;91mChoose a valid number ❌\n\033[0m\n"));
	nb = ft_atoi(argv[1]);
	if (nb != 1 && nb != 2 && nb != 3)
		return (ft_printf("\n\033[1;91mChoose a valid number ❌\n\033[0m\n"));
	data.fractal_type = ft_atoi(argv[1]);
	if (data.fractal_type == 2 && !(julia_parameter(argc, argv, &data)))
		return (1);
	set_instruction();
	if (render_fractal(&data, argc))
		return (1);
	return (0);
}
