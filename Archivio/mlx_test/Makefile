LFLAGS := -Lminilibx-linux -lmlx -lX11 -lXext -lm -Lprintf -LLibft
# -lft
MLX_GIT := git@github.com:42paris/minilibx-linux.git
MLX := minilibx-linux/*.a
MOUSE := mouse.out
LINE := line.out

all: $(MOUSE) $(LINE)

$(MOUSE): mouse/*.c *.h
	cc -Wall -Wextra -Werror -g $^ $(MLX) $(LFLAGS) -o $@

$(LINE): mouse_line/*.c *.h
	cc -Wall -Wextra -Werror -g $^ $(MLX) $(LFLAGS) -o $@

get: 
	git clone $(MLX_GIT)
	$(MAKE) all -C minilibx-linux

fclean : 
	rm -rf minilibx-linux *.out

re: fclean get all