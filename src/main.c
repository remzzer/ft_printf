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

//	unsigned int		b = 0;
//	unsigned int		*ptr = &b;

	//ft_printf("Myprintf:%d\n", 5);
	//res = printf("Myprintf:%p\n", "");
	//res = printf("Myprintf:%p\n", ptr);
	//
	//res = ft_printf("Myprintf:%p\n", ptr);
	//res = printf("Myprintf:%p\n", ptr);
	//res = printf("%u", -2);
	//res = ft_printf("Myprintf:%x\n", b);
	//res = printf("Myprintf:%x\n", b);
	//res = ft_printf("Myprintf:%*s|", -32,  "yolo");
	//res = printf("Myprintf:%*s|", -32,  "yolo");
	//res = ft_printf("%-5%");
	//res = printf("%7i", -54);
	//res = printf("%*i", -7, -54);
	//res = ft_printf("%*i", -7, -54);
	//res = printf("%04.5i", 42);
	//res = ft_printf("%x", -42);
	//res = printf("%x", -42);
	//res = ft_printf("%%|");
	//res = printf("%%");
	//res = printf("%5%");
	//res = ft_printf("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X",
	//8, -12, 123456789, 0, -12345678, "abcdefghijklmnop", 'a', 97, 4294967284,
	//4294967284, 4294967284);
	//I_test:
	//res = ft_printf("%i", 8);
	//res = printf("%i", 8);

	//D_test:
	//res = ft_printf("%d", -12);
	//res = ft_printf("%d", -12);
	//res = printf("%d", -123456789);
	//res = ft_printf("%d", -123456789);
	
	//printf("vreal:%05d\n", 5);
	//printf("vreal:%-5d\n", 5); //5
	//ft_printf("Myprintf:%-05d\n", 5); //5
	//res = printf("vreal:%7d\n", 33); //____5
	//res = ft_printf("vreal:%.6d\n", -3); //____5
	//res = ft_printf("vreal:%.0d|\n", 35); //____5
	//res = ft_printf("vreal:%-10.5d|\n",-134); //____5
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
//res = printf("test:%u",  429496729);
//res = ft_printf("test:%u",  4294967295u);

//=====================HEX===================//
//unsigned int A = -2;
//res = printf("HEX:%x", 17);
//printf("long:%d\n", sizeof(long));
//printf("usigned int:%d\n", sizeof(unsigned int));
//printf("int:%d\n", sizeof(int));
//res = ft_printf("HEX:%-8.5x|", 34);
//res = printf("HEX:%-8.5x", 34);
//res = printf("HEX:%-7x", 33);
//res = printf("HEX:%x", 166000);
//res = ft_printf("HEX:%x", 0);
//res = printf("HEX:%x", 1680);
//
//
//
//
int a = -4;
int i = 8;
int j = -12;
int k = 123456789;
int l = 0;
int m = -12345678;
char c = 'c';
int e = -2147483648;
int d = 2147483647;

//res = printf("%*i, %*d, %*d, %*d, %*d, %*d, %*d, %*d", -4, 8, -4, -12, -4, 123456789, -4, 0, a, m, a, c, a, e, a, d);
//res = ft_printf("%*i, %*d, %*d, %*d, %*d, %*d, %*d, %*d", 4, 8, 4, -12, 4, 123456789, 4, 4, a, m, a, c, a, e, a, d);
//res = printf("%*i, %*d, %*d, %*d, %*d, %*d, %*d, %*d", 4, 8, 4, -12, 4, 123456789, 4, 4, a, m, a, c, a, e, a, d);

//res = printf("%3.d", 42);
//res = printf("%*.*d", 2, 3, 8);
//res = ft_printf("%*.*d", -2, 3, 8);
//res = ft_printf("%12.12d", 42);
//res = ft_printf("%*.*s", 3, 3, "OOO");
//res = printf("%*.*s", -2, 4, "O");
//res = ft_printf("%*.*s", -2, 4, "O");
//res = printf("%*.*s", -2, 3, "O");
//res = ft_printf("%*.*s", 4, 2, "O");
//res = printf("%*.*s", 4, 2, "O");
//res = printf("%*.*s", -2, 4, "O");
//res = ft_printf("%.x", 0);
//res = printf("%.x", 0);

//res = printf("%*.*x", 2, 2, 1); //01
res = ft_printf("%*.*x", 2, 2, 1); //-01

//res = ft_printf("%.*x", 0, -1);
//res = printf("%.*x", 0, -1);

//res = printf("%.3s", "0");
//res = printf("%12.12d", 42);
printf("Result%d\n", res);
	return (0);
}
