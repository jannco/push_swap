# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/19 19:18:24 by yadereve          #+#    #+#              #
#    Updated: 2024/02/20 09:00:27 by yadereve         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
CC = cc
EXECUTABLE = push_swap
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

# Colors
GREEN = \033[1;32m
RED = \033[1;31m
BBLUE = \033[1;34m
ORANGE = \033[0;33m
RESET = \033[0;0m

SRCS = freestack.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_miniprintf.c \
		ft_str_to_long.c \
		functions.c \
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
		utiliti2.c \
		utility1.c \

OBJ_DIR = objects

OBJ = $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

# Test
BUFF = buff
PBPAST = $(shell cat $(BUFF))
NUM = $(if $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS)),$(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS)),5)
COMMAND_MAC = $(shell jot -r -n $(NUM) -999999 999999 > $(BUFF))
COMMAND_LINUX = $(shell seq -999999 999999 | shuf -n $(NUM) > $(BUFF))
RUN = ./$(EXECUTABLE) $(PBPAST)
CHECKER = ./checker_linux $(PBPAST)
CHECKER_MAC = ./checker_mac $(PBPAST)

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@ar rcs $@ $(OBJ)
	@echo "Directory $(GREEN)$(OBJ_DIR)$(RESET) is created"
	@echo "Library $(GREEN)$@$(RESET) is created."
	@$(CC) $(CFLAGS) $(OBJ) -o $(EXECUTABLE)
	@echo "Executable $(GREEN)$(EXECUTABLE)$(RESET) is created."
	@echo "\n---- Type: % ./push_swap 2 1 3 6 5 8"
	@echo "---- Type: % make test 500"

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
	@echo "$(BBLUE)./$(EXECUTABLE)$(RESET)" $(PBPAST)
	@$(RUN)
	@echo "$(ORANGE)Number of operations:$(RESET)" `$(RUN) | wc -l`
	@echo "$(ORANGE)Checker:$(RESET)" `$(RUN) | $(CHECKER)`
	@$(RM) $(BUFF)

test_mac:
	@$(COMMAND_MAC)
	@echo "$(BBLUE)./$(EXECUTABLE)$(RESET)" $(PBPAST)
	@$(RUN)
	@echo "$(ORANGE)Number of operations:$(RESET)" `$(RUN) | wc -l`
	@echo "$(ORANGE)Checker:$(RESET)" `$(RUN) | $(CHECKER_MAC)`
	@$(RM) $(BUFF)

test_all:
	curl https://raw.githubusercontent.com/hu8813/tester_push_swap/main/pstester.py | python3 -

git:
	git add .
	git commit -m "done"
	git push

%:
	@true

.PHONY: all clean fclean re test_all
