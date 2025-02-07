/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lospacce <lospacce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:49:22 by lospacce          #+#    #+#             */
/*   Updated: 2024/11/20 15:56:35 by lospacce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int					ft_printf(const char *str, ...);
int					ft_signs(va_list args, char sign);
int					print_pustr(char *str);
void				ft_putnbr(int nb);
int					ft_putchar(char c);
size_t				ft_strlen(char *str);
char				*ft_strdup(const char *s);
char				*ft_itoa(int n);
int					unsinb(unsigned int nb);
char				*unsi_ft_itoa(unsigned int n);
void				ft_putnbr_base(unsigned int nb, char *base, int *size);
int					write_base(int nb, char *base);
int					print_percent(void);
int					printp(unsigned long long int ptr);
void				ft_putnbr_base_long(unsigned long long int nb, char *base,
						int *size);

#endif