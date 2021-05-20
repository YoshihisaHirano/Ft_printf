#include "../ft_printf.h"

int	is_valid_type(char c)
{
	if (c == 's' || c == 'd' || c == 'i' || c == 'p' || c == 'x' || c == 'X'
		|| c == 'c' || c == 'u' || c == 'n')
		return (1);
	return (0);
}

int	is_valid_flag(char c)
{
	if (c == '-' || c == '0' || c == '#' || c == '+' || c == ' ')
		return (1);
	return (0);
}

int	is_valid_width(char c)
{
	if (ft_isdigit(c) || c == '*')
		return (1);
	return (0);
}

int	validate_format(t_print *elt, int *res)
{
	if (elt->prec_val > 2147483645)
	{
		*res = -1;
		free(elt);
		return (0);
	}
	if (elt->width > 2147483639 || elt->width < -2147483639)
	{
		*res = -1;
		free(elt);
		return (0);
	}
	return (1);
}
