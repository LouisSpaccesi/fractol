/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lospacce <lospacce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:55:00 by lospacce          #+#    #+#             */
/*   Updated: 2025/01/17 15:15:17 by lospacce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    int arg;
    
    arg = atoi(argv[1]);
    if(argc == 2)
    {
        if(arg == 1)
        {
            mandelbrot();
            return (0);
        }
        if(arg == 2)
        {
            julia();
            return (0);
        }
        else
            printf("Choose 1 for Mandelbrot or 2 for Julia");
    }
    return (0);
}

