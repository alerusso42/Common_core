NAME = pipex
NAME_BONUS = bonus
LIBFT = Libft/libft.a
OBJ_DIR = obj_dir
OBJ_BONUS_DIR = obj_bonus_dir
BONUS_DIR = bonus_dir
BONUS_MARK = $(BONUS_DIR)/.bonus_done
SUPPRESSION_FILE = supp.supp
ALL = all.a
CP = cp


SRC = 	alloc_memory.c reset_memory.c storage.c \
		error_message.c \
		general_ft.c \
		print_stuff.c  \
		parsing.c parsing2.c \
		execute_dup.c execute_pipe.c \
		switches.c variables.c main.c \

HEADER = z_function_list.h z_data.h z_header.h 

HEADER_BONUS = 	z_function_list_bonus.h z_data_bonus.h \
				z_header_bonus.h 

# I file bonus vengono generati rinominando i file sorgente con il suffisso _bonus
SRC_BONUS = $(SRC:.c=_bonus.c)
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
BONUS_OBJ = $(addprefix $(OBJ_BONUS_DIR)/, $(SRC:.c=_bonus.o))

COMP = -g -Wall -Wextra -Werror -ILibft -Iprintf
LIBFT_RELATIVE_PATH = Libft/

$(NAME) : $(LIBFT) $(OBJ) $(OBJ_DIR) $(HEADER)
	touch $(ALL)
	cp $(LIBFT) $(ALL)
	cc $(COMP) $(OBJ) $(OBJ_DIR)/dont_switch_to_bonus.o $(ALL) $(LIBX) -o $(NAME)
	@echo "\nall done!!"

all: $(NAME) gen BASH


$(LIBFT) : 
	$(MAKE) all -C $(LIBFT_RELATIVE_PATH)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	cc $(COMP) -c $< -o $@
	cc $(COMP) -c dont_switch_to_bonus.c -o $(OBJ_DIR)/dont_switch_to_bonus.o

# Regola per compilare gli oggetti bonus (escluso switch_to_bonus)
$(OBJ_BONUS_DIR)/%_bonus.o: $(BONUS_DIR)/%_bonus.c | $(OBJ_BONUS_DIR) $(BONUS_MARK)
	cc $(COMP) -c $< -o $@

# Regola separata per switch_to_bonus.o: per evitare relink
$(OBJ_BONUS_DIR)/switch_to_bonus.o: $(BONUS_DIR)/switch_to_bonus.c | $(OBJ_BONUS_DIR) $(BONUS_MARK)
	cc $(COMP) -c $< -o $@

$(HEADER):
	@echo "Missing header!"

$(OBJ_DIR) : 
	mkdir -p $(OBJ_DIR)

$(OBJ_BONUS_DIR): 
	@if [ ! -f $(BONUS_MARK) ]; then \
		echo "\n\nERROR!\nFile $(BONUS_MARK) does not exist.\n--You must call "make gen" before "make bonus"--"; \
		exit 1; \
	else \
		mkdir -p $(OBJ_BONUS_DIR); \
	fi


$(BONUS_DIR) : 
	mkdir -p $(BONUS_DIR)

# Genera i file bonus solo se non sono già presenti (cioe se BONUS_MARK non esiste)
gen: $(BONUS_DIR) $(HEADER_BONUS)
	@if [ ! -f $(BONUS_MARK) ]; then \
		echo "Generating bonus files..."; \
		for file in $(SRC); do \
			cp $$file $(BONUS_DIR)/$${file%.c}_bonus.c; \
		done; \
		for file in $(HEADER_BONUS); do \
			cp $$file $(BONUS_DIR)/$${file}; \
		done; \
		cp switch_to_bonus.c $(BONUS_DIR); \
		cp -r $(LIBFT_RELATIVE_PATH) $(BONUS_DIR); \
		touch $(BONUS_MARK); \
	else \
		echo "Bonus files already generated."; \
	fi

##	calls, in a new process, the rule new_process.
BASH: 
	/bin/bash -c "make new_process"

bonus: gen BASH

##	the rule bonus continue in a new process.
new_process: $(LIBFT) $(OBJ_BONUS_DIR) $(BONUS_OBJ) $(HEADER) $(OBJ_BONUS_DIR)/switch_to_bonus.o
		touch $(ALL)
		cp $(LIBFT) $(ALL)
		cc $(COMP) $(BONUS_OBJ) $(OBJ_BONUS_DIR)/switch_to_bonus.o $(ALL) -o $(NAME_BONUS)
		@echo "\nall done!!"

clean: 
	rm -f $(OBJ) $(ALL) $(NAME) $(NAME_BONUS) *.out *.gdb *.txt *.supp
	rm -rf $(OBJ_DIR) $(BONUS_DIR) $(OBJ_BONUS_DIR)
	$(MAKE) clean -C $(LIBFT_RELATIVE_PATH)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_RELATIVE_PATH)

re: fclean $(NAME)

#set follow-fork-mode child
#set detach-on-fork off

gdb: all
	clear
	gdb --args ./bonus a.txt "ls -l" "grep \.c" "wc -w" b.txt

run: all
	clear
	./$(NAME) $(ARGS)

val: all
	clear
	valgrind --track-fds=yes --trace-children=yes --suppressions=supp.supp --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./bonus a.txt "ls -l" "grep \.c" "wc -l" "xargs -I {} echo Number of .c files in working folder: {}" b.txt
	@echo "\n\n\n\n\nTEST 1 FINISHED!!\n\n\n\n\n\n"
	valgrind --track-fds=yes --trace-children=yes --suppressions=supp.supp --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./bonus here_doc LIMITER "grep \.c" "wc -l" "xargs -I {} echo Number of .c files in working folder: {}" b.txt

supp:
	@if [ ! -f $(SUPPRESSION_FILE) ]; then \
		touch $(SUPPRESSION_FILE); \
		echo "# IGNORE OTHER EXECUTABLES' LEAKS\
		\n{\
		\n\tMALLOC FAILURE OF /usr/bin/*\
		\n\tMemcheck:Leak\
		\n\tfun:malloc\
		\n\t...\
		\n\tobj:/usr/bin/*\
		\n}\
		\n{\
		\n\tCALLOC FAILURE of /usr/bin/*\
		\n\tMemcheck:Leak\
		\n\tfun:calloc\
		\n\t...\
		\n\tobj:/usr/bin/*\
		\n}\
		\n{\
		\n\tREALLOC FAILURE of /usr/bin/*\
		\n\tMemcheck:Leak\
		\n\tfun:realloc\
		\n\t...\
		\n\tobj:/usr/bin/*\
		\n}" > $(SUPPRESSION_FILE); \
		echo "$(SUPPRESSION_FILE) created."; \
	else \
		echo "Suppression file already generated."; \
	fi

.PHONY: all clean fclean re main gdb run val copy_lib gen