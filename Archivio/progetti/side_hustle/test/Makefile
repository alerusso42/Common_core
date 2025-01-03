NAME =  manage_structs.a
LIBFT = libft.a manage_file_ft.a
SRC = 	test.c \
		write_structlist.c \
		get_struct_list.c

OBJ = $(SRC:.c=.o)
COMP = cc -Wall -Werror -Wextra -g

all: $(NAME) clean
	
$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(COMP) -c $< -o $@

clean: 
	rm -f $(OBJ) *.out *.exe

fclean: clean
	rm -f $(NAME)

re: fclean all

main:
	$(COMP) main.c $(SRC) $(LIBFT)
	clear
	./a.out

gdb: 
	$(COMP) main.c $(SRC) $(LIBFT)
	clear
	gdb ./a.out

run:
	

valgrind:
	$(COMP) main.c $(SRC) $(LIBFT)
	clear
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./a.out

test.c : 
	$(COMP) test.c $(LIBFT)
	clear
	./a.out

gdb_test.c : 
	$(COMP) test.c $(LIBFT)
	clear
	gdb ./a.out

valgrind_test.c : 
	$(COMP) test.c $(LIBFT)
	clear
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./a.out

get_struct_list.c : 
	$(COMP) get_struct_list.c test.c $(LIBFT)
	clear
	./a.out

gdb_get_struct_list.c : 
	$(COMP) get_struct_list.c test.c $(LIBFT)
	clear
	gdb ./a.out

valgrind_get_struct_list.c : 
	$(COMP) get_struct_list.c test.c $(LIBFT)
	clear
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./a.out

.PHONY: all clean fclean re main gdb run valgrind \
		test.c gdb_test.c valgrind_test.c \
		get_struct_list.c gdb_get_struct_list.c valgrind_get_struct_list.c
