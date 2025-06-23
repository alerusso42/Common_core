LFLAGS := -Lminilibx-linux -lmlx -lX11 -lXext -lm
# -lft
MLX_GIT := git@github.com:42paris/minilibx-linux.git
MLX := minilibx-linux/*.a
MOUSE := mouse.out
LINE := line.out

all: $(MOUSE) $(LINE)

$(MOUSE): mouse/*.c *.h
	cc -Wall -Wextra -Werror -g mouse/*.c $(MLX) $(LFLAGS) -o $@

$(LINE): mouse_line/*.c *.h
	cc -Wall -Wextra -Werror -g mouse_line/*.c $(MLX) $(LFLAGS) -o $@

get: 
	git clone $(MLX_GIT)
	$(MAKE) all -C minilibx-linux

fclean : 
	rm -rf minilibx-linux *.out

re: fclean get all