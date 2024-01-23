# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/19 19:18:24 by yadereve          #+#    #+#              #
#    Updated: 2024/01/23 08:09:38 by yadereve         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

CC = cc

EXECUTABLE = push_swap

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

GREEN = \033[1;32m
RED = \033[1;31m
BACK_RED = \033[0;41m
BBLUE = \033[1;34m
ORANGE = \033[0;33m
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

# Test
BUFF = buff
PBPAST = $(shell cat $(BUFF))
NUM = $(if $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS)),$(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS)),5)
COMMAND_MAC = $(shell jot -r -n $(NUM) 0 999999 > $(BUFF))
COMMAND_LINUX = $(shell shuf -i 0-999999 -n $(NUM) > $(BUFF))
RUN = ./push_swap $(PBPAST)

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
		@ar rcs $@ $(OBJ)
		@echo "Directory $(GREEN)$(OBJ_DIR)$(RESET) is created"
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
		@echo "$(RED)$(NAME)$(RESET) are removed."
		@echo "$(RED)$(EXECUTABLE)$(RESET) are removed."

re:		fclean all

test:
		@$(COMMAND_LINUX)
		@echo "$(BBLUE)./push_swap$(RESET)" $(PBPAST)
		@$(RUN)
		@printf "\n$(ORANGE)Number of operations:$(BACK_RED) %s \n$(RESET)" `$(RUN) | wc -l`
		@$(RM) $(BUFF)

test_mac:
		@$(COMMAND_MAC)
		@echo "$(BBLUE)./push_swap$(RESET)" $(PBPAST)
		@$(RUN)
		@printf "\n$(ORANGE)Number of operations:$(BACK_RED) %s \n$(RESET)" `$(RUN) | wc -l`
		@$(RM) $(BUFF)

test_all:
		@curl https://git.homegu.com/raw/hu8813/tester_push_swap/main/pstester.py | python3 -

%::
		@true

.PHONY: all clean fclean re test
