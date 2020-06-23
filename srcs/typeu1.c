/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeu1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knhaila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 10:34:34 by knhaila           #+#    #+#             */
/*   Updated: 2020/01/27 10:34:40 by knhaila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_u_prec(t_param *a, char *str, int *count)
{
	int i;

	i = a->precesion - ft_strlen(str);
	while (i > 0)
	{
		write(1, "0", 1);
		*count = *count + 1;
		i--;
	}
	write(1, str, ft_strlen(str));
	*count = *count + ft_strlen(str);
}

void	printf_u_with_prec(t_param *a, char *str, int *count)
{
	int i;

	i = a->with - a->precesion;
	if (a->flag == '-')
	{
		printf_d_prec(a, str, count);
		while (i > 0)
		{
			*count = *count + 1;
			write(1, " ", 1);
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
		printf_d_prec(a, str, count);
	}
}

void	printf_u(t_param *a, int *count, unsigned int nbr)
{
	char	*str;
	int		lenght;

	str = ft_itoa_u(nbr);
	lenght = (int)ft_strlen(str);
	if (lenght >= a->with && lenght >= a->precesion)
	{
		write(1, str, ft_strlen(str));
		*count = *count + ft_strlen(str);
	}
	else
	{
		if (lenght >= a->with)
			printf_d_prec(a, str, count);
		else
		{
			if (lenght >= a->precesion)
				printf_d_with(a, str, count);
			else
				printf_d_with_prec(a, str, count);
		}
	}
	free(str);
}
