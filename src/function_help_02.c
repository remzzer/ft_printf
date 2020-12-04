#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int		size_num(long n)
{
	int		size;

	size = 0;
	if (n == 0 || n < 0 )
		size += 1;
	if (n < 0)
		n *= -1;
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

int		ft_printd_fd(long n, str_spec *format, int size)
{
	ft_putnbr_fd(n, 1);
	format->printed += size;
	return (format->printed);
}

int		ft_printpre_fd(char c, str_spec *format, int size)
{
	while (format->precision > size)
	{
		ft_putchar_fd(c, 1);
		format->precision--;
		format->printed++;
		//printf("i");
	}
	return (format->printed);
}

int		ft_printnum_fd(long n, str_spec *format, int size)
{
	int		tmp_pre;
	long	tmp_num;

	tmp_pre = format->precision;
	tmp_num = n;
	if (format->left_align == 0)
	{
		if (format->zero != 0)
			ft_printnum_pre(n, format, size);
		if (format->width > format->precision && format->precision >= size)
		{
			if (n < 0)
				format->width -= 1;
			ft_printwidth_fd(' ', format, tmp_pre);
		}
		if (format->width > format->precision)
			ft_printwidth_fd(' ', format, size);
		if (format->zero == 0)
			ft_printnum_pre(n, format, size);
	}
	else
	{
		ft_printnum_pre(n, format, size);
		if (format->width > format->precision && tmp_pre >= size)
		{
			if (tmp_num < 0)
				format->width -= 1;
			ft_printwidth_fd(' ', format, tmp_pre);
		}
		else
			ft_printwidth_fd(' ', format, size);
	}
	return (format->printed);
}

int		ft_printnum_pre(long n, str_spec *format, int size)
{
	int		tmp_size;

	tmp_size = size;
	if (n < 0 && format->zero == 0)
	{
		ft_putchar_fd('-', 1);
		n *= -1;
		tmp_size -= 1;
	}
	if (format->zero != 0)
	{
		if (n < 0)
		{
			ft_putchar_fd('-', 1);
			n *= -1;
		}
		ft_printwidth_fd('0', format, size); 
	}
	if (format->precision == 0)
		ft_printwidth_fd(' ', format, 0);
	else
	{
		ft_printpre_fd('0', format, tmp_size);
		ft_printd_fd(n, format, size);
	}
	return (format->printed);
}


