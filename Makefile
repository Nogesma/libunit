# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivautrav <ivautrav@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/12 12:07:41 by msegrans          #+#    #+#              #
#    Updated: 2023/02/11 19:07:01 by ivautrav         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
CC     = gcc $(CFLAGS)
OBJ    = libunit.o utils.o
LIB    = libft/libft.a
NAME   = libunit.a
TEST   = test
REAL   = real_test

INC_FLAGS = -I. -Ilibft
BUILD_DIR ?= ./build
SRC_DIRS ?= ./tests
REAL_DIRS ?= ./real-tests

SRCS := $(shell find $(SRC_DIRS) -name '*.c')
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

SRCS_REAL := $(shell find $(REAL_DIRS) -name '*.c')
OBJS_REAL := $(SRCS_REAL:%=$(BUILD_DIR)/%.o)

$(BUILD_DIR)/%.c.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) -c  $(CFLAGS) $(INC_FLAGS) $< -o $@

.c.o:
	@$(CC) -Ilibft -c $< -o $@

$(NAME): $(LIB) $(OBJ)
	@$(AR) qcs $(NAME) libft/*.o $(OBJ)

all: $(NAME)

$(TEST): $(NAME) $(OBJS)
	@$(CC) $(CFLAGS) $(INC_FLAGS) $(OBJS) $(NAME) -o $(TEST)

tests: $(TEST)
	@./$(TEST)

$(REAL): $(NAME) $(OBJS_REAL)
	@$(CC) $(CFLAGS) $(INC_FLAGS) $(OBJS_REAL) $(NAME) -o $(REAL)

real-tests: $(REAL)
	@./$(REAL)

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
