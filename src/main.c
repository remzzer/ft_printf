#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int		main(void)
{
int		res = 0;
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
	//res = printf("vreal:%7d\n", 33); //____5
	//res = ft_printf("vreal:%.6d\n", -3); //____5
	//res = ft_printf("vreal:%.0d|\n", 35); //____5
	res = ft_printf("vreal:%-10.5d|\n",-134); //____5
	//res = printf("vreal:%5.0d|\n", 0); //____5
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

//res = ft_printf("Myprintf:%5c\n", 's'); //____r OK
//res = printf("Myprintf:%5c\n", 's'); //____s OK
//res = ft_printf("Myprintf:%-2c\n", 'R'); //r OK
//res = printf("Myprintf:%-2c\n", 'R'); //s OK

//=====================str===================//

//res = ft_printf("Myprintf: %s\n", NULL);
//res = printf("Myprintf: %s\n", NULL);
//printf("Real: %s\n", "exemple");

//WIDTH
//res = ft_printf("Real: %15s\n", "exemple"); //_______exemple OK
//res = printf("Real: %15s\n", "exemple"); //_______exemple OK
//res = printf("Real: %5s\n", "exemple"); //_______exemple OK
//res = ft_printf("Real: %7.5s\n", "yolo"); //
//res = ft_printf("Real: %.01s\n", "yolo1"); //
//res = printf("Real:%.09s|\n", "yolo"); //
//res = ft_printf("Real:%7.5s\n", "yolo"); //
//res = ft_printf("Real: %-7.5s|\n", "tubular"); //
//res = printf("Real: %-7.5s|\n", "tubular"); //
//res = ft_printf("Real: %-15s|\n", "exemple"); //exemple OK
//res = printf("Real: %-15s|\n", "exemple"); //exemple OK
//res = ft_printf("REAL: %*s\n", 15, "exemple"); //_______exemple OK
//res = printf("REAL: %*s\n", 15, "exemple"); //_______exemple OK
//res = ft_printf("REAL: %*s\n", 6, "exemple"); //exemple OK
//res = printf("REAL: %*s\n", 6, "exemple"); //exemple  OK
//res = ft_printf("REAL: %*s\n", -6, "exemple"); //exemple  OK
//res = printf("REAL: %*s\n", -6, "exemple"); //exemple  OK
//res = ft_printf("REAL:%*s|\n", -15, "exemple"); //exemple________
//res = printf("REAL:%*s|\n", -15, "exemple"); //exemple________

//PRECISION
//res = ft_printf("Myprintf: %.5s|\n", "exe"); //exemple
//res = printf("Myprintf: %.5s|\n", "exe"); //exe
//ft_printf("Myprintf: %.*s\n", 1, "exemple"); //exemple
//printf("Real: %.*s\n", 1, "exemple"); //e
//ft_printf("Myprintf: %.*s\n", -5, "exemple"); //exemple
//printf("Real: %.*s\n", -5, "exemple"); //exemple
//res = ft_printf("Myprintf: %.s\n", "exemple");
//res = printf("Myprintf: %.s\n", "exemple");

//printf("Real:%s\n", NULL); //(null)
//ft_printf("Myprintf:%s\n", NULL);
//res = ft_printf("real:%.19s\n", NULL);
//res = printf("real:%.19s\n", NULL);
//res = ft_printf("real:%.09s\n", NULL);
//res = ft_printf("real:%3.6s|\n", "");
//res = printf("real:%.6s|\n", "Y");
//res = printf("real:%3.6s|\n", "");
//res = ft_printf("real:%7.3s|\n", "hello");

//res = ft_printf("Myprintf:%.*s\n", 3, "exemple"); //exemple
//res = printf("Myprintf:%.*s\n", 3, "exemple"); //exemple
//res = ft_printf("Real_width:%8s\n", "exemple"); //exemple
//res = printf("Real_width:%8s\n", "exemple"); //_______exemple
printf("Result%d\n", res);
	return (0);
}
