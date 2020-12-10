/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrolland <rrolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 21:15:28 by rrolland          #+#    #+#             */
/*   Updated: 2020/12/06 21:18:13 by rrolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"

# include <stdarg.h>
# include <stdio.h>

typedef struct	s_data_store{
	int		width;
	int		precision;
	int		left_align;
	int		zero;
	int		p_zero;
	int		printed;
	int		index;
	int		type_flags;
}				t_str_spec;

int				ft_printf(const char *str, ...);
int				find_id_flags(char c);
int				update_struct(const char *str, t_str_spec *format,
				va_list args);
int				fix_struct(t_str_spec *format);
void			ft_print_args(t_str_spec *format, va_list args);

void			init_struct(t_str_spec *format);
char			*ft_capital(char *str);
void			ft_print_sign(t_str_spec *format);

int				ft_printspace_fd(char c, t_str_spec *format, int len);
int				ft_printwidth_fd(char c, t_str_spec *format, int len);
int				ft_printstr_fd(char *str, t_str_spec *format);
int				ft_printstr_pre(char *str, t_str_spec *format);
int				ft_printstr_width(char *str, t_str_spec *format);

int				ft_printd_fd(long n, t_str_spec *format, int size);
int				size_num(long n);
int				ft_printnum_fd(long n, t_str_spec *format, int size);
int				ft_printnum_pre(long n, t_str_spec *format, int size);
int				ft_printpre_fd(char c, t_str_spec *format, int len);

int				ft_printchar_fd(char c, t_str_spec *format);
int				ft_printx_pre(char *str, t_str_spec *format, int len);
int				ft_printwidth_x(char *str, t_str_spec *format, int len);

void			ft_print_c(va_list args, t_str_spec *format);
void			ft_print_s(va_list args, t_str_spec *format);
void			ft_print_d(va_list args, t_str_spec *format);
void			ft_print_x(va_list args, t_str_spec *format);
void			ft_print_p(va_list args, t_str_spec *format);

int				ft_n_len(long n, int len, int sign);
int				ft_isspace(char c);
int				ft_atoi_n(const char *ptr, t_str_spec *format);
char			*ft_itoa_hex(unsigned int n);
char			*ft_itoa_hex_2(unsigned long n);

#endif
