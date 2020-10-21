#include "includes/ft_printf.h"

void	ft_putnbr(int n)
{
	int		nbr;
	char		c;

	nbr = n;
	if (nbr < 0)
	{
		nbr = -nbr;
		write(1, "-", 1);
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
	}
	c = nbr % 10 + 48;
	write(1, &c, 1);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int		find_index(char *tab, char c)
{
	int		i;
	i = 0;

	while (tab[i] != '\0')
	{
		if (tab[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void	print_str(va_list m_list)
{
	char	*str;

	str = va_arg(m_list, char *);
	write(1, str, ft_strlen(str));
}

void	print_char(va_list m_list)
{
	char	c;
	c = va_arg(m_list, int);
	write(1, &c, 1);
}

void	print_nbr(va_list m_list)
{
	int		num;
	num = va_arg(m_list, int);
	ft_putnbr(num);
}

int		ft_printf(const char *str, ...)
{
	va_list	m_list;
	char	tab_flags[4] = {'s', 'c', 'd'};
	void	(*buff_fnct[3])(va_list mlist) = {&print_str, &print_char, &print_nbr};
	int		i = 0;
	int		tmp_index = 0;

	va_start(m_list, str);
	while(str[i] != 0)
	{
		if (i != 0 && str[i - 1] == '%')
		{
			tmp_index = find_index(tab_flags, str[i]);
			if (tmp_index != -1)
			{
				(*buff_fnct[tmp_index])(m_list);
			}
		}
		else if (str[i] != '%')
			write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int		main(void)
{
	ft_printf("STRING:%s\nDECIMAL:%d\nCHAR:%c\n", "yolo", 11, 'c');
	printf("%5s\n", "remiiiii");
	printf("%*d\n", 5, -123);
	printf("%.4d\n", -2000);
	printf("%.*d\n", 5, -2);
	return(0);
}
