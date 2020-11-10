#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int		ft_printchar_fd(char c, str_spec *format)
{
	ft_putchar_fd(c, 1);
	format->printed++;
	return (format->printed);
}

int		ft_printstr_pre(char *str, str_spec *format)
{
	int		len;
	int		i;

	len = ft_strlen(str);
	i = 0;
	if (format->precision < len && format->precision != -1)
	{
		while (format->precision > 0)
		{
			ft_putchar_fd(str[i], 1);
			i++;
			format->precision--;
			format->printed++;
		}
	}
	else
	{
		i = 0;
		while (len > i)
		{
			ft_putchar_fd(str[i], 1);
			format->printed++;
			i++;
		}
	}
	return (format->printed);
}

int		ft_printstr_width(char *str, str_spec *format)
{
	int		len;
	int		i;

	len =  ft_strlen(str);
	if (format->width > len && format->left_align == 0)
	{
		while (format->width > len)
		{
			ft_putchar_fd(' ', 1);
			format->width--;
			format->printed++;
		}
	}
	else if (format->width < 0)
	{
		format->width *= -1;
		format->left_align = 1;
		//printf("n_width%d\n", len);
	}
	i = 0;
	while (len > i)
	{
		ft_putchar_fd(str[i], 1);
		format->printed++;
		i++;
	}
	while (format->width > len)
	{
		ft_putchar_fd(' ', 1);
		format->width--;
		format->printed++;
	}
	return (format->printed);
}

int		ft_printd_fd(int n, str_spec *format)
{
	ft_putnbr_fd(n, 1);
	format->printed++;
	return(format->printed);
}

