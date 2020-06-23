/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knhaila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 12:26:58 by knhaila           #+#    #+#             */
/*   Updated: 2020/01/20 12:27:03 by knhaila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	affichage(const char **s, t_param *a, va_list param, int *count)
{
	while (**s != 'd' && **s != 's' && **s != 'p' && **s != 'c' && **s != 'i'
	&& **s != 'u' && **s != 'x' && **s != 'X' && **s != '%')
		*s = *s + 1;
	if (**s == 'd' || **s == 'i')
		d_case(s, a, param, count);
	if (**s == 's')
		s_case(s, a, param, count);
	if (**s == 'p')
		p_case(s, a, param, count);
	if (**s == 'c')
		c_case(a, param, count);
	if (**s == 'u')
		u_case(s, a, param, count);
	if (**s == 'x' || **s == 'X')
		x_x_case(s, a, param, count);
	if (**s == '%')
		pourc_case(a, count);
}

void	norminette16(const char **s, va_list param, t_param *a)
{
	while (**s == '-' || **s == '0')
	{
		if (**s == '0')
		{
			if (a->flag != '-')
				a->flag = '0';
		}
		else
			a->flag = '-';
		*s = *s + 1;
	}
	if (**s > '0' && **s <= '9')
		a->with = ft_atoi(*s);
	if (**s == '*')
	{
		a->with = (int)va_arg(param, int);
		if (a->with < 0)
		{
			a->flag = '-';
			a->with = -a->with;
		}
	}
}

void	traitement(const char **s, va_list param, int *count)
{
	t_param *a;

	a = malloc(sizeof(t_param));
	set_struct(a);
	norminette16(s, param, a);
	while (**s != '.' && **s != 'd' && **s != 's' && **s != 'p' && **s != 'c'
	&& **s != 'i' && **s != 'u' && **s != 'x' && **s != 'X' && **s != '%')
		*s = *s + 1;
	if (**s == '.')
	{
		*s = *s + 1;
		if (**s == '*')
			a->precesion = (int)va_arg(param, int);
		else
			a->precesion = ft_atoi(*s);
	}
	affichage(s, a, param, count);
	free(a);
}

int		ft_printf(const char *s, ...)
{
	va_list	param;
	int		count;

	va_start(param, s);
	count = 0;
	if (s == NULL)
		return (-1);
	while (*s != '\0')
	{
		if (*s == '%')
		{
			s++;
			traitement(&s, param, &count);
		}
		else
		{
			count++;
			write(1, s, 1);
		}
		s++;
	}
	va_end(param);
	return (count);
}
