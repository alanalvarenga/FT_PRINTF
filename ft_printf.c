#include "ft_printf.h"

void	no_flags(const char *str, t_vari **vari,va_list print)
{
	char	*string;
	char	character;
	int		integer;
	

	if (str[(*vari)->i + 1] == '%')
		write(1,"%",1);	
	else if (str[(*vari)->i + 1] == 's')
	{
		string = va_arg(print,char*);
		ft_putstr_fd(string, 1);
		(*vari)->amount = (*vari)->amount + ft_strlen(string);
	}
	else if (str[(*vari)->i + 1] == 'c')
	{
		character = va_arg(print,int);
		ft_putchar_fd(character,1);
		(*vari)->amount++;
	}
	else if (str[(*vari)->i + 1] == 'i' || str[(*vari)->i + 1] == 'd')
	{
		integer = va_arg(print,int);
		ft_putnbr_fd(integer,1);
		count_numbers(&vari,integer);
	}
	(*vari)->i = (*vari)->i + 2;
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
		no_flags(str,&vari,print);
	else
		with_flags(str,vari,print);
	
	//string = va_arg(print,char*);
	//ft_putstr_fd(string, 1);
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

	return (vari.amount);
}