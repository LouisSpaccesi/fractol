/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsi_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lospacce < lospacce@student.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:13:34 by lospacce          #+#    #+#             */
/*   Updated: 2024/11/14 13:36:04 by lospacce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	unsi_nb_len(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

static void	unsi_convertstr(unsigned int n, char *tab, unsigned int i)
{
	char	c;

	while (i--)
	{
		c = (n % 10 + '0');
		tab[i] = c;
		n /= 10;
	}
}

char	*unsi_ft_itoa(unsigned int n)
{
	char	*tab;
	int		i;

	if (n == 0)
		return (ft_strdup("0"));
	tab = malloc(unsi_nb_len(n) + 1);
	i = unsi_nb_len(n);
	if (!tab)
		return (NULL);
	tab[i] = '\0';
	unsi_convertstr(n, tab, i);
	return (tab);
}
