/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lospacce < lospacce@student.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:35:58 by lospacce          #+#    #+#             */
/*   Updated: 2024/11/14 13:14:08 by lospacce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned int nb, char *base, int *size)
{
	if (nb >= ft_strlen(base))
		ft_putnbr_base(nb / ft_strlen(base), base, size);
	*size += write(1, &base[nb % ft_strlen(base)], 1);
}

void	ft_putnbr_base_long(unsigned long long int nb, char *base, int *size)
{
	if (nb >= ft_strlen(base))
		ft_putnbr_base_long(nb / ft_strlen(base), base, size);
	*size += write(1, &base[nb % ft_strlen(base)], 1);
}

int	write_base(int nb, char *base)
{
	int	size;

	size = 0;
	ft_putnbr_base(nb, base, &size);
	return (size);
}

int	print_percent(void)
{
	write(1, "%", 1);
	return (1);
}

int	printp(unsigned long long int ptr)
{
	int	size;

	size = 0;
	if (ptr)
	{
		size += write(1, "0x", 2);
		ft_putnbr_base_long(ptr, "0123456789abcdef", &size);
		return (size);
	}
	return (write(1, "(nil)", 5));
}
