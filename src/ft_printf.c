#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_print_args(str_spec *format, va_list args)
{
	if (format->type_flags == 0)
		ft_print_c(args, format);
	if (format->type_flags == 1)
		ft_print_s(args, format);
	if (format->type_flags == 2)
		ft_print_p(args, format);
	if (format->type_flags == 3 || format->type_flags == 4 
	|| format->type_flags == 5)
		ft_print_d(args, format);
	if (format->type_flags == 6 || format->type_flags == 7)
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

int		fix_struct(str_spec *format)
{
	if (format->precision < 0)
		format->precision = -1;
	if (format->zero == 1 && (format->precision != -1 
		|| format->left_align == 1))
		format->zero = 0;
	return (1);
}

int		update_struct(const char *str, str_spec *format, va_list list)
{
	int		test;
	test = 0;
	while (str[format->index])
	{
		if (str[format->index] == '0')
		{
			format->zero = 1;
			//printf("zero:%d", format->zero);
		}
		else if (str[format->index] == '-')
		{
			format->left_align = 1;
			//printf("left:%d", format->left_align);
		}
		else if (str[format->index] == '*' && str[format->index -1] != '.')
		{
			format->width = va_arg(list, int);
			//printf("width:%d", format->width);
		}
		else if (str[format->index] == '.')
		{
			test = format->index;
			(str[format->index + 1] == '*')
			? (format->precision = va_arg(list, int))
			: (format->precision = ft_atoi_n(&str[format->index + 1], format));
	//		printf("pre:%d", format->precision);
		//	printf("width:%d", format->width);
		}
		else if (ft_isdigit(str[format->index]) && str[format->index] != '0')
		{
			if (str[format->index] > test && test != 0)
			{
				(format->precision = ft_atoi_n(&str[format->index], format));
				//printf("pre:%d\n", format->precision);
			}
			else
			{
				(format->width = ft_atoi_n(&str[format->index], format));
				//printf("width:%d\n", format->width);
			}
		}
		else if ((format->type_flags = find_id_flags(str[format->index])) != -1)
		{
			return(fix_struct(format));
		}
		format->index++;
	}
	return (0);
}

int		ft_printf(const char *str, ...)
{
	str_spec	format;
	va_list		list;

	format.printed = 0;
	format.index = 0;
	va_start(list, str);
	while (str[format.index] != '\0')
	{
		init_struct(&format);
		if (str[format.index] == '%' && str[format.index] != '\0')
		{
			update_struct(str, &format, list);
			ft_print_args(&format, list);
		}
		else
			ft_printchar_fd(str[format.index], &format);
		format.index++;
	}
	return (format.printed);
}
