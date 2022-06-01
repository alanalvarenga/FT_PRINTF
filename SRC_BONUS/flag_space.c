/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_space.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alachris <alachris@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 21:41:11 by alachris          #+#    #+#             */
/*   Updated: 2022/06/01 00:35:28 by alachris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

void	space_continue(const char *str, t_vari **vari, va_list print)
{
	if ((str[(*vari)->i + 1] == 'x') || (str[(*vari)->i + 1] == 'X')
		|| (str[(*vari)->i + 1] == '%') || (str[(*vari)->i + 1] == 'c')
		|| (str[(*vari)->i + 1] == 's') || (str[(*vari)->i + 1] == 'u'))
	{
		(*vari)->i++;
		no_flags(str, vari, print);
		(*vari)->i++;
	}
	else if (ft_isalpha(str[(*vari)->i + 1]) > 0)
	{
		(*vari)->i++;
		no_flags2(str, vari, print);
	}
}

void	flag_space(const char *str, t_vari **vari, va_list print)
{
	t_types	types;

	ft_bzero(&types, sizeof(t_types));
	if ((str[(*vari)->i + 1] == 'i') || (str[(*vari)->i + 1] == 'd'))
	{
		types.integer = va_arg(print, int);
		if (types.integer >= 0)
		{
			write (1, " ", 1);
			(*vari)->amount++;
		}
		ft_putnbr_fd(types.integer, 1);
		count_numbers(vari, types.integer);
		(*vari)->i = (*vari)->i + 2;
	}
	else if (str[(*vari)->i + 1] == 'p')
	{
		write (1, " ", 1);
		(*vari)->amount++;
		ft_percent_p(vari, print);
		(*vari)->i = (*vari)->i + 2;
	}
	else
		space_continue(str, vari, print);
}
