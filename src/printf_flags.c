#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_print_c(va_list list, str_spec *format)
{
	char	c;

	c = va_arg(list, int);
	ft_printchar_fd(c, format);
}

void	ft_print_s(va_list list, str_spec *format)
{
	char	*str;
	str = va_arg(list, char *);
	ft_printstr_fd(str, format);
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
	{
		ft_Capital(str);
	}
	ft_printstr_fd(str, format);
}

