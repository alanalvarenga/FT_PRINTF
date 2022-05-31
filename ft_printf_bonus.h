/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alachris <alachris@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 21:24:21 by alachris          #+#    #+#             */
/*   Updated: 2022/05/31 01:38:17 by alachris         ###   ########.fr       */
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
	int	del;
}					t_vari;

typedef struct s_types
{
	char			*string;
	char			character;
	int				integer;
	unsigned int	unsi_int;	
	unsigned long	unsi_long;
}					t_types;

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

#endif