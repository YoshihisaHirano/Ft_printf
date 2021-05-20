#include "../ft_printf.h"

void	process_char(va_list args, t_print *elt)
{
	char	c;

	if (elt->invalid_char > 0)
		c = elt->invalid_char;
	else
		c = (char) va_arg(args, int);
	if (elt->flag == '0')
	{
		print_sym((elt->width - 1), '0');
		print_sym(1, c);
	}
	else if (elt->flag == '-')
	{
		print_sym(1, c);
		print_sym((elt->width - 1), ' ');
	}
	else
	{
		print_sym((elt->width - 1), ' ');
		print_sym(1, c);
	}
	if (elt->width == 0)
		elt->len = 1;
	else
		elt->len = elt->width;
}
