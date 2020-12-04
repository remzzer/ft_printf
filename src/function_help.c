#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int		ft_printstr_fd(char *str, str_spec *format)
{
	write(1, &str[0], ft_strlen(str));
	format->printed += ft_strlen(str);
	return (format->printed);
}

int		ft_printwidth_fd(char c, str_spec *format, int len)
{
	while (format->width > len)
	{
		ft_putchar_fd(c, 1);
		format->width--;
		format->printed++;
		//printf("y");
	}
	return (format->printed);
}

int		ft_printspace_fd(char c,  str_spec *format, int len)
{
	int		size;

	size = 0;
	(len >= format->width) ?
	(size = format->width - format->precision) :
	(size = format->precision - format->width);
	if (format->precision != -1)
	{
		if (len == 0)
		{
			ft_printwidth_fd(c, format, len);
			return (0);
		}
		while (size > 0)
		{
				ft_putchar_fd(c, 1);
				size--;
				format->printed++;
		}
		if (format->precision < len && size != 0)
			len = format->precision;
	}
	ft_printwidth_fd(c, format, len);
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
			ft_putchar_fd(str[i++], 1);
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
	else
	{
		ft_printstr_pre(str, format);
		ft_printspace_fd(' ', format, len);
	}
	return (format->printed);
}
