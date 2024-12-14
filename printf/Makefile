NAME = libftprintf.a
LIBFT = Libft/libft.a
CP = cp
SRC = 	ft_printf.c flags_manage.c flags_manage_2.c print_flags.c print_char.c\
		 print_strings.c print_signed_int.c print_lower_hex.c\
		 print_upper_hex.c print_unsigned_int.c print_pointer.c

OBJ = $(SRC:.c=.o)
COMP = cc -Wall -Werror -Wextra
LIBFT_RELATIVE_PATH = Libft/

all: $(NAME)
	

$(NAME) : $(LIBFT) $(OBJ)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ)

$(LIBFT) : 
	$(MAKE) -C $(LIBFT_RELATIVE_PATH)

%.o: %.c
	$(COMP) -c $< -o $@

clean: 
	rm -f $(OBJ)
	$(MAKE) clean -C $(LIBFT_RELATIVE_PATH)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_RELATIVE_PATH)

re: fclean all

main: re
	$(COMP) -g main.c $(NAME) -o hello_world.out
	rm -f $(OBJ)
	$(MAKE) clean -C $(LIBFT_RELATIVE_PATH)

gdb: 
	cc -g main.c $(SRC) $(LIBFT)
	clear
	gdb ./a.out

run:
	cc -g main.c $(SRC) $(LIBFT)
	clear
	./a.out

val:
	cc -g main.c $(SRC) $(LIBFT)
	clear
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./a.out

.PHONY: all clean fclean re main
