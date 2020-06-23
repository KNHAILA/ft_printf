/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knhaila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 12:24:53 by knhaila           #+#    #+#             */
/*   Updated: 2020/01/27 10:32:02 by knhaila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		initialize(int *a, int *b)
{
	*a = 0;
	*b = 0;
}

static int		test(int negative, int nombre)
{
	if (negative)
		nombre = nombre * (-1);
	return (nombre);
}

int				ft_atoi(const char *str)
{
	int		nombre;
	int		negative;

	initialize(&nombre, &negative);
	while (*str != '\0')
	{
		if (*str == ' ' || *str == '\n'
			|| *str == '\t' || *str == '\v'
			|| *str == '\f' || *str == '\r')
			str++;
		else
			break ;
	}
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			negative = 1;
	}
	while (*str >= '0' && *str <= '9' && *str != '\0')
	{
		nombre = nombre * 10 + *str - 48;
		str++;
	}
	nombre = test(negative, nombre);
	return (nombre);
}
