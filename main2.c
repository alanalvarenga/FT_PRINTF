#include <stdio.h>
#include "ft_printf_bonus.h"

int main()
{
	//char ch = 'B';
	//char str[] = "Palavra";
	//int  i = 120;
	//int  j = 48456125;
	//int		m_int=-2147483647;
	//unsigned int usi = -329494395;
	//unsigned int max_usi = 4294967295;

	int count1 = 0;
	int count2 = 0;
	//printf(" |%c %i %s|\n",ch,i,str);
	//count1 = ft_printf("|%06i|%-8d|%-5s|%%|% i|\n",-856,98,"tes",45);	
	//count2 = printf("|%06i|%-8d|%-5s|%%|% i|\n",-856,98,"tes",45);
	count1 = ft_printf("|%2p| \n",-1);	
	count2 = printf("|%-20s| \n","(void *)-1");
	printf("Quantidade meu: |%i| , original: |%i|\n",count1,count2);
	return (0);
}