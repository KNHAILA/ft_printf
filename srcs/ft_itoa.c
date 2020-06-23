/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knhaila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 12:25:08 by knhaila           #+#    #+#             */
/*   Updated: 2020/01/20 12:25:14 by knhaila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	size_t	divi(long n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char			*tab;
	size_t			siz;
	long long int	nb;
	int				x;

	x = 0;
	nb = n;
	siz = divi(nb);
	if (nb < 0)
		x++;
	if (!(tab = malloc(sizeof(char) * (siz + x + 1))))
		return (NULL);
	tab[siz + x] = '\0';
	if (nb < 0)
	{
		nb = -nb;
		tab[0] = '-';
	}
	while (siz)
	{
		tab[siz + x - 1] = '0' + (nb % 10);
		nb = nb / 10;
		siz--;
	}
	return (tab);
}

char			*ft_itoa_u(unsigned int n)
{
	char			*tab;
	size_t			siz;
	long long int	nb;

	nb = n;
	siz = divi(nb);
	if (!(tab = malloc(sizeof(char) * (siz + 1))))
		return (NULL);
	tab[siz] = '\0';
	while (siz)
	{
		tab[siz - 1] = '0' + (nb % 10);
		nb = nb / 10;
		siz--;
	}
	return (tab);
}
