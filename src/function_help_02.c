#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int		size_num(long n)
{
	long	size;

	size = 0;
	if (n == 0)
		size++;
	if (n < 0)
		size++;
	while (n != 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}

int		ft_printd_fd(long n, str_spec *format)
{
	ft_putnbr_fd(n, 1);
	format->printed++;
	return (format->printed);
}

int		ft_printpre_fd(char c, str_spec *format, long size)
{
	while (format->precision > size)
	{
		ft_putchar_fd(c, 1);
		format->precision--;
		format->printed++;
	}
	return (format->printed++);
}

int		ft_printnum_fd(long n, str_spec *format)
{
	long	size;

	size = size_num(n);
	if (format->left_align == 0)
	{
		ft_printwidth_fd(' ', format, size);
		ft_printd_fd(n, format);
	}
	else
	{
		ft_printd_fd(n, format);
		ft_printwidth_fd(' ', format, size);
	}
	return (format->printed);
}

int		ft_printnum_pre(long n, str_spec *format)
{
	long	size;

	size = size_num(n);
	ft_printpre_fd('0', format, size);
	ft_printd_fd(n, format);
	return (format->printed);
}

