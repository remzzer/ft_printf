#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

char	*ft_strrev(char *str)
{
	int		i;
	int		len = 0; 
	char	c;
	if (!str)
		return NULL;
	while (str[len] != '\0')
	{
		len++;
	}
	len = len - 1;
	i = 0;
	while (i <= (len / 2))
	{
		c = str[i];
		str[i] = str[len - i];
		str[len - i] = c;
		i++;
	}
	return (str);
}

char	*ft_itoa(int i, char *strout, int base)
{
	char	*str = strout;
	int		digit = 0;
	int		sign = 0;

	if (i < 0)
	{
		sign = 1;
		i = i * -1;
	}
	while(i)
	{
		digit = i % base; // ???
		*str = (digit > 9) ? ('A' + digit - 10) : '0' + digit;
		i = i / base;
		str ++;
	}
	if (sign)
	{
		*str++ = '-';
	}
	*str = '\0';
	ft_strrev(strout);
	return (strout);
}

int		print(char *str, ...)
{
	va_list	vl;
	int		i = 0;
	int		j = 0;
	char	buff[100] = {0};
	char	tmp[20];
	char	*str_arg;

	va_start(vl, str);
	while (str && str[i])
	{
		if(str[i] == '%')
		{
			i++;
			switch (str[i])
			{
				case 'c':
				{
					buff[j] = (char)va_arg(vl, int);
					j++;
					break;
				}
				case 'd':
				{
					ft_itoa(va_arg(vl, int), tmp, 10); // base decimal
					strcpy(&buff[j], tmp);
					j += strlen(tmp);
					break;
				}
				case 'x':
				{
					ft_itoa(va_arg(vl, int), tmp, 16); //base hexadecim
					strcpy(&buff[j], tmp);
					j += strlen(tmp);
					break;
				}
				case 'o':
				{
					ft_itoa(va_arg(vl, int), tmp, 8);
					strcpy(&buff[j], tmp);
					j += strlen(tmp);
					break;
				}
				case 's':
				{
					str_arg = va_arg(vl, char *);
					strcpy(&buff[j], str_arg);
					j += strlen(str_arg);
					break;
				}
			}
		}
		else
		{
			buff[j] = str[i];
			j++;
		}
		i++;
	}
	fwrite(buff, j, 1, stdout); 
	//j = size total(bytes of each elements
	//nmemb (1) = number of elements
	//pointers == output (ici sortie standard)
	va_end(vl);
	return (j);
}

int		main(void)
{
	char	res[10] = "bruh";
	char	*ptr = &res[0];
	char	strout[10] = "";
	int		ret;
	printf("Res ==> %s\n", ft_strrev(ptr));
	printf("itoa==> %s\n", ft_itoa(12, strout, 16));
	ret = print("Char: %c\n Deci:%d\n Hex:%x\n Octal: %o\n Str: %s\n", 'A', 10, 100, 1000,"Hello Bitches");
	print("rest: %d\n",  ret);
	printf("test_de_fou");
	return(0);
}
