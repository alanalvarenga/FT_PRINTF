/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_sharp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alachris <alachris@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 21:08:52 by alachris          #+#    #+#             */
/*   Updated: 2022/06/06 22:30:11 by alachris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

void	flag_sharp(const char *str, t_vari **vari,
			va_list print, t_flags **flags)
{
	(*vari)->i++;
	write(1, "0x", 2);
	(*vari)->amount = (*vari)->amount + 2;
	if (str[(*vari)->i] == '-')
	{
		flag_negative(str, vari, print, flags);
	}
	else if (str[(*vari)->i] == '0')
	{
		(*vari)->numbers = +2;
		flag_zero(str, vari, print, flags);
	}
	else
	{
		no_flags2(str, vari, print);
		(*vari)->i++;
	}	
}
