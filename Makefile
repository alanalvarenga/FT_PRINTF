NAME = libftprintf.a
LIBFT_PATH = ./Libft
LIBFT = $(LIBFT_PATH)/libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
FILES = ft_printf.c ft_printf_utils.c
OBJECTS = $(FILES:.c=.o)
RM = rm -f

all: $(NAME)

$(NAME): $(OBJECTS)
	make -C $(LIBFT_PATH)
	cp $(LIBFT) $(NAME)
	mv $(LIBFT) $(NAME)
	ar -rcs $(NAME) $(OBJECTS)	

$(OBJECTS): $(FILES)
	$(CC) $(CFLAGS) -c $(FILES)

clean:
	make clean -C $(LIBFT_PATH)
	$(RM) $(OBJECTS) 

fclean: clean
	make fclean -C $(LIBFT_PATH) 
	$(RM) $(NAME)

re: fclean all

testerun: 
	$(CC) $(CFLAGS) main.c $(NAME) && ./a.out

.PHONY: all clean fclean re

