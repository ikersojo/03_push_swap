# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/20 16:19:35 by isojo-go          #+#    #+#              #
#    Updated: 2022/11/22 19:22:44 by isojo-go         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Key variable and files definitions:

NAME		=	push_swap
MAIN		=	ft_push_swap.c
LIBFT		=	libft/libft.a
INC			=	inc/
SRC_DIR		=	src/

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

SRC_FILES	=	ft_push.c ft_swap.c ft_rotate.c ft_rev_rotate.c ft_sort.c \
				ft_sort_5.c ft_sort_2_3.c ft_visualize.c ft_smart_rotate.c \
				ft_sort_big.c ft_input_to_args.c ft_sort_big_cost.c

BONUS		=	bonus/ft_checker_bonus.c bonus/ft_checks_bonus.c

SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ			= 	$(SRC:.c=.o)
OBJ_B		= 	$(BONUS:.c=.o)

#Colors:

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;31m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

# **************************************************************************** #

all:		$(NAME)

$(NAME):	$(LIBFT) $(OBJ)
			@$(CC) $(FLAGS) $(MAIN) $(OBJ) $(LIBFT) -I$(INC) -o $(NAME)
			@echo "$(GREEN)push_swap compiled!$(DEF_COLOR)"

$(LIBFT):
			@make -C ./libft

bonus:		$(LIBFT) $(OBJ) $(OBJ_B)
			@$(CC) $(FLAGS) $(OBJ) $(OBJ_B) $(LIBFT) -I$(INC) -o checker
			@echo "$(GREEN)makchecker compiled!$(DEF_COLOR)"

print:		$(LIBFT) $(OBJ)
			@$(CC) $(FLAGS) $(MAIN) -D PR=1 $(OBJ) $(LIBFT) -I$(INC) -o $(NAME)
			@echo "$(GREEN)push_swap compiled!$(DEF_COLOR)"
.c.o:
			@echo "$(BLUE)Compiling: $< $(DEF_COLOR)"
			@$(CC) $(FLAGS) -I$(INC) -c $< -o $(<:.c=.o)

clean:
			@$(RM) $(OBJ) $(OBJ_B) 
			@echo "$(YELLOW)$(OBJ) file removed.$(DEF_COLOR)"
			@make clean -C ./libft

fclean:		clean
			@make fclean -C ./libft
			@$(RM) $(NAME) checker
			@echo "$(RED)$(NAME) removed!$(DEF_COLOR)"

re:			fclean all

.PHONY:		all clean fclean re libft print bonus