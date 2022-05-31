NAME = libftprintf.a
NAME_BONUS = libftprintf_bonus.a
LIBFT_PATH = ./Libft
INCLUDE = ft_printf.h
INCLUDE_BONUS = ft_printf_bonus.h
LIBFT = $(LIBFT_PATH)/libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
PATH_SRC = ./SRC/
PATH_SRC_BONUS = ./SRC_BONUS/
FILES = $(PATH_SRC)ft_printf.c $(PATH_SRC)ft_printf_utils.c
OBJECTS = $(FILES:.c=.o)
FILES_BONUS = $(PATH_SRC_BONUS)ft_printf_bonus.c $(PATH_SRC_BONUS)ft_printf_utils_bonus.c
OBJECTS_BONUS = $(FILES_BONUS:.c=.o)
RM = rm -f

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJECTS)
		@ make -C $(LIBFT_PATH)
		@ cp $(LIBFT) $(NAME)
		@ mv $(LIBFT) $(NAME)
		@ ar -rcs $(NAME) $(OBJECTS) $(INCLUDE)

$(PATH_SRC)%.o: $(PATH_SRC)%.c
		@ $(CC) $(CFLAGS) -c $< -o $@

#	make OBJECTS="$(OBJECTS_BONUS)"
$(NAME_BONUS): $(OBJECTS_BONUS) $(INCLUDE_BONUS)
		@ make -C $(LIBFT_PATH)
		@ cp $(LIBFT) $(NAME_BONUS)
		@ mv $(LIBFT) $(NAME_BONUS)
#		@ cp $(NAME_BONUS) $(NAME)
		@ ar -rcs $(NAME_BONUS) $(OBJS_BONUS)

$(PATH_SRC_BONUS)%.o: $(PATH_SRC_BONUS)%.c
		@ $(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(LIBFT_PATH)
	$(RM) $(OBJECTS) $(OBJECTS_BONUS)

fclean: clean
	make fclean -C $(LIBFT_PATH) 
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

testerun: 
	$(CC) main.c $(NAME) && ./a.out

testbonus:
	gcc main2.c $(NAME_BONUS) && ./a.out

.PHONY: all clean fclean re

