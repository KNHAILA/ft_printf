/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knhaila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 12:28:03 by knhaila           #+#    #+#             */
/*   Updated: 2020/01/20 12:28:05 by knhaila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_p_nothing(t_param *a, int *count)
{
	int i;

	i = a->with - 2;
	if (a->flag == '-')
	{
		write(1, "0x", 2);
		*count = *count + 2;
		while (i > 0)
		{
			write(1, " ", 1);
			*count = *count + 1;
			i--;
		}
	}
	else
	{
		while (i > 0)
		{
			write(1, " ", 1);
			*count = *count + 1;
			i--;
		}
		write(1, "0x", 2);
		*count = *count + 2;
	}
}

void	norminette10(int j, int *count, int i)
{
	while (i > 0)
	{
		write(1, " ", 1);
		*count = *count + 1;
		i--;
	}
	write(1, "0x", 2);
	*count = *count + 2;
	while (j > 0)
	{
		write(1, "0", 1);
		*count = *count + 1;
		j--;
	}
}

void	norminette9(char *str, t_param *a, int *count, int i)
{
	int j;

	j = a->precesion - (int)ft_strlen(str);
	if (a->flag == '0' && a->precesion < 0)
	{
		write(1, "0x", 2);
		*count = *count + 2;
		while (i > 0)
		{
			write(1, "0", 1);
			*count = *count + 1;
			i--;
		}
	}
	else
		norminette10(j, count, i);
	write(1, str, ft_strlen(str));
	*count = *count + ft_strlen(str);
}

void	norminette11(char *str, int j, int *count)
{
	write(1, "0x", 2);
	*count = *count + 2;
	while (j > 0)
	{
		write(1, "0", 1);
		*count = *count + 1;
		j--;
	}
	write(1, str, ft_strlen(str));
	*count = *count + ft_strlen(str);
}

void	printf_p(t_param *a, int *count, unsigned long l)
{
	char	*str;
	int		i;
	int		j;

	str = ft_itoa_base(l, 16);
	j = a->precesion - (int)ft_strlen(str);
	if (j >= 0)
		i = a->with - 2 - (int)ft_strlen(str) - j;
	else
		i = a->with - 2 - (int)ft_strlen(str);
	if (a->flag == '-')
	{
		norminette11(str, j, count);
		while (i > 0)
		{
			write(1, " ", 1);
			*count = *count + 1;
			i--;
		}
	}
	else
		norminette9(str, a, count, i);
	free(str);
}
