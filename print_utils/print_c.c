#include "../ft_printf.h"

void	print_str(const char *s, int str_len, int *res)
{
	if (!str_len || !s)
		return ;
	write(1, s, str_len);
	if (res)
		*res += str_len;
}

void	print_sym(int qty, char sym)
{
	int		i;

	if (qty < 0)
		return ;
	i = 0;
	while (i < qty)
	{
		write(1, &sym, 1);
		i++;
	}
}
