#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	init_struct(t_str_spec *format)
{
	format->precision = -1;
	format->no_prec = 0;
	format->width = 0;
	format->left_align = 0;
	format->zero =  0;
	format->type_flags = 0;
}

char	*ft_capital(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	return (str);

}
