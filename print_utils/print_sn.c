#include "../ft_printf.h"

int	find_num_len(long int nbr, t_print *elt)
{
	unsigned long	num;
	int				num_len;

	num_len = 0;
	if (elt->is_prec && elt->prec_val == 0 && nbr == 0 && !elt->plus_flag)
		return (0);
	if (nbr < 0)
	{
		num = nbr * (-1);
		num_len++;
	}
	else
		num = nbr;
	if (num == 0)
		num_len = 1;
	if (nbr >= 0 && elt->plus_flag && (!elt->is_prec || (elt->is_prec &&
		elt->prec_val > 0)))
		num_len++;
	while (num)
	{
		num /= 10;
		num_len++;
	}
	return (num_len);
}

void	ft_putnbr(long int nb)
{
	char			result;
	unsigned long	u_nb;

	if (nb < 0)
		u_nb = nb * (-1);
	else if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	else
		u_nb = nb;
	if (u_nb < 10 && u_nb >= 0)
	{
		result = u_nb + '0';
		write(1, &result, 1);
	}
	if (u_nb >= 10)
	{
		ft_putnbr(u_nb / 10);
		result = (u_nb % 10) + '0';
		write(1, &result, 1);
	}
}

void	add_prec(t_print *elt, long int num, int num_len)
{
	if (check_zero_prec(elt, num))
	{
		if (elt->prec_val >= num_len)
		{
			if (num < 0)
			{
				write(1, "-", 1);
				print_sym(elt->prec_val - num_len + 1, '0');
			}
			else if (num >= 0 && elt->plus_flag)
			{
				print_sym(1, elt->plus_flag);
				print_sym(elt->prec_val - num_len + 1, '0');
			}
			else
				print_sym(elt->prec_val - num_len, '0');
			ft_putnbr(num);
		}
		else
		{
			add_sign(num, elt);
			ft_putnbr(num);
		}
	}
}

void	print_num_wprec(t_print *elt, long int num, int num_len)
{
	long int	total_len;

	total_len = 0;
	if (elt->prec_val > num_len)
		total_len = elt->prec_val;
	else
		total_len = num_len;
	if (elt->prec_val >= num_len && (num < 0 || elt->plus_flag))
		total_len++;
	if (elt->flag == '-')
	{
		add_prec(elt, num, num_len);
		print_sym(elt->width - total_len, ' ');
	}
	else
	{
		print_sym(elt->width - total_len, ' ');
		add_prec(elt, num, num_len);
	}
}

void	print_num_woprec(t_print *elt, long int num, int num_len)
{
	if (elt->flag == '0')
	{
		add_sign(num, elt);
		print_sym(elt->width - num_len, '0');
		ft_putnbr(num);
	}
	else if (elt->flag == '-')
	{
		add_sign(num, elt);
		ft_putnbr(num);
		print_sym(elt->width - num_len, ' ');
	}
	else
	{
		print_sym(elt->width - num_len, ' ');
		add_sign(num, elt);
		ft_putnbr(num);
	}
}
