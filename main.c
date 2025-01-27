/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lospacce <lospacce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:55:00 by lospacce          #+#    #+#             */
/*   Updated: 2025/01/27 15:11:13 by lospacce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void	set_instruction(void)
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
	ft_printf("| Switch 1 or 2 for Mandelbrot or Julia         ||\n|");
	ft_printf("| ----------------------------------------------||\n|");
	ft_printf("| Use j,u,l,i or a to change Julia Fractal      ||\n|");
	ft_printf("| ----------------------------------------------||\n|");
	ft_printf("| Use c or v to change the color gradient       ||\n|");
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

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		return (ft_printf("\n\033[1;91mChoose 1 for Mandelbrot, 2 for Julia or 3 for burningship 💫\n\033[0m\n"));
	data.fractal_type = atoi(argv[1]);
	set_instruction();
	if (data.fractal_type == 1)
		mandelbrot();
	if (data.fractal_type == 2)
		julia();
	if (data.fractal_type == 3)
		burningship();
	return (0);
}
