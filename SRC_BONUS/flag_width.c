/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_width.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alachris <alachris@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 01:04:27 by alachris          #+#    #+#             */
/*   Updated: 2022/06/07 01:22:53 by alachris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

void	count_digits_width(const char *str, t_vari **vari,
	va_list print, t_types *types)
{			
	(*vari)->is_negative = 0;
	if (str[(*vari)->i] == 'i' || str[(*vari)->i] == 'd')
	{
		types->integer = va_arg(print, int);
		count_int(vari, types->integer);			
	}
	else if (str[(*vari)->i] == 'u')
	{
		types->unsi_int = va_arg(print, unsigned int);
		count_unsi(vari, types->unsi_int);
	}
	else if ((str[(*vari)->i] == 'x') || (str[(*vari)->i] == 'X'))
	{
		types->unsi_int = va_arg(print, unsigned int);
		count_hexa(types->unsi_int, vari);
	}
}

void	flag_width_continue(const char *str, t_vari **vari, t_types *types)
{
	(*vari)->aux = (*vari)->min - (*vari)->numbers;	
	if ((*vari)->aux > 0)
	{
		while ((*vari)->aux > 0)
		{
			write(1, " ", 1);
			(*vari)->aux--;
			(*vari)->amount++;
		}
	}
	if (str[(*vari)->i] == 'i' || str[(*vari)->i] == 'd')
	{		
		ft_putnbr_fd(types->integer, 1);
		count_numbers(vari, types->integer);
	}
	else if ((str[(*vari)->i] == 'x') || (str[(*vari)->i] == 'X'))
	{
		ft_puthexa(types->unsi_int, str[(*vari)->i], vari);
	}
	else if (str[(*vari)->i] == 'u')
	{
		ft_putnbr_unsi_fd(types->unsi_int, 1);
		count_unsi_numbers(vari, types->unsi_int);
	}
	(*vari)->i++;
}

void	flag_width(const char *str, t_vari **vari,
			va_list print, t_flags **flags)
{	
	t_types	types;

	ft_bzero(&types, sizeof(t_types));
	if ((str[(*vari)->i - (*vari)->n] == ' ')
		|| (str[(*vari)->i - (*vari)->n] == '+'))
		(*vari)->n = 1;
	count_min_zero_neg(str, vari);
	(*vari)->i = (*vari)->i + (*vari)->n;
	count_digits_width(str, vari, print, &types);
	if ((str[(*vari)->i - (*vari)->n] == ' ')
		|| (str[(*vari)->i - (*vari)->n] == '+'))
	{
		if ((*vari)->is_negative == 0)
		{
			if ((*flags)->positive == 0)
				write(1, " ", 1);
			else if ((*flags)->positive == 1)
				write(1, "+", 1);
			(*vari)->min--;
			(*vari)->amount++;
		}
	}
	// else if (types.integer < 0)
	// 	write(1, "-", 1);
	flag_width_continue(str, vari, &types);
}
