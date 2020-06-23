/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knhaila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 10:34:18 by knhaila           #+#    #+#             */
/*   Updated: 2020/01/27 10:34:22 by knhaila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_struct(t_param *a)
{
	a->flag = '1';
	a->with = -1;
	a->precesion = -1;
	a->type = 'd';
}

void	x_x_case(const char **s, t_param *a, va_list param, int *count)
{
	unsigned int	nbr;

	nbr = va_arg(param, unsigned int);
	a->type = **s;
	if ((*(*s - 1) == '.' && nbr == 0) || (a->precesion == 0 && nbr == 0))
		printf_nothing(a, count);
	else if (*(*s - 1) == '.' && a->flag == '0')
		printf_space_number_x_x(a, count, nbr);
	else
		printf_x_x(a, count, nbr);
}

void	norminette5(int *count, int *i)
{
	while (*i > 0)
	{
		write(1, " ", 1);
		*i = *i - 1;
		*count = *count + 1;
	}
}

void	pourc_case(t_param *a, int *count)
{
	char	c;
	int		i;

	c = '%';
	i = a->with - 1;
	if (a->flag == '-')
	{
		write(1, &c, 1);
		*count = *count + 1;
		norminette5(count, &i);
	}
	else
	{
		while (i > 0)
		{
			if (a->flag == '0')
				write(1, "0", 1);
			else
				write(1, " ", 1);
			i--;
			*count = *count + 1;
		}
		write(1, &c, 1);
		*count = *count + 1;
	}
}

void	p_case(const char **s, t_param *a, va_list param, int *count)
{
	unsigned long	l;

	l = va_arg(param, unsigned long);
	if ((*(*s - 1) == '.' && l == 0) || (a->precesion == 0 && l == 0))
		printf_p_nothing(a, count);
	else
		printf_p(a, count, l);
}
