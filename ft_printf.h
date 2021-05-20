#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "utils/utils.h"

typedef struct s_print
{
	char		flag;
	char		plus_flag;
	char		type;
	long int	len;
	long int	width;
	int			is_prec;
	long int	prec_val;
	char		invalid_char;
	int			hash_flag;
}				t_print;

int		ft_printf(const char *s, ...);
int		is_valid_type(char c);
int		is_valid_flag(char c);
int		is_valid_width(char c);
void	get_flag(char const *s, t_print *elt, int *offset);
void	get_width(char const *s, t_print *elt, int *offset, va_list args);
void	get_prec(char const *s, t_print *elt, int *offset, va_list args);
void	get_type(char const *s, t_print *elt, int *offset);
int		parse_format(char const *s, t_print *elt, va_list args);
int		process_elt(va_list args, t_print *elt);
void	print_str(const char *s, int str_len, int *res);
void	print_sym(int qty, char sym);
void	process_char(va_list args, t_print *elt);
void	process_str(va_list args, t_print *elt);
void	process_signed(va_list args, t_print *elt);
int		find_num_len(long int nbr, t_print *elt);
void	add_prec(t_print *elt, long int num, int num_len);
void	print_num_wprec(t_print *elt, long int num, int num_len);
void	print_num_woprec(t_print *elt, long int num, int num_len);
void	process_unsigned(va_list args, t_print *elt);
int		find_num_len_u(unsigned long nbr, char *base, t_print *elt);
void	ft_putnbr_base_u(unsigned long nbr, char *base);
void	add_prec_u(t_print *elt, unsigned long num, int num_len, char *base);
void	print_n_wprec_u(t_print *elt, unsigned long n, int n_len, char *base);
void	print_n_woprec_u(t_print *elt, unsigned long n, int n_len, char *base);
void	add_sign(long int num, t_print *elt);
int		check_zero_prec(t_print *elt, long int num);
void	indicate_address(t_print *elt, unsigned long num);
void	ft_putnbr(long int nb);
int		validate_format(t_print *elt, int *res);

#endif
