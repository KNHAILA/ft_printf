/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knhaila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 10:33:59 by knhaila           #+#    #+#             */
/*   Updated: 2020/01/27 10:34:04 by knhaila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	d_case(const char **s, t_param *a, va_list param, int *count)
{
	int	nbr;

	nbr = va_arg(param, int);
	if ((*(*s - 1) == '.' && nbr == 0) || (a->precesion == 0 && nbr == 0))
		printf_nothing(a, count);
	else if (*(*s - 1) == '.' && a->flag == '0')
		printf_space_number(a, count, nbr);
	else
		printf_d(a, count, nbr);
}

void	u_case(const char **s, t_param *a, va_list param, int *count)
{
	unsigned int	nbr;

	nbr = va_arg(param, unsigned int);
	if ((*(*s - 1) == '.' && nbr == 0) || (a->precesion == 0 && nbr == 0))
		printf_nothing(a, count);
	else if (*(*s - 1) == '.' && a->flag == '0')
		printf_space_number_u(a, count, nbr);
	else
		printf_u(a, count, nbr);
}

void	s_case(const char **s, t_param *a, va_list param, int *count)
{
	if (*(*s - 1) == '.' && a->flag != '0')
		printf_nothing(a, count);
	else if (*(*s - 1) == '.' && a->flag == '0')
		printf_nothing_zero(a, count);
	else
		printf_s(a, param, count);
}

void	norminette6(int *count, int *i, char c)
{
	write(1, &c, 1);
	*count = *count + 1;
	while (*i > 0)
	{
		write(1, " ", 1);
		*i = *i - 1;
		*count = *count + 1;
	}
}

void	c_case(t_param *a, va_list param, int *count)
{
	char	c;
	int		i;

	c = (char)va_arg(param, void *);
	i = a->with - 1;
	if (a->flag == '-')
		norminette6(count, &i, c);
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
