#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int		ft_printx_pre(char *str, str_spec *format, int length)
{
	if (format->zero != 0)
		ft_printwidth_fd('0', format, length);
	if (format->precision == 0)
		ft_printwidth_fd(' ', format, 0);
	else
	{
		ft_printpre_fd('0', format, length);
		ft_printstr_fd(str, format);
	}
	return (format->printed);
}
