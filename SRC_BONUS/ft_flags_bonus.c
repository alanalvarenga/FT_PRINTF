/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alachris <alachris@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 03:18:41 by alachris          #+#    #+#             */
/*   Updated: 2022/06/05 02:20:36 by alachris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

void	using_flags(const char *str, t_vari **vari, va_list print, t_flags *flags)
{
	(*vari)->min = 0;
	(*vari)->n = 0;
	//(*vari)->numbers = 0;
	if (flags->negative == 1)
		flag_negative(str, vari, print, &flags);
	else if (flags->negative == 0 && flags->zero == 1)
	 	flag_zero(str, vari, print);
	else if ((flags->negative == 0) && (flags->zero == 0) && (flags->space == 1))
	 	flag_space(str, vari, print);
	ft_bzero(&flags, sizeof(t_flags));
}

void	is_flag(const char *str, t_vari **vari, va_list print)
{
	t_flags	flags;

	//printf("TESTANDO");
	ft_bzero(&flags, sizeof(t_flags));
	(*vari)->n = 0;
	while (!ft_isalpha(str[(*vari)->i + (*vari)->n])) 
		// || (flags.negative == 0) || (flags.zero == 0)
		// || (flags.space == 0) || (flags.sharp == 0)
		// || (flags.positive == 0))
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
