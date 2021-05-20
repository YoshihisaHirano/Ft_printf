#include "ft_printf.h"

void	save_res(va_list args, int *res, t_print *elt)
{
	int	*ptr;

	if (elt->type == 'n')
	{
		ptr = va_arg(args, int *);
		*ptr = *res;
	}
}

int	handle_str(char const **s, int *res, t_print *elt)
{
	if (!(**s))
	{
		free(elt);
		return (0);
	}
	if (**s == '%')
	{
		write(1, "%", 1);
		(*s)++;
		(*res)++;
		free(elt);
		return (0);
	}
	return (1);
}

int	parse_process_param(va_list args, char const **s, int *res, int str_len)
{
	t_print	*elt;
	int		elt_len;
	int		offset;

	(*s)++;
	elt = malloc(sizeof(t_print));
	if (!elt)
		return (-1);
	offset = parse_format(*s, elt, args);
	if (!(validate_format(elt, res)))
		return (-1);
	print_str((*s) - str_len, str_len - 1, res);
	if (!(handle_str(s, res, elt)))
		return (1);
	save_res(args, res, elt);
	elt_len = process_elt(args, elt);
	if (elt_len == -1)
		return (-1);
	*res += elt_len;
	*s += offset;
	return (1);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		str_len;
	int		res;
	int		output;

	str_len = 0;
	res = 0;
	va_start(args, s);
	while (*s)
	{
		str_len++;
		if (*s == '%')
		{
			output = parse_process_param(args, &s, &res, str_len);
			if (output == -1)
				return (res);
			str_len = 0;
			continue ;
		}
		s++;
	}
	print_str(s - str_len, str_len, &res);
	va_end(args);
	return (res);
}
