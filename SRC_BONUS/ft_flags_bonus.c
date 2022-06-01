/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alachris <alachris@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 03:18:41 by alachris          #+#    #+#             */
/*   Updated: 2022/06/01 20:55:59 by alachris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

void	using_flags(const char *str, t_vari **vari, va_list print, t_flags *flags)
{
	if (flags->negative == 1)
		flag_negative(str, vari, print);
	if (flags->space == 1)
		flag_space(str, vari, print);
}

void	is_flag(const char *str, t_vari **vari, va_list print)
{
	t_flags	flags;
	int		n;

	ft_bzero(&flags, sizeof(t_flags));
	n = 0;
	while (str[(*vari)->i + n] != ft_isalpha(str[(*vari)->i + n]))
	{
		if (str[(*vari)->i + n] == '-')
			flags.negative = 1;
		else if (str[(*vari)->i + n] == '0')
			flags.zero = 1;
		else if (str[(*vari)->i + n] == ' ')
			flags.space = 1;
		else if (str[(*vari)->i + n] == '#')
			flags.sharp = 1;
		else if (str[(*vari)->i + n] == '+')
			flags.positive = 1;
		else if (str[(*vari)->i + n] == ft_isdigit(str[(*vari)->i + n]))
			flags.width = 1;
		else if (str[(*vari)->i + n] == '.')
			flags.point = 1;
		n++;
	}
	using_flags(str, vari, print, &flags);	
}
