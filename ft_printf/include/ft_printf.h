/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-de <fvon-der@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:57:20 by fvon-de           #+#    #+#             */
/*   Updated: 2025/04/07 17:19:30 by fvon-de          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h" 

/* ---------- FLAGS --------------------- */
typedef struct s_flags
{
	int	spec;
	int	width;
	int	left;
	int	zero;
	int	star;
	int	precision;
	int	hash;
	int	space;
	int	plus;
}		t_flags;

t_flags	ft_flags_init(void);
t_flags	ft_flag_left(t_flags flags);
t_flags	ft_flag_digit(char c, t_flags flags);
t_flags	ft_flag_width(va_list args, t_flags flags);
int		ft_flag_precision(const char *str, int pos,
			va_list args, t_flags *flags);

/* ---------- PRINTF -------------------- */
int		ft_printf(const char *format, ...);
int		ft_print_arg(char type, va_list args, t_flags flags);

/*------------NEW---------------------------*/
/*------------DPRINTF------------------------*/
int		ft_dprintf(int fd, const char *fmt, ...);

/* ---------- PRINT SPECIFIERS ---------- */
// c
int		ft_print_char(char c, t_flags flags);
int		ft_print_c(char c);
// s
int		ft_print_str(const char *str, t_flags flags);
int		ft_print_s(const char *str);
int		ft_print_s_pre(const char *str, int precision);
int		ft_print_sign_pre(int n, t_flags *flags);
// i, d
int		ft_print_number(long n, t_flags flags);
int		ft_print_integer(char *nbstr, int n, t_flags flags);
int		ft_print_i(char *nbstr, int n, t_flags flags);
// u
int		ft_print_unsigned(unsigned int n, t_flags flags);
int		ft_print_u(char *nbstr, t_flags flags);
int		ft_print_unint(char *nbstr, t_flags flags);
//int		ft_int_min_handler(t_flags flags);
// x, X
int		ft_print_hex_low(unsigned int n, t_flags flags);
int		ft_print_hex_up(unsigned int n, t_flags flags);
int		ft_print_x(char *nbstr, int n, int is_upper, t_flags flags);
int		ft_print_hexadec(char *nbstr, int n, int is_upper, t_flags flags);
// p
int		ft_print_ptr(unsigned long int n, t_flags flags);
int		ft_print_p(unsigned long int n);
void	ft_print_adr(unsigned long int n);
/* ---------- HELPER FUNCTIONS ---------- */
char	*ft_printf_itoa(long nb);
char	*ft_printf_utoa(unsigned int nb);
char	*ft_printf_xtoa(unsigned long int nb, int is_upper);
int		ft_unint_len(unsigned int n);
int		ft_hex_len(unsigned int n);
int		ft_ptr_len(unsigned long int n);
int		ft_istype(int c);
int		ft_isspec(int c);
int		ft_isflag(int c);

/* ---------- FLAG FUNCTIONS ------------ */
int		ft_pad_width(int total_width, int size, int zero);

#endif
