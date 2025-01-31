# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabrielsobral <gabrielsobral@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/31 12:42:13 by gabrielsobr       #+#    #+#              #
#    Updated: 2025/01/31 12:46:25 by gabrielsobr      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC_DIR = src
SRCS = forks.c init.c philosophers.c utils.c threads.c philosophers_utils.c validation.c
SRC = $(addprefix $(SRC_DIR)/, $(SRCS))
OBJ = $(SRC:.c=.o)
HEADER = include

CC = cc

CFLAGS = -Wall -Werror -Wextra -I$(HEADER) -g 
all: $(NAME)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@echo "Compiling $(NAME)"
	@$(CC) $(CFLAGS) $(SRC_DIR)/main.c $(OBJ) -pthread -o $(NAME)

leak: $(NAME)
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 2>&1 | \
	grep -i "no leaks are possible" > /dev/null && echo "Everything is OK." || echo "Leak found!!!"

clean:
	@echo "Objects removed."
	@rm -f $(OBJ)

fclean: clean
	@echo "$(NAME) removed."
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re