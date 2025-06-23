NAME = "csv_reader"
LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = main.c srcs/*.c header.h

all: $(NAME)

$(NAME) : $(SRCS) $(LIBFT)
	@cc -Wall -Wextra -Werror -g main.c srcs/*.c $(LIBFT) -o $@

$(LIBFT) : 
	$(MAKE) all -C $(LIBFT_DIR)

clean: 
	rm -f  $(NAME)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR) 

re: fclean all
	