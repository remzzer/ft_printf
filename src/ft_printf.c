#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_print_args(str_spec *format, va_list args)
{
	if (format->type_flags == 0)
		ft_print_c(args, format);
	if (format->type_flags == 1)
		ft_print_s(args, format);
	//if (format->type_flags == 2)
	//	ft_print_p(args);
	if (format->type_flags == 3)
		ft_print_d(args, format);
	//if (format->type_flags == 4)
	//	ft_print_i(args, format);
	//if (format->type_flags == 5)
	//	ft_print_u(args, format);
	if (format->type_flags == 6)
		ft_print_x(args, format);
	if (format->type_flags == 7)
		ft_print_x(args, format);
}

int		find_id_flags(char c)
{
	int		index;
	char	*flags;

	index = 0;
	flags = "cspdiuxX";
	while (flags[index] != '\0')
	{
		if (flags[index] == c)
			return(index);
		index++;
	}
	return (-1);
}

int		ft_printf(const char *str, ...)
{
	str_spec	format;
	va_list	list;
	int		type;

	format.printed = 0;
	format.index = 0;
	va_start(list, str);
	while (str[format.index] != '\0')
	{
		init_struct(&format);
		if (str[format.index] == '%' && str[format.index + 1] != '\0')
		{
			if (find_id_flags(str[format.index + 1]) > -1)
				type = set_flag_params(find_id_flags(str[format.index + 1]), &format);
				format.index++; //on n'imprime pas les flags
				ft_print_args(&format, list);
		}
		else
			ft_printchar_fd(str[format.index], &format);
		format.index++;
	}
	return (format.printed);
}
