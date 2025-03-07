NAME = libft.a
CC = cc
OBJ_DIR = obj_dir
CFLAGS = -Wall -Wextra -Werror -g
SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
	ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
	ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
	ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
	ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c ft_calloc.c ft_strdup.c
SRC_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
	ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
	ft_lstiter.c ft_lstmap.c
SRC_GAME = game_bfs.c game_bfs_copy.c game_bfs_draw.c game_bfs_utils.c
SRC_MFILE = mfile_find_line.c mfile_get_next_line_original.c \
			mfile_get_n_line.c mfile_gnl.c \
			mfile_gnl_utils1.c mfile_gnl_utils2.c \
			mfile_hold_space.c mfile.main.c mfile_num_line.c \
			mfile_read_all_line.c mfile_read_line.c mfile_reset_fd.c \
			mfile_set_maximum_word_len.c mfile_store_fds_back.c \
			mfile_store_fds_user.c mfile_write_line.c mfile_initiate_file.c
SRC_OTHER = other_add_sign.c other_cut_string.c other_del_pointer.c \
			other_free_matrix.c other_move_sign.c other_realloc.c \
			other_strjoin_free.c other_sub_string_tools.c \
			other_trim_only.c
SRC_PISCINE =	piscine_capitalize.c piscine_conver_base1.c \
				piscine_convert_base2.c piscine_factorial.c \
				piscine_find_next_prime.c piscine_is_lower.c \
				piscine_isprime.c piscine_is_upper.c piscine_power.c \
				piscine_rev_tab.c piscine_sort_int_tab.c piscine_sqrt.c \
				piscine_strlowcase.c
SRC_PRINTF =	printf_light.c printf_fd.c
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
OBJ_BONUS = $(addprefix $(OBJ_DIR)/, $(SRC_BONUS:.c=.o))
OBJ_GAME = $(addprefix $(OBJ_DIR)/, $(SRC_GAME:.c=.o))
OBJ_MFILE = $(addprefix $(OBJ_DIR)/, $(SRC_MFILE:.c=.o))
OBJ_OTHER = $(addprefix $(OBJ_DIR)/, $(SRC_OTHER:.c=.o))
OBJ_PISCINE = $(addprefix $(OBJ_DIR)/, $(SRC_PISCINE:.c=.o))
OBJ_PRINTF = $(addprefix $(OBJ_DIR)/, $(SRC_PRINTF:.c=.o))

$(NAME): $(OBJ) $(OBJ_BONUS) $(OBJ_PRINTF)
	ar rcs $(NAME) $(OBJ) $(OBJ_BONUS) $(OBJ_PRINTF)

$(OBJ_DIR) : 
	mkdir -p $(OBJ_DIR)

piscine: $(OBJ) $(OBJ_BONUS) $(OBJ_PISCINE) $(OBJ_PRINTF)
	ar rcs $(NAME) $(OBJ) $(OBJ_BONUS) $(OBJ_PISCINE) $(OBJ_PRINTF)

other: $(OBJ) $(OBJ_BONUS) $(OBJ_PISCINE) $(OBJ_OTHER) $(OBJ_PRINTF)
	ar rcs $(NAME) $(OBJ) $(OBJ_BONUS) $(OBJ_PISCINE) $(OBJ_OTHER) $(OBJ_PRINTF)

mfile: $(OBJ) $(OBJ_BONUS) $(OBJ_PISCINE) $(OBJ_OTHER) $(OBJ_PRINTF) $(OBJ_MFILE)
	ar rcs $(NAME) $(OBJ) $(OBJ_BONUS) $(OBJ_PISCINE) $(OBJ_OTHER) $(OBJ_PRINTF) $(OBJ_MFILE)

all: $(OBJ) $(OBJ_BONUS) $(OBJ_PISCINE) $(OBJ_OTHER) $(OBJ_PRINTF) $(OBJ_MFILE) $(OBJ_GAME)
	ar rcs $(NAME) $(OBJ) $(OBJ_BONUS) $(OBJ_PISCINE) $(OBJ_OTHER) $(OBJ_PRINTF) $(OBJ_MFILE) $(OBJ_GAME)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o *.txt *.out
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all


.PHONY: all clean fclean re piscine other mfile
