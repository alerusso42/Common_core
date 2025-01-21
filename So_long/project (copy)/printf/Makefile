NAME = libftprintf.a
LIBFT = Libft/libft.a
CP = cp
SRC = 	ft_printf.c flags_manage.c flags_manage_2.c print_flags.c print_char.c \
		 print_strings.c print_signed_int.c print_lower_hex.c \
		 print_upper_hex.c print_unsigned_int.c print_pointer.c
SRC_BONUS = ft_printf_bonus.c flags_manage_bonus.c flags_manage_2_bonus.c \
			 print_flags_bonus.c print_char_bonus.c \
		 print_strings_bonus.c print_signed_int_bonus.c print_lower_hex_bonus.c \
		 print_upper_hex_bonus.c print_unsigned_int_bonus.c print_pointer_bonus.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
COMP = cc -Wall -Werror -Wextra
LIBFT_RELATIVE_PATH = ../Libft/

all: $(NAME)
	

$(NAME) : $(LIBFT) $(OBJ)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ)

bonus: $(LIBFT) $(OBJ_BONUS)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ_BONUS)

$(LIBFT) : 
	$(MAKE) -C $(LIBFT_RELATIVE_PATH)

%.o: %.c
	$(COMP) -c $< -o $@

clean: 
	rm -f $(OBJ) $(OBJ_BONUS) *.out

fclean: clean
	rm -f $(NAME)

re: fclean all

main: re
	$(COMP) -g main.c $(NAME) -o hello_world.out
	rm -f $(OBJ) $(OBJ_BONUS)

gdb: 
	cc -g main.c $(SRC) $(LIBFT)
	clear
	gdb ./a.out

run:
	cc -g main.c $(SRC) $(LIBFT)
	clear
	./a.out

valgrind:
	cc -g main.c $(SRC) $(LIBFT)
	clear
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./a.out

val: re clean
	$(COMP) main.c $(NAME)
	clear
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./a.out

val_noflags: re clean
	cc main.c $(NAME)
	clear
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./a.out

.PHONY: all clean fclean re main gdb run valgrind val val_noflags
