# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isojo-go <isojo-go@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/20 16:19:35 by isojo-go          #+#    #+#              #
#    Updated: 2022/10/04 10:14:01 by isojo-go         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Key variable and files definitions:

NAME = libftprintf.a
LIBFT = libft/libft.a

CC = gcc
CCFLAGS = -Wall -Wextra -Werror

AR = ar rc
RM = rm -f

SRC =	ft_printf.c
OBJ = 	$(SRC:.c=.o)

INCLUDE = ft_printf.h

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

all:		$(LIBFT) $(NAME)

$(NAME):	$(OBJ)
			@cp $(LIBFT) $(NAME)
			@$(AR) $(NAME) $(OBJ)
			@echo "$(GREEN)libftprintf compiled!$(DEF_COLOR)"

$(LIBFT):
			@make -C ./libft

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