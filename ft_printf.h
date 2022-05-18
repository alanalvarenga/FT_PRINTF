#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef struct s_vari
{
	int	amount;
	int i;
	int	del;
}					t_vari;


# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include "./Libft/libft.h"

int ft_printf(const char *str,...);

#endif