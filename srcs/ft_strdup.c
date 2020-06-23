/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knhaila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 12:27:28 by knhaila           #+#    #+#             */
/*   Updated: 2020/01/20 12:27:30 by knhaila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *src)
{
	int		l;
	int		i;
	char	*src1;

	i = 0;
	l = 0;
	while (src[l] != '\0')
		l++;
	if (!(src1 = malloc(l + 1)))
		return (NULL);
	while (i < l)
	{
		src1[i] = src[i];
		i++;
	}
	src1[i] = '\0';
	return (src1);
}
