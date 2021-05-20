#include "../ft_printf.h"

int	find_num_len_u(unsigned long nbr, char *base, t_print *elt)
{
	unsigned long	base_size;
	int				num_len;

	num_len = 0;
	if (elt->is_prec && elt->prec_val == 0 && nbr == 0)
		return (0);
	base_size = (unsigned long) ft_strlen(base);
	if (nbr == 0)
		num_len = 1;
	while (nbr)
	{
		nbr /= base_size;
		num_len++;
	}
	return (num_len);
}

void	ft_putnbr_base_u(unsigned long nbr, char *base)
{
	unsigned long	base_size;
	int				idx;
	unsigned long	final_num[20];

	base_size = (unsigned long) ft_strlen(base);
	idx = 0;
	if (nbr == 0)
	{
		write(1, "0", 1);
		return ;
	}
	while (nbr)
	{
		final_num[idx] = nbr % base_size;
		idx++;
		nbr /= base_size;
	}
	while (idx-- > 0)
		write(1, &(base[final_num[idx]]), 1);
}

void	add_prec_u(t_print *elt, unsigned long num, int num_len, char *base)
{
	if (elt->is_prec && elt->prec_val == 0 && elt->type == 'p' && num == 0)
	{
		indicate_address(elt, num);
		return ;
	}
	if (elt->is_prec && elt->prec_val == 0 && num == 0)
		return ;
	indicate_address(elt, num);
	if (elt->prec_val > num_len)
	{
		print_sym(elt->prec_val - num_len, '0');
		ft_putnbr_base_u(num, base);
	}
	else
		ft_putnbr_base_u(num, base);
}

void	print_n_wprec_u(t_print *elt, unsigned long n, int n_len, char *base)
{
	long int	total_len;

	total_len = 0;
	if (elt->prec_val > n_len)
		total_len = elt->prec_val;
	else
		total_len = n_len;
	if (elt->type == 'p' || (elt->hash_flag && n != 0))
		total_len += 2;
	if (elt->flag == '-')
	{
		add_prec_u(elt, n, n_len, base);
		print_sym(elt->width - total_len, ' ');
	}
	else
	{
		print_sym(elt->width - total_len, ' ');
		add_prec_u(elt, n, n_len, base);
	}
}

void	print_n_woprec_u(t_print *elt, unsigned long n, int n_len, char *base)
{
	if (elt->type == 'p' || (elt->hash_flag && n != 0))
		n_len += 2;
	if (elt->flag == '0')
	{
		indicate_address(elt, n);
		print_sym(elt->width - n_len, '0');
		ft_putnbr_base_u(n, base);
	}
	else if (elt->flag == '-')
	{
		indicate_address(elt, n);
		ft_putnbr_base_u(n, base);
		print_sym(elt->width - n_len, ' ');
	}
	else
	{
		print_sym(elt->width - n_len, ' ');
		indicate_address(elt, n);
		ft_putnbr_base_u(n, base);
	}
}
