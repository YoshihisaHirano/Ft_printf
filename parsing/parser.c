#include "../ft_printf.h"

void	zero_initialize(t_print *elt)
{
	elt->flag = 0;
	elt->width = 0;
	elt->prec_val = 0;
	elt->type = 0;
	elt->len = 0;
	elt->is_prec = 0;
	elt->invalid_char = 0;
	elt->hash_flag = 0;
	elt->plus_flag = 0;
}

int	parse_format(char const *s, t_print *elt, va_list args)
{
	int	offset;

	offset = 0;
	zero_initialize(elt);
	get_flag(s + offset, elt, &offset);
	get_width(s + offset, elt, &offset, args);
	get_prec(s + offset, elt, &offset, args);
	get_width(s + offset, elt, &offset, args);
	get_type(s + offset, elt, &offset);
	return (offset);
}
