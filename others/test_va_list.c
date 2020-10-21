#include <stdarg.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

//=================================VA_LIST====================================
/*
int		add(int counter, ...)
{
	int sum = 0;
	va_list paramns_infos;
	//Initialisation va_list structure
	va_start(paramns_infos, counter);

	//For all unnamed integer, do an addition 
	while (counter > 0)
	{
		sum += (int)va_arg(paramns_infos, int); //cast sur int car sum = int
		counter--;
	}
	// Release va_list resources
	va_end(paramns_infos);
	return sum;
}

int		main(void)
{
	int		res;
	res = add(2, 3, 11);
	printf("add == %d\n", res);
	//res = add(10, 5, 1);
	//printf("add == %d\n", res);
	return (0);
}
===============================VA_START=======================================
int		find_max_int(int first, ...)
{
	int		max = first;
	va_list params_infos;
	//Initialisation va_list structure
	va_start(params_infos, first);

	while (true)
	{
		int		current = (int) va_arg(params_infos, int);
		if (current == -1)
			break;
		if (current > max)
			max = current;
	}
	// Release va_list resources
	va_end(params_infos);
	return (max);
}

int		main(void)
{
	int		res;

	res = find_max_int(10, 3, 11, -1);
	printf("Max: %d\n", res);
	return (0);
}

//============================VA_ARG===========================================
size_t	display_int (int val)
{
	if (val < 10)
	{
		putchar (0x30 + val);
		return (1);
	}
	size_t size = display_int(val / 10);
	putchar(0x30 + val % 10);
	return (size);
}

int	ft_printf(const char *format, ...)
{
	va_list	params_infos;
	//Initialisation va_list structure
	va_start(params_infos, format);
	size_t	written_char = 0;
	char	currentChar;

	while ((currentChar =  *format) != '\0')
	{
		format++;
		if (currentChar != '%')
		{
			putchar(currentChar);
			written_char++;
			continue;
		}
		switch (*format++)
		{
			case 'd':
			{
				int		int_val = (int)va_arg(params_infos, int);
				written_char += display_int(int_val);
			}
			break;
			case 's':
			{
				const char	*str;
				str = (const char *)va_arg(params_infos, const char *);
				while (*str != '\0')
				{
					putchar(*str++);
					written_char++;
				}
			}
			break;
			default:
			{
				fprintf(stderr, "format Error");
				abort();
			}
		}
	}
	va_end(params_infos);
	return written_char;
}

int		main(void)
{
	//size_t	res;
	//res = display_int(15);
	size_t size;
	int		n;
	size = ft_printf( "Begin %s End\n", "Middle" );
	n = ft_printf("int:%dn", 123);
	return (0);
}
*/
//========================VA_COPY=============================================

void	doubleLoop(int first, ...)
{
	va_list	list;
	va_start(list, first);

	int		count;
	count = 1; // car first est un element de list
	va_list	list_tmp;
	va_copy(list_tmp, list); //copy list dans list_tmp
	int		current;
	do
	{
		current = (int) va_arg(list_tmp, int);
		if (current != -1)
			count++;
	}
	while (current != -1);
	{
		va_end(list_tmp);
	}
	//while (current != -1)
	//{
	//	va_end(list_tmp);
	//}
	printf ("%d%s", first, (count>1?".": "\n"));
	for (int i=1; i < count; i++)
	{
		current = (int)va_arg(list, int);
		printf("%d%s", current, (i < count-1?". ":"\n"));
	}
	va_end(list);
}

int		main(void)
{
	doubleLoop(10, 33, 42, 1, -1);
	//doubleLoop(50, 40, -1);
	return(0);
}
