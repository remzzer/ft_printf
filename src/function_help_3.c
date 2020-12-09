/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_help_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrolland <rrolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 21:18:35 by rrolland          #+#    #+#             */
/*   Updated: 2020/12/06 21:18:36 by rrolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int		ft_printchar_fd(char c, t_str_spec *format)
{
	ft_putchar_fd(c, 1);
	format->printed++;
	return (format->printed);
}

int		ft_printx_pre(char *str, t_str_spec *format, int length)
{
	if (format->zero != 0)
		ft_printwidth_fd('0', format, length);
	if (format->precision == 0)
	{
		if (*str == '0')
			ft_printwidth_fd(' ', format, 0);
		else
			ft_printstr_fd(str, format);
	}
	else
	{
		ft_printpre_fd('0', format, length);
		ft_printstr_fd(str, format);
	}
	return (format->printed);
}

int		ft_printwidth_x(char *str, t_str_spec *format, int length)
{
	int		tmp_prec;

	tmp_prec = format->precision;
	if (format->left_align == 0)
	{
		if (format->zero != 0)
			ft_printx_pre(str, format, length);
		if (format->width > format->precision && format->precision >= length)
			ft_printwidth_fd(' ', format, tmp_prec);
		else
			ft_printwidth_fd(' ', format, length);
		if (format->zero == 0)
			ft_printx_pre(str, format, length);
	}
	else
	{
		ft_printx_pre(str, format, length);
		if (format->width > format->precision && tmp_prec >= length)
			ft_printwidth_fd(' ', format, tmp_prec);
		else
			ft_printwidth_fd(' ', format, length);
	}
	return (format->printed);
}
