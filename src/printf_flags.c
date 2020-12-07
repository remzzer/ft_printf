/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrolland <rrolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 21:18:58 by rrolland          #+#    #+#             */
/*   Updated: 2020/12/06 21:18:59 by rrolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_print_c(va_list list, t_str_spec *format)
{
	char	c;

	c = va_arg(list, int);
	if (format->left_align != 0 && format->width != 0)
	{
		ft_printchar_fd(c, format);
		ft_printspace_fd(' ', format, 1);
	}
	else
	{
		ft_printspace_fd(' ', format, 1);
		ft_printchar_fd(c, format);
	}
}

void	ft_print_s(va_list list, t_str_spec *format)
{
	char	*str;

	str = va_arg(list, char *);
	if (str == NULL)
	{
		str = "(null)";
		ft_printstr_width(str, format);
	}
	else if (format->precision != -1 && format->width == 0)
		ft_printstr_pre(str, format);
	else if (format->precision != -1 && format->width != 0)
		ft_printstr_width(str, format);
	else if (format->width != 0)
		ft_printstr_width(str, format);
	else
		ft_printstr_pre(str, format);
}

void	ft_print_d(va_list list, t_str_spec *format)
{
	long	n;
	long	size;

	(format->type_flags == 5) ? (n = (long)va_arg(list, unsigned int)) :
	(n = (long)va_arg(list, int));
	size = size_num(n);
	if (format->zero != 0)
	{
		if (n < 0)
		{
			ft_putchar_fd('-', 1);
			n *= -1;
		}
		ft_printwidth_fd('0', format, size);
		ft_printnum_pre(n, format, size);
	}
	if (format->precision != -1 && format->width == 0)
		ft_printnum_pre(n, format, size);
	else if (format->precision != -1 && format->width != 0)
		ft_printnum_fd(n, format, size);
	else
		ft_printnum_fd(n, format, size);
}

void	ft_print_x(va_list list, t_str_spec *format)
{
	char	*str;
	int		length;

	str = ft_itoa_hex(va_arg(list, unsigned int));
	length = ft_strlen(str);
	if (format->type_flags == 7)
		ft_capital(str);
	if (format->precision != -1 && format->width == 0)
		ft_printx_pre(str, format, length);
	else if (format->precision != -1 && format->width != 0)
		ft_printwidth_x(str, format, length);
	else
		ft_printwidth_x(str, format, length);
}

void	ft_print_p(va_list list, t_str_spec *format)
{
	unsigned long	value;
	char			*str_1;
	char			*str_2;
	int				length;

	value = va_arg(list, unsigned long);
	str_1 = ft_itoa_hex_2(value);
	str_2 = ft_strjoin("0x", str_1);
	length = ft_strlen(str_2);
	ft_printwidth_x(str_2, format, length);
	free(str_1);
	free(str_2);
}
