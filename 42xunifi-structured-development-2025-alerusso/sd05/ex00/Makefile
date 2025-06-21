NAME = "lib"
LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = main.c srcs/*.c

all: $(NAME)

$(NAME) : $(SRCS) $(LIBFT)
	cc -Wall -Wextra -Werror -g $^ -o $@

$(LIBFT) : 
	$(MAKE) all -C $(LIBFT_DIR) 

clean: 
	rm -f data/*_* data/*.log  $(NAME)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR) 

re: fclean all
	