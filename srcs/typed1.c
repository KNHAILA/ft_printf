/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typed1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knhaila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 10:35:25 by knhaila           #+#    #+#             */
/*   Updated: 2020/01/27 10:35:29 by knhaila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	norminette7(char *str, int *count, t_param *a, int *i)
{
	if (*str == '-' && a->precesion < 0)
	{
		write(1, "-", 1);
		*count = *count + 1;
		str++;
	}
	while (*i != 0)
	{
		if (a->precesion >= 0)
			write(1, " ", 1);
		else
			write(1, "0", 1);
		*count = *count + 1;
		*i = *i - 1;
	}
	*count = *count + ft_strlen(str);
	write(1, str, ft_strlen(str));
}

void	norminette8(char *str, int *count, int *i)
{
	while (*i > 0)
	{
		*count = *count + 1;
		write(1, " ", 1);
		*i = *i - 1;
	}
	write(1, str, ft_strlen(str));
	*count = *count + ft_strlen(str);
}

void	printf_d_with(t_param *a, char *str, int *count)
{
	int i;

	i = a->with - ft_strlen(str);
	if (a->flag == '-')
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
	else if (a->flag == '0')
	{
		norminette7(str, count, a, &i);
	}
	else
	{
		norminette8(str, count, &i);
	}
}
