#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef struct	data_store
{
int		width;
int		precision;
int		no_prec;
int		left_align;
int		zero;
int		printed;
int		index;
int		type_flags;

}				str_spec;

//ft_printf.c
int		ft_printf(const char *str, ...);
int		find_id_flags(char c);
int		update_struct(const char *str, str_spec *format, va_list args);
void	ft_print_args(str_spec *format, va_list args);

//initialize.c
void	init_struct(str_spec *format);

//function_help.c
int		ft_printchar_fd(char c, str_spec *format);
int		ft_printspace_fd(char c, str_spec *format, int len);
int		ft_printwidth_fd(char c, str_spec *format, int len);
int		ft_printstr_fd(char *str, str_spec *format);
int		ft_printstr_pre(char *str, str_spec *format);
int		ft_printstr_width(char *str, str_spec *format);

//function_help_2.c
int		ft_printd_fd(long n, str_spec *format, int size);
int		size_num(long n);
int		ft_printnum_fd(long n, str_spec *format, int size);
int		ft_printnum_pre(long n, str_spec *format, int size);
int		ft_printpre_fd(char c, str_spec *format, int len);

//function_help_3.c
int		ft_printx_pre(char *str, str_spec *format, int len);
int		ft_printwidth_x(char *str, str_spec *format, int len);


//printed_flags.c
void	ft_print_c(va_list args, str_spec *format);
void	ft_print_s(va_list args, str_spec *format);
void	ft_print_d(va_list args, str_spec *format);
void	ft_print_x(va_list args, str_spec *format);
void	ft_print_p(va_list args, str_spec *format);

//conv.c
int		ft_n_len(long n, int len);
int		ft_atoi_n(const char *ptr, str_spec *format);
char	*ft_itoa_hex(unsigned int  n);
char	*ft_Capital(char *str);
#endif
