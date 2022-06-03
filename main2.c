#include <stdio.h>
#include "ft_printf_bonus.h"

int main()
{
	//char ch = 'B';
	//char str[] = "Palavra";
	//int  i = 120;
	//int  j = 48456125;
	//int		m_int=-2147483647;
	//unsigned int usi = 329494395;
	//unsigned int max_usi = 4294967295;

	int count1 = 0;
	int count2 = 0;
	//printf(" |%c %i %s|\n",ch,i,str);
	count1 = ft_printf("|% i|%- 8d|\n",85,-123);	
	count2 = printf("|% i|%- 8d|\n",85,-123);
	printf("Quantidade meu: |%i| , original: |%i|\n",count1,count2);
	return (0);
}