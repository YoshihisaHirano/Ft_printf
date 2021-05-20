#include "../ft_printf.h"

void	get_flag(char const *s, t_print *elt, int *offset)
{
	while (is_valid_flag(*s))
	{
		if (*s == '0' && elt->flag != '-')
			elt->flag = '0';
		if (*s == '-')
			elt->flag = '-';
		if (*s == '#' && !elt->hash_flag)
			elt->hash_flag = 1;
		if (*s == ' ' && elt->plus_flag != '+')
			elt->plus_flag = ' ';
		if (*s == '+')
			elt->plus_flag = '+';
		s++;
		(*offset)++;
	}
}

void	get_type(char const *s, t_print *elt, int *offset)
{
	if (is_valid_type(*s))
		elt->type = *s;
	else if (*s == 0)
		elt->type = 0;
	else
	{
		elt->type = 'c';
		elt->invalid_char = *s;
	}
	(*offset)++;
}

void	get_width(char const *s, t_print *elt, int *offset, va_list args)
{
	while (is_valid_width(*s))
	{
		if (*s == '*')
		{
			elt->width = (long int) va_arg(args, int);
			if (elt->width < 0)
			{
				elt->flag = '-';
				elt->width = elt->width * (-1);
			}
		}
		if (ft_isdigit(*s))
		{
			elt->width = ft_atoi(s);
			while (ft_isdigit(*s))
			{
				s++;
				(*offset)++;
			}
			continue ;
		}
		s++;
		(*offset)++;
	}
}

void	get_prec(char const *s, t_print *elt, int *offset, va_list args)
{
	if (*s == '.')
	{
		elt->is_prec = 1;
		s++;
		(*offset)++;
		if (*s == '*')
		{
			elt->prec_val = (long int) va_arg(args, int);
			if (elt->prec_val == -2147483648)
				elt->prec_val = elt->prec_val * (-1);
			else if (elt->prec_val < 0)
				elt->is_prec = 0;
			(*offset)++;
		}
		else if (ft_isdigit(*s))
		{
			elt->prec_val = ft_atoi(s);
			while (ft_isdigit(*s))
			{
				s++;
				(*offset)++;
			}
		}
	}
}
