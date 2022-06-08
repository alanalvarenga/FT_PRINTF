/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alachris <alachris@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 22:02:57 by alachris          #+#    #+#             */
/*   Updated: 2022/06/07 23:15:24 by alachris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

void	sharp_zero_x(size_t n, int c, t_vari **vari, t_flags *flags)
{
	if ((flags)->sharp == 1)
	{
		if ((c == 'x') && (n != 0))		
			write(1, "0x", 2);
		else if ((c == 'X') && (n != 0))
			write(1, "0X", 2);
		if (n != 0)
			(*vari)->amount = (*vari)->amount + 2;
		(flags)->sharp = 0;
	}
}

void	ft_free_null(char **ptr)
{
	if (*ptr)
		free(*ptr);
	*ptr = NULL;
}
