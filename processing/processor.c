#include "../ft_printf.h"

int	process_elt(va_list args, t_print *elt)
{
	int	res;

	if (elt->type == 0)
	{
		free(elt);
		return (-1);
	}
	if (elt->type == 'n')
		elt->len = 0;
	if (elt->type == 'i' || elt->type == 'd')
		process_signed(args, elt);
	if (elt->type == 'u' || elt->type == 'p'
		|| elt->type == 'x' || elt->type == 'X')
		process_unsigned(args, elt);
	if (elt->type == 's')
		process_str(args, elt);
	if (elt->type == 'c')
		process_char(args, elt);
	res = (int) elt->len;
	free(elt);
	return (res);
}
