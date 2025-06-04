# ——————————————————————————————
#  Makefile for “DAFT” project (SDL2 + Libft + src)
# ——————————————————————————————

# Directory where all .o files go:
O_DIR := obj

# Project root (current directory)
ROOT := .

# ------------------------------------------------
# 1) Collect every .c under Libft/ 
#    (ft_*.c, other_*.c, plus the three “mfile_*.c” files)
# ------------------------------------------------
LIBFT_SRC := \
	$(wildcard $(ROOT)/Libft/ft_*.c) \
	$(wildcard $(ROOT)/Libft/other_*.c) \
	$(ROOT)/Libft/mfile_a_gnl.c \
	$(ROOT)/Libft/mfile_rw_support.c \
	$(ROOT)/Libft/mfile_store_fds_user.c \
	$(ROOT)/Libft/mfile_store_fds_utils.c

# ------------------------------------------------
# 2) Collect every .c under src/ 
# ------------------------------------------------
SRC := $(wildcard $(ROOT)/src/*.c)

# ------------------------------------------------
# 3) Turn “./Libft/foo.c”  → “obj/foo.o”
# ------------------------------------------------
#    We know every entry in LIBFT_SRC looks like “./Libft/NAME.c”, 
#    so the pattern “$(ROOT)/Libft/%.c” matches it.
#    Replacing with “$(O_DIR)/%.o” yields “obj/NAME.o”.
# ------------------------------------------------
LIBFT_OBJ := $(patsubst $(ROOT)/Libft/%.c,$(O_DIR)/%.o,$(LIBFT_SRC))

# ------------------------------------------------
# 4) Turn “src/bar.c”  → “obj/bar.o”
# ------------------------------------------------
PROG_OBJ := $(patsubst src/%.c,$(O_DIR)/%.o,$(SRC))

# ------------------------------------------------
# 5) Everything we depend on at link time:
# ------------------------------------------------
OBJ := $(LIBFT_OBJ) $(PROG_OBJ)

# ------------------------------------------------
# 6) Our final executable name:
# ------------------------------------------------
NAME := daft.out

# ------------------------------------------------
# 7) Compiler + flags
# ------------------------------------------------
COMP   := cc
CFLAGS := -Wall -Wextra -Werror -g $(shell sdl2-config --cflags)
LDFLAGS:= $(shell sdl2-config --libs)

# ------------------------------------------------
# 8) Phony targets
# ------------------------------------------------
.PHONY: all clean fclean re

# ------------------------------------------------
# Default rule: build the executable
# ------------------------------------------------
all: $(NAME)

# Link step: make $(NAME) from all object files
# Note: “| $(O_DIR)” means “ensure obj/ exists before proceeding”
$(NAME): $(OBJ) | $(O_DIR)
	@echo "Linking: $(OBJ)"
	$(COMP) $(CFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS)

# ------------------------------------------------
# 9) Ensure the obj/ directory exists
# ------------------------------------------------
# This rule says: “if you ever need obj/, just mkdir -p it”
$(O_DIR):
	mkdir -p $(O_DIR)

# ------------------------------------------------
# 10) How to compile ANY “./Libft/NAME.c” → “obj/NAME.o”
#     (Note: identical target‐pattern for all Libft files)
# ------------------------------------------------
$(O_DIR)/%.o: $(ROOT)/Libft/%.c | $(O_DIR)
	@echo "Compiling Libft: $< → $@"
	$(COMP) $(CFLAGS) -c $< -o $@

# ------------------------------------------------
# 11) How to compile ANY “src/NAME.c” → “obj/NAME.o”
# ------------------------------------------------
$(O_DIR)/%.o: src/%.c | $(O_DIR)
	@echo "Compiling Program: $< → $@"
	$(COMP) $(CFLAGS) -c $< -o $@

# ------------------------------------------------
# 12) Remove just the object‐directory
# ------------------------------------------------
clean:
	rm -rf $(O_DIR)

# ------------------------------------------------
# 13) Remove objects AND the binary itself
# ------------------------------------------------
fclean: clean
	rm -f $(NAME)

# ------------------------------------------------
# 14) “Rebuild from scratch”
# ------------------------------------------------
re: fclean all
