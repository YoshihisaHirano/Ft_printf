#include "../ft_printf.h"

void	static	add_padding(t_print *elt, char *str, int len)
{
	if (elt->flag == '0')
	{
		print_sym(elt->width - len, '0');
		print_str(str, len, NULL);
	}
	else if (elt->flag == '-')
	{
		print_str(str, len, NULL);
		print_sym(elt->width - len, ' ');
	}
	else
	{
		print_sym(elt->width - len, ' ');
		print_str(str, len, NULL);
	}
}

void	process_str(va_list args, t_print *elt)
{
	char	*str;
	int		len;

	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (elt->is_prec && elt->prec_val == 0)
		len = 0;
	else if (elt->is_prec && elt->prec_val < len)
		len = elt->prec_val;
	if (elt->width > len)
	{
		add_padding(elt, str, len);
		elt->len = elt->width;
	}
	else
	{
		print_str(str, len, NULL);
		elt->len = len;
	}
}
