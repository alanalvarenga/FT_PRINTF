/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alachris <alachris@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 22:24:48 by alachris          #+#    #+#             */
/*   Updated: 2022/05/24 00:28:14 by alachris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	no_flags2(const char *str, t_vari **vari,va_list print)
{
	t_types types;

	ft_bzero(&types, sizeof(t_types));
	if (str[(*vari)->i + 1] == 'u')
	{
		types.unsi_int = va_arg(print,int);
		ft_putnbr_unsi_fd(types.unsi_int,1);
		count_unsi_numbers(vari,types.unsi_int);		
	}
	else if ((str[(*vari)->i + 1] == 'x') || (str[(*vari)->i + 1] == 'X'))
	{
		types.unsi_int = va_arg(print,unsigned int);
		ft_puthexa(types.unsi_int,str[(*vari)->i + 1],vari);
	}
	else if (str[(*vari)->i + 1] == 'p')
	{
		types.unsi_long = va_arg(print,unsigned long);
		write(1,"0x",2);
		ft_puthexa_point(types.unsi_long,vari);
		(*vari)->amount = (*vari)->amount +2;
	}
}

void	no_flags(const char *str, t_vari **vari,va_list print)
{
	t_types types;

	ft_bzero(&types, sizeof(t_types));
	if (str[(*vari)->i + 1] == '%')
		write(1,"%",1);	
	else if (str[(*vari)->i + 1] == 's')
	{
		types.string = va_arg(print,char*);
		ft_putstr_fd(types.string, 1);
		(*vari)->amount = (*vari)->amount + ft_strlen(types.string);
	}
	else if (str[(*vari)->i + 1] == 'c')
	{
		types.character = va_arg(print,int);
		ft_putchar_fd(types.character,1);
		(*vari)->amount++;
	}
	else if (str[(*vari)->i + 1] == 'i' || str[(*vari)->i + 1] == 'd')
	{
		types.integer = va_arg(print,int);
		ft_putnbr_fd(types.integer,1);
		count_numbers(vari,types.integer);
	}
	else
		no_flags2(str,vari,print);
}

void	with_flags(const char *str, t_vari *vari,va_list print)
{
	(void)str;
	(void)vari;
	(void)print;
}

void	verify(const char *str, t_vari *vari,va_list print)
{
	//char *string;

	(void)str;
	(void)vari;
	if ((ft_isalpha(str[vari->i + 1]) > 0) || (str[vari->i + 1] == '%'))
	{
		no_flags(str,&vari,print);
		(*vari)->i = (*vari)->i + 2;		
	}
	else
		with_flags(str,vari,print);	
}

int ft_printf(const char *str,...)
{
	t_vari vari;
	va_list print;
	va_start(print,str);
	ft_bzero(&vari, sizeof(t_vari));
	while (str[vari.i] != '\0')
	{
		if (str[vari.i] == '%')
			verify(str,&vari,print);
		write (1, &str[vari.i], 1);
		vari.i++;
		vari.amount++;
	}
	va_end(print);

	return (vari.amount);
}