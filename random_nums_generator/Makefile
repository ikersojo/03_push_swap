# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/20 16:19:35 by isojo-go          #+#    #+#              #
#    Updated: 2022/11/16 19:28:54 by isojo-go         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Key variable and files definitions:

NAME		=	random_nums
MAIN		=	random_nums.c
LIBFT		=	../libft/libft.a

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

#Colors:

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

# **************************************************************************** #

all:		$(NAME)

$(NAME):	$(LIBFT)
			@$(CC) $(FLAGS) $(MAIN) $(LIBFT) -o $(NAME)
			@echo "$(GREEN)random_nums compiled!$(DEF_COLOR)"

$(LIBFT):
			@make -C ../libft

fclean:		
			@make fclean -C ../libft
			@$(RM) $(NAME)
			@echo "$(RED)$(NAME) removed!$(DEF_COLOR)"

re:			fclean all

.PHONY:		all fclean re libft