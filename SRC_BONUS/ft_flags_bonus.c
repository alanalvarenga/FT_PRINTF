/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alachris <alachris@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 03:18:41 by alachris          #+#    #+#             */
/*   Updated: 2022/06/03 04:10:07 by alachris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

void	using_flags(const char *str, t_vari **vari, va_list print, t_flags *flags)
{
	(*vari)->min = 0;
	if (flags->negative == 1)
		flag_negative(str, vari, print, &flags);
	// if (flags->negative == 0 && flags->zero == 1)
	// 	flag_zero();
	// else if (flags->space == 1)
	// 	flag_space(str, vari, print);
	ft_bzero(&flags, sizeof(t_flags));
}

void	is_flag(const char *str, t_vari **vari, va_list print)
{
	t_flags	flags;

	ft_bzero(&flags, sizeof(t_flags));
	(*vari)->n = 0;
	while (!ft_isalpha(str[(*vari)->i + (*vari)->n]))
	{
		if (str[(*vari)->i + (*vari)->n] == '-')
			flags.negative = 1;
		else if (str[(*vari)->i + (*vari)->n] == '0')
			flags.zero = 1;
		else if (str[(*vari)->i + (*vari)->n] == ' ')
			flags.space = 1;
		else if (str[(*vari)->i + (*vari)->n] == '#')
			flags.sharp = 1;
		else if (str[(*vari)->i + (*vari)->n] == '+')
			flags.positive = 1;
		// else if (str[(*vari)->i + (*vari)->n] == ft_isdigit(str[(*vari)->i + (*vari)->n]))
		// 	flags.width = 1;
		// else if (str[(*vari)->i + (*vari)->n] == '.')
		// 	flags.dot = 1;
		(*vari)->n++;
	}
	using_flags(str, vari, print, &flags);	
}
