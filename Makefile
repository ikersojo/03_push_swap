# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/20 16:19:35 by isojo-go          #+#    #+#              #
#    Updated: 2022/11/13 19:25:03 by isojo-go         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Key variable and files definitions:

NAME		=	push_swap
LIBFT		=	libft/libft.a
INC_DIR		=	inc/
SRC_DIR		=	src/

CC			=	gcc
CCFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

SRC_FILES	=	ft_push.c ft_swap.c ft_rotate.c ft_rev_rotate.c ft_sort.c \
				ft_sort_5.c ft_sort_2_3.c ft_visualize.c ft_smart_rotate.c \
				ft_sort_big.c

SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ			= 	$(SRC:.c=.o)

INCLUDE = $(addprefix $(INC_DIR), ft_push_swap.h)

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

$(NAME):	$(LIBFT) $(OBJ)
			@$(CC) $(CCFLAGS) ft_push_swap.c $(OBJ) $(LIBFT) -I$(INCLUDE) -o $(NAME) # revisar
			@echo "$(GREEN)push_swap compiled!$(DEF_COLOR)"

$(LIBFT):
			@make -C ./libft

see:		$(LIBFT) $(OBJ)
			@$(CC) $(CCFLAGS) ft_push_swap.c -D PRINT=1 $(OBJ) $(LIBFT) -I$(INCLUDE) -o $(NAME) # revisar
			@echo "$(GREEN)push_swap compiled!$(DEF_COLOR)"
.c.o:
			@echo "$(BLUE)Compiling: $< $(DEF_COLOR)"
			@$(CC) $(CCFLAGS) -I$(INCLUDE) -c $< -o $(<:.c=.o)

clean:
			@$(RM) $(OBJ)
			@echo "$(YELLOW)$(OBJ) file removed.$(DEF_COLOR)"
			@make clean -C ./libft

fclean:		clean
			@make fclean -C ./libft
			@$(RM) $(NAME)
			@echo "$(RED)$(NAME) removed!$(DEF_COLOR)"

re:			fclean all

.PHONY:		all clean fclean re libft