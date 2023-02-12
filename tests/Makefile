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

SHELL = /bin/sh

CC ?= gcc
CFLAGS += -Wall -Wextra -Werror

INC_FLAGS :=
LDFLAGS := -lunit -L..

NAME   ?= test_exec

BUILD_DIR ?= ./build
SRC_DIRS ?= .

SRCS := $(shell find $(SRC_DIRS) -name '*.c')
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

INC_DIRS := ../includes
INC_DIRS += ../libft
INC_FLAGS += $(addprefix -I,$(INC_DIRS))

LIB = ../libunit.a

test: $(NAME)
	@./$(NAME)

$(BUILD_DIR)/%.c.o: %.c
	@echo Compiling $@
	@mkdir -p $(dir $@)
	@$(CC) -c  $(CFLAGS) $(INC_FLAGS) $< -o $@

$(NAME): $(LIBFT) $(OBJS)
	@echo Linking $@
	@$(CC) $(CFLAGS) $(INC_FLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)


$(LIB):
	@$(MAKE) -C ..

clean:
	@rm -rf $(BUILD_DIR)
	@echo Clean done

fclean: clean
	@$(RM) $(NAME)

re: fclean test

.PHONY: all clean fclean re test
