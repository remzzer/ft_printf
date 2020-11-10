#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int		ft_printd_fd(int n, str_spec *format)
{
	ft_putnbr_fd(n, 1);
	format->printed++;
	return (format->printed);
}
