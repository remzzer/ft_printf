#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_print_c(va_list list, str_spec *format)
{
	char	c;

	c = va_arg(list, int);
	if (format->left_align != 0 && format->width != 0)
	{
		ft_printchar_fd(c, format);
		while (format->width -1 > 0)
		{
			ft_putchar_fd(' ', 1);
			format->printed++;
			format->width--;
		}
	}
	else
	{
		while (format->width -1 > 0)
		{
			ft_putchar_fd(' ', 1);
			format->printed++;
			format->width--;
		}
		ft_printchar_fd(c, format);
	}
}

void	ft_print_s(va_list list, str_spec *format)
{
	char	*str;
	str = va_arg(list, char *);
	if (str == NULL)
	{
		str = "(null)";
		ft_printstr_pre(str, format);
	}
	else if (format->precision != - 1 && format->width == 0)
		ft_printstr_pre(str, format);
	else if (format->width != 0)
		ft_printstr_width(str, format);
	else
		ft_printstr_pre(str, format);
}

void	ft_print_d(va_list list, str_spec *format)
{
	int		n;
	n = va_arg(list, int);
	ft_printd_fd(n, format);
}

void	ft_print_x(va_list list, str_spec *format)
{
	char	*str;
	str = ft_itoa_hex(va_arg(list, unsigned int));
	if (format->type_flags == 7)
		ft_Capital(str);
	ft_putstr_fd(str, 1);
}

