/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeu.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knhaila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 12:28:23 by knhaila           #+#    #+#             */
/*   Updated: 2020/01/20 12:28:25 by knhaila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	norminette12(int i, t_param *a, int *count, char *str)
{
	while (i != 0)
	{
		if (a->precesion > 0)
			write(1, " ", 1);
		else
			write(1, "0", 1);
		*count = *count + 1;
		i--;
	}
	*count = *count + ft_strlen(str);
	write(1, str, ft_strlen(str));
}

void	norminette13(int i, int *count, char *str)
{
	write(1, str, ft_strlen(str));
	*count = *count + ft_strlen(str);
	while (i > 0)
	{
		*count = *count + 1;
		write(1, " ", 1);
		i--;
	}
}

void	printf_u_with(t_param *a, char *str, int *count)
{
	int i;

	i = a->with - ft_strlen(str);
	if (a->flag == '-')
	{
		norminette13(i, count, str);
	}
	else if (a->flag == '0')
		norminette12(i, a, count, str);
	else
	{
		while (i > 0)
		{
			*count = *count + 1;
			write(1, " ", 1);
			i--;
		}
		write(1, str, ft_strlen(str));
		*count = *count + ft_strlen(str);
	}
}

void	printf_space_number_u(t_param *a, int *count, unsigned int nbr)
{
	char	*str;

	str = ft_itoa_u(nbr);
	a->with = a->with - (int)ft_strlen(str);
	while (a->with > 0)
	{
		write(1, " ", 1);
		*count = *count + 1;
		a->with--;
	}
	write(1, str, ft_strlen(str));
	*count = *count + ft_strlen(str);
	free(str);
}
