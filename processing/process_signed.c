#include "../ft_printf.h"

void	add_sign(long int num, t_print *elt)
{
	if (num < 0)
		write(1, "-", 1);
	else if (num >= 0 && elt->plus_flag)
		print_sym(1, elt->plus_flag);
}

int	check_zero_prec(t_print *elt, long int num)
{
	if (elt->is_prec && elt->prec_val == 0 && num == 0 && !elt->plus_flag)
		return (0);
	if (elt->is_prec && elt->prec_val == 0 && num == 0 && elt->plus_flag)
	{
		print_sym(1, elt->plus_flag);
		return (0);
	}
	return (1);
}

void	process_signed(va_list args, t_print *elt)
{
	int			num_len;
	long int	num;

	num = va_arg(args, int);
	num_len = find_num_len(num, elt);
	elt->len = num_len;
	if (elt->is_prec)
	{
		print_num_wprec(elt, num, num_len);
		if (elt->len < elt->prec_val)
			elt->len = elt->prec_val;
		if ((num < 0 || elt->plus_flag) && num_len <= elt->prec_val)
			elt->len++;
	}
	else
		print_num_woprec(elt, num, num_len);
	if (elt->len < elt->width)
		elt->len = elt->width;
}
