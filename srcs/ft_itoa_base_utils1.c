/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_utils1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knhaila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 10:33:29 by knhaila           #+#    #+#             */
/*   Updated: 2020/01/27 10:33:34 by knhaila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	norminette2c(unsigned int *t, int *i, char *tab, int *n)
{
	while (*t != 0)
	{
		if (*t % 16 > 9)
			tab[*i] = 'a' + *t % 16 - 10;
		else
			tab[*i] = '0' + *t % 16;
		*i = *i + 1;
		*t = *t / 16;
	}
	tab[*i] = '\0';
	*n = ft_str(tab);
}

int		muchc(unsigned int i, int base)
{
	int j;

	j = 1;
	while (i / base != 0 && (base >= 2 && base <= 16))
	{
		j++;
		i = i / base;
	}
	return (j);
}
