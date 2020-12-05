#include "../includes/ft_printf.h"
#include "../libft/libft.h"
#include <ctype.h>

int		ft_n_len(long n, int len)
{
	while ((n /= 16) > 0)
		len++;
	return (len);
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
	if (num < 0)
	{
		len++;
		num *= -1;
		sign = 1;
	}
	len = ft_n_len(num, len);
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len--] = '\0';
	if (num == 0)
		str[len] = '0';
	while (num > 0)
	{
		if (num % 16 <= 9)
			str[len] = num % 16 + '0';
		else
			str[len] = num % 16 - 10 + 'a';
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
	if (num < 0)
	{
		len++;
		num *= -1;
		sign = 1;
	}
	len = ft_n_len(num, len);
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len--] = '\0';
	if (num == 0)
		str[len] = '0';
	while (num > 0)
	{
		if (num % 16 <= 9)
			str[len] = num % 16 + '0';
		else
			str[len] = num % 16 - 10 + 'a';
		num /= 16;
		len--;
	}
	if (sign == 1)
		str[0] = '-';
	return (str);
}

char	*ft_Capital(char *str)
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

int		ft_atoi_n(const char *str, str_spec *format)
{
	int		neg;
	int		res;
	int		i;

	neg = 1;
	res = 0;
	i = 0;
	/*
	if (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	*/
	if (isspace(str[i]) >= 1)
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
