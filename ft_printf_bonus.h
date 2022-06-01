/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alachris <alachris@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 21:24:21 by alachris          #+#    #+#             */
/*   Updated: 2022/06/01 21:54:29 by alachris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include "./Libft/libft.h"

typedef struct s_vari
{
	int	amount;
	int	i;
}					t_vari;

typedef struct s_types
{
	char			*string;
	char			character;
	int				integer;
	unsigned int	unsi_int;	
	unsigned long	unsi_long;
}					t_types;

typedef struct s_flags
{
	int	space;
	int	negative;
	int	zero;
	int	point;
	int	sharp;
	int	width;
	int	positive;
}				t_flags;

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
void	using_flags(const char *str, t_vari **vari, va_list print, t_flags *flags);
void	flag_negative(const char *str, t_vari **vari, va_list print);

#endif