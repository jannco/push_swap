# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/19 19:18:24 by yadereve          #+#    #+#              #
#    Updated: 2024/03/05 20:01:15 by yadereve         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECKER = checker
CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -g
SRC_DIR = sources
OBJ_DIR = objects

SRC = freestack.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_miniprintf.c \
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
		utility1.c \
		utility2.c \

CHECKER_SRC = freestack.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_miniprintf.c \
		functions.c \
		operation_rotate1.c \
		operation_rotate2.c \
		operation_swap.c \
		operations_push.c \
		parcing_utils.c \
		parsing.c \
		get_next_line_utils.c \
		get_next_line.c \
		checker_moves.c \
		checker_main.c \

SRCS = $(addprefix $(SRC_DIR)/, $(SRC))
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
CHECKER_SRCS = $(addprefix $(SRC_DIR)/, $(CHECKER_SRC))
CHECKER_OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(CHECKER_SRCS))

# Colors
GREEN = \033[1;32m
RED = \033[1;31m
BLUE = \033[1;34m
ORANGE = \033[0;33m
RESET = \033[0;0m

# Tests
BUFF = buff
PBPAST = $(shell cat $(BUFF))
NUM = $(if $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS)),$(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS)),5)
COMMAND_MAC = $(shell jot -r -n $(NUM) -999999 999999 > $(BUFF))
COMMAND_LINUX = $(shell seq -999999 999999 | shuf -n $(NUM) > $(BUFF))
RUN = ./$(NAME) $(PBPAST)
CHECKER_LINUX = ./checker_linux $(PBPAST)
CHECKER_MAC = ./checker_mac $(PBPAST)

all: $(NAME) $(CHECKER)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(BLUE)                    __"
	@echo ".-----.--.--.-----.|  |--.    .-----.--.--.--.---.-.-----."
	@echo "|  _  |  |  |__ --||     |    |__ --|  |  |  |  _  |  _  |"
	@echo "|   __|_____|_____||__|__|____|_____|________|___._|   __|"
	@echo "|__|                    |______|                   |__|$(RESET)"
	@echo "\ncreate:\t$(GREEN)$(OBJ_DIR)\n\t$@$(RESET)"
	@echo "\t$(GREEN)$(CHECKER)$(RESET)"
	@echo "\n  Type:\t% ./push_swap 2 1 3 6 5 8"
	@echo "\t% ARG=\"4 67 3 87 23\"; ./push_swap \$$ARG | ./checker \$$ARG"
	@echo "\t% make test 500"

$(CHECKER): $(CHECKER_OBJS)
	@$(CC) $(CFLAGS) $(CHECKER_OBJS) -o $(CHECKER)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@$(RM) $(OBJ_DIR)
	@echo "removed: $(RED)$(OBJ_DIR)$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "\t $(RED)$(NAME)$(RESET)"

clean_checker:
	@$(RM) $(CHECKER)
	@echo "removed: $(RED)$(CHECKER)$(RESET)"

re: fclean all

test:
	@$(COMMAND_LINUX)
	@echo "$(BLUE)./$(NAME)$(RESET)" $(PBPAST)
	@$(RUN)
	@echo "$(ORANGE)Number of operations:$(RESET)" `$(RUN) | wc -l`
	@echo "$(ORANGE)Checker:$(RESET)" `$(RUN) | $(CHECKER_LINUX)`
	@$(RM) $(BUFF)

test_mac:
	@$(COMMAND_MAC)
	@echo "$(BLUE)./$(NAME)$(RESET)" $(PBPAST)
	@$(RUN)
	@echo "$(ORANGE)Number of operations:$(RESET)" `$(RUN) | wc -l`
	@echo "$(ORANGE)Checker:$(RESET)" `$(RUN) | $(CHECKER_MAC)`
	@$(RM) $(BUFF)

test_all:
	@curl https://raw.githubusercontent.com/hu8813/tester_push_swap/main/pstester.py | python3 -
	@echo "\n"
	norminette

%:
	@true

.PHONY: all clean fclean re test_all
