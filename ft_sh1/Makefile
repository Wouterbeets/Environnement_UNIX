# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/04 16:27:25 by wbeets            #+#    #+#              #
#    Updated: 2014/01/25 18:37:48 by tleroy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_minishell1
FILES	= main.c			\
		  ft_get_command.c	\
		  ft_ex_command.c	\
		  ft_count_c.c		\
		  ft_execute.c		\
		  ft_get_path.c		\
		  ft_change_dir.c	\
		  ft_go_home.c		\
		  get_next_line.c	\
		  ft_update_env.c	\
		  ft_opening.c		\
		  ft_search.c
SRCS		= $(addprefix srcs/, $(FILES))
OBJS		= $(SRCS:srcs/%.c=.objs/%.o)
FLAGS	= -Wall -Werror -Wextra
DFLAGS	= -Wall -Werror -Wextra -g3 -pedantic
LIBCOM	= -L libft -lft -L /usr/X11/lib -lmlx -lXext -lX11
NO_COLOR=\x1b[0m
OK_COLOR=\x1b[32;01m
ERROR_COLOR=\x1b[31;01m
WARN_COLOR=\x1b[33;01m
INCLUDE	= -I includes -I libft/includes
DEB		= .deb/test

all: $(NAME)

$(NAME): disp relib disp2 $(OBJS)
	@echo "$(OK_COLOR)\t---OBJECTS CREATED---$(NO_COLOR)"
	@echo  "\t---COMPILING---EXECUTABLE---"
	@gcc $(OBJS) $(INCLUDE) $(FLAGS) $(LIBCOM) -o $@
	@echo  "$(OK_COLOR)\t---SUCCES---"
	@echo  "---COMPILATION COMPLETE---$(NO_COLOR)"

disp:
	@echo  "$(WARN_COLOR)---PLEASE-HOLD---COMPILING--- $(NO_COLOR)"

disp2:
	@echo  "\t---COMPILING---OBJECTS---"

.objs/%.o: srcs/%.c
	@mkdir -p .objs/
	@echo ".\c"
	@gcc $(FLAGS) $(INCLUDE) -c $< -o $@

clean:
	@rm -rf .objs/
	@make clean -C libft/

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(DEB)
	@make fclean -C libft/

re: fclean all

gdb:
	@mkdir -p .deb/
	@cc -o $(DEB) $(INCLUDE) $(DFLAGS) $(LIBCOM) $(SRCS)
	gdb $(DEB)

lib:
	@echo "\t---CHECKING LIBRARY---"
	@make -C libft
	@echo "$(OK_COLOR)\t---LIBRARY UP TO DATE---$(NO_COLOR)"

relib:
	@echo "\t---CHECKING LIBRARY---"
	@make re -C libft
	@echo "$(OK_COLOR)\t---LIBRARY UP TO DATE---$(NO_COLOR)"
