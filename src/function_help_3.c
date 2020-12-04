#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int		ft_printchar_fd(char c, str_spec *format)
{
	ft_putchar_fd(c, 1);
	format->printed++;
	return (format->printed);
}

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

int		ft_printwidth_x(char *str, str_spec *format, int length)
{
	int		tmp_prec;

	tmp_prec = format->precision;
	if (format->left_align == 0)
	{
		if (format->zero != 0)
			ft_printx_pre(str, format, length);
		if (format->width > format->precision && format->precision >= length)
			ft_printwidth_fd(' ', format, tmp_prec);
		else
			ft_printwidth_fd(' ', format, length);
		if (format->zero == 0)
			ft_printx_pre(str, format, length);
	}
	else
	{
		ft_printx_pre(str, format, length);
		if (format->width > format->precision && tmp_prec >= length)
			ft_printwidth_fd(' ', format, tmp_prec);
		else
		ft_printwidth_fd(' ', format, length);
	}
	return (format->printed);
}
