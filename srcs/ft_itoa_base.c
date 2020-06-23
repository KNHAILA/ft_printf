/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knhaila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 12:25:29 by knhaila           #+#    #+#             */
/*   Updated: 2020/01/20 12:25:32 by knhaila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	norminette3(unsigned int *t, int *i, char *tab, int *n)
{
	while (*t != 0)
	{
		if (*t % 16 > 9)
			tab[*i] = 'A' + *t % 16 - 10;
		else
			tab[*i] = '0' + *t % 16;
		*i = *i + 1;
		*t = *t / 16;
	}
	tab[*i] = '\0';
	*n = ft_str(tab);
}

char	*norminette4(char *tab)
{
	tab[0] = '0';
	tab[1] = '\0';
	return (tab);
}

char	*ft_itoa_base(unsigned long t, int base)
{
	char			*tab;
	int				i;
	int				j;
	int				n;
	char			swap;

	i = 0;
	tab = 0;
	norminette1(&j, &n, &t, &tab);
	if (base <= 16 && base >= 2)
	{
		if (t == 0)
			return (norminette4(tab));
		norminette2(&t, &i, tab, &n);
		while (j < n / 2)
		{
			swap = tab[j];
			tab[j] = tab[n - j - 1];
			tab[n - j - 1] = swap;
			j++;
		}
		return (tab);
	}
	return (0);
}

char	*ft_itoa_base_x(unsigned int t, int base)
{
	char			*tab;
	int				i;
	int				j;
	int				n;
	char			swap;

	i = 0;
	tab = 0;
	norminette1c(&j, &n, &t, &tab);
	if (base <= 16 && base >= 2)
	{
		if (t == 0)
			return (norminette4(tab));
		norminette2c(&t, &i, tab, &n);
		while (j < n / 2)
		{
			swap = tab[j];
			tab[j] = tab[n - j - 1];
			tab[n - j - 1] = swap;
			j++;
		}
		return (tab);
	}
	return (0);
}

char	*ft_itoa_base_x_x(unsigned int t, int base)
{
	char			*tab;
	int				i;
	int				j;
	int				n;
	char			swap;

	tab = 0;
	i = 0;
	norminette1c(&j, &n, &t, &tab);
	if (base <= 16 && base >= 2)
	{
		if (t == 0)
			return (norminette4(tab));
		norminette3(&t, &i, tab, &n);
		while (j < n / 2)
		{
			swap = tab[j];
			tab[j] = tab[n - j - 1];
			tab[n - j - 1] = swap;
			j++;
		}
		return (tab);
	}
	return (0);
}
