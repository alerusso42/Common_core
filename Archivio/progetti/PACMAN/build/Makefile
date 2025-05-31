O_DIR = obj/

SRC = 	$(wildcard ../Libft/ft_*.c) \
		$(wildcard ../Libft/other_*.c) \
		../Libft/mfile_a_gnl.c \
	  	../Libft/mfile_rw_support.c \
	  	../Libft/mfile_store_fds_user.c \
	  	../Libft/mfile_store_fds_utils.c


OBJ := $(patsubst ../Libft/%.c, $(O_DIR)%.o, $(SRC))

NAME = test.out

COMP = cc
CFLAGS = -Wall -Wextra -Werror -g $(shell sdl2-config --cflags)
LDFLAGS = $(shell sdl2-config --libs)

all: $(NAME)

$(NAME): $(OBJ) $(O_DIR)
	@echo $(OBJ)
	@$(COMP) $(CFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS)

$(O_DIR):
	mkdir -p $(O_DIR)

$(O_DIR)%.o: ../Libft/%.c | $(O_DIR)
	$(COMP) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(O_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
