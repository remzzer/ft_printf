#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int		ft_printchar_fd(char c, str_spec *format)
{
	ft_putchar_fd(c, 1);
	format->printed++;
	return (format->printed);
}

int		ft_printspace_fd(char c,  str_spec *format, int len)
{
	int		size;

	size = 0;

	(format->precision > format->width) ?
	(size = format->precision - format->width) :
	(size = format->width - format->precision);

	if (format->precision != -1 && len >= format->width)
	{
		while ((format->width - format->precision) > 0)
		{
			ft_putchar_fd(c, 1);
			format->width--;
			format->printed++;
		}
	}
	else if (format->precision != -1 && len < format->width)
	{
		if (len == 0)
		{
			while (format->width > len)
			{
				ft_putchar_fd(c, 1);
				format->printed++;
				format->width--;
			}
			return (0);
		}
		while (size > 0)
		{
				ft_putchar_fd(c, 1);
				size--;
				format->printed++;
		}
		{
			while (format->precision  > len)
			{
				ft_putchar_fd(c, 1);
				format->precision--;
				format->printed++;
			}
		}
	}
	else
	{
		while (format->width > len)
		{
			ft_putchar_fd(c, 1);
			format->printed++;
			format->width--;
		}
	}
	return (format->printed);
}

int		ft_printstr_fd(char *str, str_spec *format)
{
	write(1, &str[0], ft_strlen(str));
	format->printed += ft_strlen(str);
	return (format->printed);
}

int		ft_printstr_pre(char *str, str_spec *format)
{
	int		len;
	int		i;
	int		prec;

	len = ft_strlen(str);
	prec = format->precision;
	i = 0;
	if (format->precision < len && format->precision != -1)
	{
		while (prec > 0)
		{
			ft_putchar_fd(str[i], 1);
			i++;
			prec--;
			format->printed++;
		}
	}
	else
		ft_printstr_fd(str, format);
	return (format->printed);
}

int		ft_printstr_width(char *str, str_spec *format)
{
	int		len;

	len = ft_strlen(str);
	if (format->left_align == 0)
	{
		ft_printspace_fd(' ', format, len);
		ft_printstr_pre(str, format);
	}
	else if (format->left_align != 0)
	{
		ft_printstr_pre(str, format);
		ft_printspace_fd(' ', format, len);
	}
	else
		ft_printstr_fd(str, format);
	return (format->printed);
}

int		ft_printd_fd(int n, str_spec *format)
{
	ft_putnbr_fd(n, 1);
	format->printed++;
	return(format->printed);
}

