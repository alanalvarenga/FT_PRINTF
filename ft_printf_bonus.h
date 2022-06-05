/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alachris <alachris@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 21:24:21 by alachris          #+#    #+#             */
/*   Updated: 2022/06/05 01:00:16 by alachris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include "./Libft/libft.h"
# include <stdio.h>

typedef struct s_vari
{
	int	amount;
	int	i;
	int	n;
	int	amount_current;
	int	min;
	int	aux;
	int	numbers;
	int	is_negative;
}	t_vari;

typedef struct s_types
{
	char			*string;
	char			character;
	int				integer;
	unsigned int	unsi_int;	
	unsigned long	unsi_long;
}	t_types;

typedef struct s_flags
{
	int	space;
	int	negative;
	int	zero;
	int	dot;
	int	sharp;
	int	width;
	int	positive;
}	t_flags;

int		ft_printf(const char *str, ...);
void	count_numbers(t_vari **vari, int integer);
void	ft_putnbr_unsi_fd(unsigned int n, int fd);
void	count_unsi_numbers(t_vari **vari, unsigned int unsi_int);
void	ft_puthexa(unsigned long n, int c, t_vari **vari);
void	ft_puthexa_point(unsigned long n, t_vari **vari);
void	ft_percent_p(t_vari **vari, va_list print);
void	no_flags2(const char *str, t_vari **vari, va_list print);
void	no_flags(const char *str, t_vari **vari, va_list print);
void	verify(const char *str, t_vari *vari, va_list print);
void	is_flag(const char *str, t_vari **vari, va_list print);
void	flag_space(const char *str, t_vari **vari, va_list print);
void	space_continue(const char *str, t_vari **vari, va_list print);
void	using_flags(const char *str, t_vari **vari,
			va_list print, t_flags *flags);
void	flag_negative(const char *str, t_vari **vari,
			va_list print, t_flags **flags);
void	negative_continue(const char *str, t_vari **vari,
			va_list print, t_flags **flags);
void	print_numb_neg_space(t_vari **vari, va_list print);
void	negative_continue2(const char *str, t_vari **vari,
			va_list print, t_flags **flags);
void	negative_continue3(const char *str, t_vari **vari, va_list print);
void	flag_zero(const char *str, t_vari **vari, va_list print);
void	count_digits(const char *str, t_vari **vari,
			va_list print, t_types *types);
void	count_int(t_vari **vari, int integer);
void	count_unsi(t_vari **vari, unsigned int unsi_int);
void	count_hexa(unsigned long n, t_vari **vari);
void	flag_zero_continue(const char *str, t_vari **vari, t_types *types);
void	print_id(int n);

#endif