# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saguesse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/07 14:54:21 by saguesse          #+#    #+#              #
#    Updated: 2023/02/10 15:35:16 by saguesse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc -g3
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

INC = -I include
HEADER = include/philo.h

SRC_DIR = srcs
SRC_FILES = main.c \
			check_inputs.c \
			init.c \
			philo.c \
			eating.c \
			print_msg.c \
			time.c
SRC = $(SRC_FILES:%=$(SRC_DIR)/%)

OBJ_DIR = objs
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o) $(HEADER)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(HEADER) $(INC)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean
	make all

.PHONY: all clean fclean re
