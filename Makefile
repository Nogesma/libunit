# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msegrans <msegrans@student.42lausan>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/12 12:07:41 by msegrans          #+#    #+#              #
#    Updated: 2021/10/12 12:07:45 by msegrans         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
CC     = gcc $(CFLAGS)
OBJ    = libunit.o
LIB    = libft/libft.a
NAME   = libunit.a
TEST   = test


INC_FLAGS = -I. -Ilibft
BUILD_DIR ?= ./build
SRC_DIRS ?= ./tests

SRCS := $(shell find $(SRC_DIRS) -name '*.c')
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

$(BUILD_DIR)/%.c.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) -c  $(CFLAGS) $(INC_FLAGS) $< -o $@

.c.o:
	@$(CC) -Ilibft -Llibft -lft -c $< -o $@

$(NAME): $(LIB) $(OBJ)
	@$(AR) qcs $(NAME) libft/*.o $(OBJ)

all: $(NAME)

$(TEST): $(NAME) $(OBJS)
	@$(CC) $(CFLAGS) $(INC_FLAGS) $(OBJS) $(NAME) -o $(TEST)

tests: $(TEST)
	@./$(TEST)

$(LIB):
	@$(MAKE) -C libft bonus

clean:
	@$(RM) $(OBJ)
	@$(MAKE) -C libft clean

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re
