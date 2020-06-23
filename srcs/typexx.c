/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typexx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knhaila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 10:34:51 by knhaila           #+#    #+#             */
/*   Updated: 2020/01/27 10:34:56 by knhaila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	norminette14(int i, t_param *a, int *count, char *str)
{
	if (*str == '-')
	{
		write(1, "-", 1);
		*count = *count + 1;
		str++;
	}
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

void	norminette15(int i, int *count, char *str)
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

void	printf_x_with(t_param *a, char *str, int *count)
{
	int i;

	i = a->with - ft_strlen(str);
	if (a->flag == '-')
		norminette15(i, count, str);
	else if (a->flag == '0')
		norminette14(i, a, count, str);
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
