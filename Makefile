# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/19 19:18:24 by yadereve          #+#    #+#              #
#    Updated: 2024/01/19 11:33:36 by yadereve         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

CC = cc

EXECUTABLE = push_swap

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

GREEN = \033[1;32m
RED = \033[1;31m
RESET = \033[0;0m

SRCS = comands.c \
		create_stack.c \
		freestack.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_miniprintf.c \
		ft_strtolong.c \
		mini_sort.c \
		operation_rotate1.c \
		operation_rotate2.c \
		operation_swap.c \
		operations_push.c \
		optimization.c \
		parcing_utils.c \
		parsing.c \
		perform_sort.c \
		push_swap.c \
		rotation.c \
		size_stack.c \
		sorted.c \
		utiliti2.c \
		utility1.c \

OBJ_DIR = objects

OBJ = $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
		@ar rcs $@ $(OBJ)
		@echo "$(GREEN)$(OBJ_DIR)$(RESET) is created"
		@echo "Library $(GREEN)$@$(RESET) is created."
		@$(CC) $(CFLAGS) $(OBJ) -o $(EXECUTABLE)
		@echo "Executable $(GREEN)$(EXECUTABLE)$(RESET) is created."

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c
		@$(CC) $(CFLAGS) -c $< -o $@

clean:
		@$(RM) -r $(OBJ_DIR)
		@echo "$(RED)$(OBJ_DIR)$(RESET) are removed."

fclean:	clean
		@$(RM) $(NAME)
		@$(RM) $(EXECUTABLE)
		@echo "$(RED)$(NAME)$(RESET) and $(RED)$(EXECUTABLE)$(RESET) are removed."

re:		fclean all

.PHONY: all clean fclean re
