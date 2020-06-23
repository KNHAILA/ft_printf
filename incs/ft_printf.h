/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knhaila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 12:27:16 by knhaila           #+#    #+#             */
/*   Updated: 2020/01/27 10:36:54 by knhaila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct	s_param
{
	char	flag;
	int		with;
	int		precesion;
	char	type;
}				t_param;

char			*ft_itoa(int n);
size_t			ft_strlen(const char *s);
int				ft_atoi(const char *str);
void			printf_d_prec(t_param *a, char *str, int *count);
void			printf_d_with(t_param *a, char *str, int *count);
void			printf_d_with_prec(t_param *a, char *str, int *count);
void			printf_d(t_param *a, int *count, int nbr);
void			printf_nothing(t_param *a, int *count);
void			set_struct(t_param *a);
int				ft_printf(const char *s, ...);
void			set_struct(t_param *a);
void			d_case(const char **s, t_param *a, va_list param, int *count);
void			s_case(const char **s, t_param *a, va_list param, int *count);
void			printf_s_without_flag(t_param *a, char *str, int *count);
void			printf_s_flag(t_param *a, char *str, int *count);
void			printf_s(t_param *a, va_list param, int *count);
char			*ft_strdup(const char *src);
void			printf_s_flag_zero(t_param *a, char *str, int *count);
char			*ft_itoa_base(unsigned long value, int base);
void			p_case(const char **s, t_param *a, va_list param, int *count);
void			printf_p_nothing(t_param *a, int *count);
void			printf_p(t_param *a, int *count, unsigned long l);
void			printf_nothing_zero(t_param *a, int *count);
void			c_case(t_param *a, va_list param, int *count);
void			printf_u(t_param *a, int *count, unsigned int nbr);
void			printf_u_with_prec(t_param *a, char *str, int *count);
void			printf_u_with(t_param *a, char *str, int *count);
void			printf_u_prec(t_param *a, char *str, int *count);
void			u_case(const char **s, t_param *a, va_list param, int *count);
void			printf_space_number(t_param *a, int *count, int nbr);
void			printf_space_number_u(t_param *a, int *count, unsigned int nbr);
char			*ft_itoa_u(unsigned int n);
void			x_x_case(const char **s, t_param *a, va_list param, int *count);
void			printf_space_number_x_x(t_param *a, int *cnt, unsigned int n);
void			printf_x_x(t_param *a, int *count, unsigned int nbr);
char			*ft_itoa_base_x(unsigned int value, int base);
void			printf_x_with_prec(t_param *a, char *str, int *count);
void			printf_x_with(t_param *a, char *str, int *count);
void			printf_x_prec(t_param *a, char *str, int *count);
char			*ft_itoa_base_x_x(unsigned int value, int base);
void			pourc_case(t_param *a, int *count);
void			norminette1(int *j, int *n, unsigned long *t, char **tab);
void			norminette2(unsigned long *t, int *i, char *tab, int *n);
void			norminette3(unsigned int *t, int *i, char *tab, int *n);
char			*norminette4(char *tab);
void			norminette5(int *count, int *i);
void			norminette6(int *count, int *i, char c);
void			norminette7(char *str, int *count, t_param *a, int *i);
void			norminette8(char *str, int *count, int *i);
void			norminette9(char *str, t_param *a, int *count, int i);
void			norminette10(int j, int *count, int i);
void			norminette11(char *str, int j, int *count);
void			norminette12(int i, t_param *a, int *count, char *str);
void			norminette13(int i, int *count, char *str);
void			norminette14(int i, t_param *a, int *count, char *str);
void			norminette15(int i, int *count, char *str);
int				ft_str(char *a);
int				much(unsigned long i, int base);
void			norminette1c(int *j, int *n, unsigned int *t, char **tab);
void			norminette2c(unsigned int *t, int *i, char *tab, int *n);
int				muchc(unsigned int i, int base);
void			pourc_case(t_param *a, int *count);
void			affichage(const char **s, t_param *a, va_list p, int *c);
void			traitement(const char **s, va_list param, int *count);

#endif
