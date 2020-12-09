/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_help_02.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrolland <rrolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 21:18:31 by rrolland          #+#    #+#             */
/*   Updated: 2020/12/06 21:18:32 by rrolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int		size_num(long n)
{
	int		size;

	size = 0;
	if (n == 0 || n < 0)
		size += 1;
	if (n < 0)
		n *= -1;
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

int		ft_printd_fd(long n, t_str_spec *format, int size)
{
	ft_putnbr_fd(n, 1);
	format->printed += size;
	return (format->printed);
}

int		ft_printpre_fd(char c, t_str_spec *format, int size)
{
	int		prec;

	prec = format->precision;
	while (prec > size)
	{
		ft_putchar_fd(c, 1);
		prec--;
		format->printed++;
	}
	return (format->printed);
}

int		ft_printnum_fd(long n, t_str_spec *format, int size)
{
	if (format->left_align == 0)
	{
		if (format->width > format->precision && format->precision >= size)
		{
			(n < 0) ? (format->width -= 1) : (format->width);
			ft_printwidth_fd(' ', format, format->precision);
		}
		if (format->width > format->precision)
			ft_printwidth_fd(' ', format, size);
		if (format->zero == 0)
			ft_printnum_pre(n, format, size);
	}
	else
	{
		ft_printnum_pre(n, format, size);
		if (format->precision >= size)
		{
			(n < 0) ? (format->width -= 1) : (format->width);
			ft_printwidth_fd(' ', format, format->precision);
		}
		else
			ft_printwidth_fd(' ', format, size);
	}
	return (format->printed);
}

int		ft_printnum_pre(long n, t_str_spec *format, int size)
{
	int		tmp_size;
	long	tmp_num;

	tmp_size = size;
	tmp_num = n;
	if (tmp_num < 0 && format->zero == 0)
	{
		ft_putchar_fd('-', 1);
		tmp_num *= -1;
		size -= 1;
	}
	if (format->precision == 0)
	{
		if (n == 0)
			ft_printwidth_fd(' ', format, 0);
		else
			ft_printd_fd(tmp_num, format, tmp_size);
	}
	else
	{
		ft_printpre_fd('0', format, size);
		ft_printd_fd(tmp_num, format, tmp_size);
	}
	return (format->printed);
}
