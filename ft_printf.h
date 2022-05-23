/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alachris <alachris@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 22:25:08 by alachris          #+#    #+#             */
/*   Updated: 2022/05/24 00:11:45 by alachris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

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


# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include "./Libft/libft.h"

int		ft_printf(const char *str,...);
void	count_numbers(t_vari **vari, int integer);
void	ft_putnbr_unsi_fd(unsigned int n, int fd);
void	count_unsi_numbers(t_vari **vari, unsigned int unsi_int);
void	ft_puthexa(unsigned long n, int c, t_vari **vari);
void	ft_puthexa_point(unsigned long n, t_vari **vari);

#endif