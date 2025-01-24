/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lospacce < lospacce@student.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:55:00 by lospacce          #+#    #+#             */
/*   Updated: 2025/01/21 00:15:01 by lospacce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    t_data data;
    (void)argc;

    data.fractal_type = atoi(argv[1]);
    // int arg;
    // arg = atoi(argv[1]);

    if(data.fractal_type == 1)
        mandelbrot();
    if(data.fractal_type == 2)
        julia();
    printf("%d", data.fractal_type);
    return (0);
}

