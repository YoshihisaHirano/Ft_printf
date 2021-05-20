#include "../ft_printf.h"

void	indicate_address(t_print *elt, unsigned long num)
{
	if (elt->type == 'p' || (elt->hash_flag && num != 0 && elt->type == 'x'))
		write(1, "0x", 2);
	else if (elt->hash_flag && num != 0 && elt->type == 'X')
		write(1, "0X", 2);
}

void	process_to_print(t_print *elt, char *base, unsigned long num, int n_len)
{
	elt->len = n_len;
	if (elt->is_prec)
	{
		print_n_wprec_u(elt, num, n_len, base);
		if (elt->len < elt->prec_val)
			elt->len = elt->prec_val;
	}
	else
		print_n_woprec_u(elt, num, n_len, base);
	if (elt->type == 'p' || (elt->hash_flag && num != 0))
		elt->len += 2;
	if (elt->len < elt->width)
		elt->len = elt->width;
}

void	process_unsigned(va_list args, t_print *elt)
{
	int				num_len;
	unsigned long	num;
	char			*base;

	if (elt->type == 'p')
		num = va_arg(args, unsigned long);
	else
		num = (unsigned long) va_arg(args, unsigned int);
	if (elt->type == 'X')
		base = "0123456789ABCDEF";
	else if (elt->type == 'x' || elt->type == 'p')
		base = "0123456789abcdef";
	else
		base = "0123456789";
	num_len = find_num_len_u(num, base, elt);
	process_to_print(elt, base, num, num_len);
}
