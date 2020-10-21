#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	init_struct(str_spec *format)
{
	format->width = 0;
	format->zero =  0;
	format->type_flags = 0;
}

int		set_flag_params(int id_flags, str_spec *format)
{
	format->type_flags = id_flags;
	return (id_flags);
}
