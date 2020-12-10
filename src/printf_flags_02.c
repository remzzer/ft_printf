/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flags_02.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrolland <rrolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 21:18:45 by rrolland          #+#    #+#             */
/*   Updated: 2020/12/06 21:18:46 by rrolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	init_struct(t_str_spec *format)
{
	format->precision = -1;
	//format->no_prec = 0;
	format->width = 0;
	format->left_align = 0;
	format->zero = 0;
	format->p_zero = 0;
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

void	ft_print_sign(t_str_spec *format)
{
	if (format->left_align != 0 && format->width != 0)
	{
		ft_printchar_fd('%', format);
		if (format->precision == 0)
			ft_printwidth_fd(' ', format, 1);
		else
			ft_printspace_fd(' ', format, 1);
	}
	else
	{
		if (format->p_zero != 0)
			ft_printwidth_fd('0', format, 1);
		else if (format->precision == 0)
			ft_printwidth_fd(' ', format, 1);
		else
			ft_printspace_fd(' ', format, 1);
		ft_printchar_fd('%', format);
	}
}
