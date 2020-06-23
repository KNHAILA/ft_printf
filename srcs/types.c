/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knhaila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 12:28:11 by knhaila           #+#    #+#             */
/*   Updated: 2020/01/20 12:28:15 by knhaila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_s_flag(t_param *a, char *str, int *count)
{
	int i;

	if ((int)ft_strlen(str) >= a->precesion && a->precesion >= 0)
	{
		write(1, str, a->precesion);
		*count = *count + a->precesion;
		i = a->with - a->precesion;
	}
	else
	{
		write(1, str, ft_strlen(str));
		*count = *count + ft_strlen(str);
		i = a->with - ft_strlen(str);
	}
	while (i > 0)
	{
		write(1, " ", 1);
		i--;
		*count = *count + 1;
	}
}

void	printf_s_without_flag(t_param *a, char *str, int *count)
{
	int i;

	if ((int)ft_strlen(str) >= a->precesion && a->precesion >= 0)
		i = a->with - a->precesion;
	else
		i = a->with - ft_strlen(str);
	while (i > 0)
	{
		write(1, " ", 1);
		i--;
		*count = *count + 1;
	}
	if ((int)ft_strlen(str) >= a->precesion && a->precesion >= 0)
	{
		write(1, str, a->precesion);
		*count = *count + a->precesion;
	}
	else
	{
		write(1, str, ft_strlen(str));
		*count = *count + ft_strlen(str);
	}
}

void	printf_s_flag_zero(t_param *a, char *str, int *count)
{
	int	i;

	if (a->precesion < 0 || a->with <= a->precesion
	|| (int)ft_strlen(str) <= a->precesion)
		i = a->with - ft_strlen(str);
	else
		i = a->with - a->precesion;
	while (i > 0)
	{
		write(1, "0", 1);
		i--;
		*count = *count + 1;
	}
	if ((int)ft_strlen(str) >= a->precesion && a->precesion >= 0)
	{
		write(1, str, a->precesion);
		*count = *count + a->precesion;
		i = a->with - a->precesion;
	}
	else
	{
		write(1, str, ft_strlen(str));
		*count = *count + ft_strlen(str);
		i = a->with - ft_strlen(str);
	}
}

void	printf_s(t_param *a, va_list param, int *count)
{
	char	*str;
	int		i;

	str = va_arg(param, char *);
	i = 0;
	if (str == NULL)
	{
		str = ft_strdup("(null)");
		i = 1;
	}
	if (a->flag == '-')
		printf_s_flag(a, str, count);
	else if (a->flag == '0')
		printf_s_flag_zero(a, str, count);
	else
		printf_s_without_flag(a, str, count);
	if (i == 1)
		free(str);
}

void	printf_nothing_zero(t_param *a, int *count)
{
	while (a->with > 0)
	{
		write(1, "0", 1);
		*count = *count + 1;
		a->with--;
	}
}
