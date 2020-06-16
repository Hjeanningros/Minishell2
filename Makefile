##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile Defender
##

REDDARK=\033[31;2m
RED=\033[31;1m
GREEN=\033[32;1m
YEL=\033[33;1m
BLUE=\033[34;1m
PINK=\033[35;1m
CYAN=\033[36;1m
RES=\033[0m

SRC =	src/main.c 										\
		src/cmd/case_cd.c 								\
		src/cmd/case_env.c 								\
		src/cmd/case_exit.c 							\
		src/cmd/case_others.c 							\
		src/cmd/case_setenv.c 							\
		src/cmd/case_unsetenv.c 						\
		src/lib/get_path.c 								\
		src/lib/getline.c 								\
		src/lib/my_getnbr.c 							\
		src/lib/my_puter.c 								\
		src/lib/my_putstr.c 							\
		src/lib/my_putstr_redir.c 						\
		src/lib/my_str_to_word_array.c 					\
		src/lib/my_strlen.c 							\
		src/lib/my_strcat.c								\
		src/lib/my_strcmp.c 							\
		src/lib/my_tab_len.c 							\
		src/lib/my_wait.c 								\
		src/lib/get_next_line.c 						\
		src/list_lib/add_node_at_end.c 					\
		src/list_lib/delete_a_node.c 					\
		src/list_lib/linked_list_to_tab.c 				\
		src/list_lib/my_initialization_linked_list.c	\
		src/list_lib/print_linked_list.c 				\
		src/redir/case_redir_right.c 					\
		src/redir/check_redir.c							\
		src/redir/case_dredir_right.c					\
		src/redir/case_redir_left.c						\
		src/redir/case_dredir_left.c					\
		src/pipe/check_pipe.c 							\
		src/pipe/case_pipe.c 							\
		src/pipe/which_exec_pipe.c						\
		src/lib/my_str_to_word_array_com.c


OBJ = $(SRC:.c=.o)

NAME = mysh

$(NAME):	$(OBJ)
	gcc  -o $(NAME) $(SRC)
	@echo -e "$(RED)$(NAME) $(GREEN)[✘]$(RES)"

all: 	$(NAME)

clean:
	rm -f $(OBJ)


fclean: clean
		rm -f $(NAME)

re:		fclean all
