#cc -Wall -Wextra -Werror $(sdl2-config --cflags) ft_*.c mfile_a_gnl.c mfile_rw_support.c mfile_store_fds_user.c mfile_store_fds_utils.c $(sdl2-config --libs)

O_DIR = obj/

SRC = $(wildcard ../Libft/ft_*.c) \
	  mfile_a_gnl.c mfile_rw_support.c mfile_store_fds_user.c mfile_store_fds_utils.c
OBJ := $(patsubst ../Libft/%.c, $(O_DIR)%.o, $(SRC))

NAME = test.out

COMP = cc
CFLAGS = -Wall -Wextra -Werror $(shell sdl2-config --cflags)
LDFLAGS = $(shell sdl2-config --libs)

all: 

$(NAME): $(O_DIR) $(OBJ)
	$(COMP) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(O_DIR):
	mkdir -p $(O_DIR)

$(O_DIR)%.o: ../Libft/%.c | $(O_DIR)
	$(COMP) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(O_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
