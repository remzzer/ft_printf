#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	init_struct(str_spec *format)
{
	format->precision = -1; //argument++ & with
	format->no_prec = 0;
	format->width = 0; //largeur
	format->left_align = 0; //ajuster gauche
	format->zero =  0; //padding
	format->type_flags = 0;// cspdiuxX
}
