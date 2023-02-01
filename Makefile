# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saguesse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/07 14:54:21 by saguesse          #+#    #+#              #
#    Updated: 2023/02/01 18:30:52 by saguesse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc -g3
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

SRC_DIR = srcs
SRC_FILES = main.c \
			check_inputs.c \
			creating_threads.c \
			philo.c \
			ft_atoi.c \
			ft_strlen.c \
			ft_lstnew.c \
			ft_lstadd_back.c \
			ft_lstlast.c \
			ft_lstclear.c
SRC = $(SRC_FILES:%=$(SRC_DIR)/%)

OBJ_DIR = objs
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean
	make all

.PHONY: all clean fclean re