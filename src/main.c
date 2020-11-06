#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int		main(void)
{
//====================TEST GLOBAL==============//
	//ft_printf("char:%c\n str:%s\n dec:%d\n hex:%x\n HEX:%X\n", 'r', "yolo", 11, 10, 10);
	//ft_printf("star:%0*d", 3, 5);
	//printf("star:%.*d", 5, 2);
	//
//========DECIMAL================"star:%*==============//

//FLAGS
	//printf("vreal:%05d\n", 5);
	//printf("vreal:%-5d\n", 5); //5
	//ft_printf("Myprintf:%-05d\n", 5); //5
	//printf("vreal:%5d\n", 5); //____5
	//ft_printf("Myprintf:%5d\n", 5); //5

//WIDTH

//	printf("vreal:%-*d\n", 3, 5);//5
//	ft_printf("Myprintf:%-*d\n", 2, 5); //5
//	printf("vreal:%0*d\n", 2, 5); //05
//	ft_printf("myprintf:%0*d\n", 2, 5); //5
//	printf("real:%*d\n", -2, 1); //1
//	ft_printf("Myprintf:%*d\n", -2, 1); //1
//	printf("real:%*d\n", 3, 1); //__1
//	ft_printf("Myprintf:%*d\n", 3, 1); //1
//	printf("real:%523d\n", 2);
//	ft_printf("result:%523d\n", 2);

//PRECISION

//printf("real: %.5d\n", 1); //00001
//ft_printf("myprintf: %.5d\n", 1); //1
//printf("real: %.*d\n", 5, -1); //-00001
//ft_printf("myprintf: %.*d\n", 5, -1); //-1
//printf("real:%.*d\n", -5, -1); //-1
//ft_printf("Myprintf: %.*d\n", -5, -1); //1
//=====================str===================//


//=====================CHAR===================//

//ft_printf("Myprintf:%5c\n", 'r'); //____r OK
//printf("real:%5c\n", 's'); //____s OK
//ft_printf("Myprintf:%-5c\n", 'r'); //r OK
//printf("real:%-5c\n", 's'); //s OK

//=====================str===================//

int		res = 0;
//res = ft_printf("Myprintf: %s\n", NULL);
//res = printf("Myprintf: %s\n", NULL);
//printf("Real: %s\n", "exemple");

//WIDTH
//ft_printf("Myprintf: %15s\n", "exemple"); //exemple
//printf("Real: %15s\n", "exemple"); //_______exemple
//ft_printf("Myprintf: %-15s\n", "exemple"); //exemple
//printf("Real: %-15s\n", "exemple"); //exemple
//res = ft_printf("REAL: %*s\n", 15, "exemple"); //exemple
//res = printf("REAL: %*s\n", 15, "exemple"); //_______exemple
//res = ft_printf("REAL: %*s\n", 6, "exemple"); //_______exemple
//res = printf("REAL: %*s\n", 6, "exemple"); //_______exemple
res = ft_printf("REAL:%*s\n", -15, "exemple"); //exemple
//res = printf("REAL:%*s\n", -5, "exemple"); //exemple

//PRECISION
//ft_printf("Myprintf: %.7s\n", "exemple"); //exemple
//printf("Real: %.7s\n", "exemple"); //exe
//ft_printf("Myprintf: %.*s\n", 1, "exemple"); //exemple
//printf("Real: %.*s\n", 1, "exemple"); //e
//ft_printf("Myprintf: %.*s\n", -5, "exemple"); //exemple
//printf("Real: %.*s\n", -5, "exemple"); //exemple


//printf("Real:%s\n", NULL); //(null)
//ft_printf("Myprintf:%s\n", NULL);


//res = ft_printf("Myprintf:%.*s\n", 3, "exemple"); //exemple
//res = printf("Myprintf:%.*s\n", 3, "exemple"); //exemple
//res = ft_printf("Real_width:%8s\n", "exemple"); //exemple
//res = printf("Real_width:%8s\n", "exemple"); //_______exemple
printf("Result%d\n", res);
	return (0);
}
