#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int		ft_printchar_fd(char c, str_spec *format)
{
	ft_putchar_fd(c, 1);
	format->printed++;
	return (format->printed);
}

int		ft_printstr_fd(char *str, str_spec *format)
{
	write(1, &str[0], ft_strlen(str));
	format->printed++;
	return(format->printed);
}

int		ft_printd_fd(int n, str_spec *format)
{
	ft_putnbr_fd(n, 1);
	format->printed++;
	return(format->printed);
}

