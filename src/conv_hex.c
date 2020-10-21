#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int		ft_n_len(long n)
{
	int		len;
	len = 1;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 9)
	{
		n = n / 16;
		len++;
	}
	return(len);
}

char	*ft_itoa_hex(long n)
{
	char	*str;
	long	num;
	int		len;
	int		counter;
	int		i;

	num = n;
	len = ft_n_len(num);

	if(!(str = (char *) malloc(sizeof(char) * len + 1)))
		return (NULL);
	counter = 0;
	while (counter < len)
	{
		str[counter] = '\0';
		counter++;
	}
	str[counter] = '\0';
	i = 0;
	if (num < 0)
	{
		num = -num;
		str[0] = '-';
		i++;
	}
	while (i < len - 1)
	{
		if (num < 10)
			str[i] = num % 16 + '0';
		else
		{
			str[i] = num % 16 - 10 + 'a';
		}
		num = num / 16;
		i++;
	}
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
