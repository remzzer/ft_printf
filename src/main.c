#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int		main(void)
{
//====================TEST GLOBAL==============//
	//ft_printf("char:%c\n str:%s\n dec:%d\n hex:%x\n HEX:%X\n", 'r', "yolo", 11, 10, 10);
	//ft_printf("star:%-*d", 3, 5);
	ft_printf("star:%.*d", 3, 5);

//========DECIMAL==============================//
/*
//flags
	printf("vreal:%05d\n", 5);
	printf("vreal:%-5d\n", 5);

//width

	printf("vreal:%-*d\n", 2, 5);
	printf("vreal:%0*d\n", 2, 5);
	printf("vreal:%5d\n", 2);

//precision

	printf("vreal:%.2d\n", 2);
	printf("vreal:%.*d\n", 6, 1);
	//ft_printf("Myprintf:%-5d",5);
	//ft_printf("Myprintf:%-5d\n",5);
//=====================CHAR===================//



//=====================str===================//
	return (0);
*/
}
