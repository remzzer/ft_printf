/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrolland <rrolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 21:17:54 by rrolland          #+#    #+#             */
/*   Updated: 2020/12/06 21:18:10 by rrolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int		ft_n_len(long num, int len, int sign)
{
	if (num < 0)
	{
		sign = 1;
		num *= -1;
		len++;
	}
	while ((num /= 16) > 0)
		len++;
	return (len);
}

int		ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r'
		|| c == '\v' || c == '\f')
		return (1);
	return (0);
}

char	*ft_itoa_hex(unsigned int n)
{
	char		*str;
	int			sign;
	int			len;
	long long	num;

	sign = 0;
	len = 1;
	num = n;
	len = ft_n_len(num, len, sign);
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len--] = '\0';
	if (num == 0)
		str[len] = '0';
	while (num > 0)
	{
		(num % 16 <= 9) ? (str[len] = num % 16 + '0') :
		(str[len] = num % 16 - 10 + 'a');
		num /= 16;
		len--;
	}
	if (sign == 1)
		str[0] = '-';
	return (str);
}

char	*ft_itoa_hex_2(unsigned long n)
{
	char		*str;
	int			sign;
	int			len;
	long long	num;

	sign = 0;
	len = 1;
	num = n;
	len = ft_n_len(num, len, sign);
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len--] = '\0';
	if (num == 0)
		str[len] = '0';
	while (num > 0)
	{
		(num % 16 <= 9) ? (str[len] = num % 16 + '0') :
		(str[len] = num % 16 - 10 + 'a');
		num /= 16;
		len--;
	}
	if (sign == 1)
		str[0] = '-';
	return (str);
}

int		ft_atoi_n(const char *str, t_str_spec *format)
{
	int		neg;
	int		res;
	int		i;

	neg = 1;
	res = 0;
	i = 0;
	if (ft_isspace(str[i]) >= 1)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - 48);
		i++;
		format->index++;
	}
	format->index--;
	return (neg * res);
}
