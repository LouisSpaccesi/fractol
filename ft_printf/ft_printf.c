/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lospacce <lospacce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:28:07 by lospacce          #+#    #+#             */
/*   Updated: 2024/11/20 15:58:27 by lospacce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_signs(va_list args, char sign)
{
	int		print;
	char	*str;

	print = 0;
	if (sign == 'c')
		print += ft_putchar(va_arg(args, int));
	if (sign == 's')
		print += print_pustr(va_arg(args, char *));
	if (sign == 'd' || sign == 'i')
	{
		str = ft_itoa(va_arg(args, int));
		print += print_pustr(str);
		free(str);
	}
	if (sign == 'u')
	{
		str = unsi_ft_itoa(va_arg(args, unsigned int));
		print += print_pustr(str);
		free(str);
	}
	if (sign == 'x')
		print += write_base(va_arg(args, int), "0123456789abcdef");
	if (sign == 'X')
		print += write_base(va_arg(args, int), "0123456789ABCDEF");
	return (print);
}

int	ft_others_signs(va_list args, char sign)
{
	if (sign == '%')
		return (print_percent());
	if (sign == 'p')
		return (printp((unsigned long long)va_arg(args, void *)));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		print;

	i = 0;
	print = 0;
	va_start(args, str);
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			i++;
			if (str[i] == 'p' || str[i] == '%')
				print += ft_others_signs(args, str[i]);
			else
				print += ft_signs(args, str[i]);
		}
		else
			print += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (print);
}
