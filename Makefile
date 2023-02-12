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
LDFLAGS :=

NAME   ?= libunit.a
LIBFT    = libft/libft.o

BUILD_DIR ?= ./build
SRC_DIRS ?= ./src
INCLUDE_DIR ?= ./includes

SRCS := $(shell find $(SRC_DIRS) -name '*.c')
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

INC_DIRS := $(shell find $(INCLUDE_DIR) -type d)
INC_DIRS += libft
INC_FLAGS += $(addprefix -I,$(INC_DIRS))

$(BUILD_DIR)/%.c.o: %.c
	@echo Compiling $@
	@mkdir -p $(dir $@)
	@$(CC) -c  $(CFLAGS) $(INC_FLAGS) $< -o $@

$(NAME): $(LIBFT) $(OBJS)
	@echo Linking $@
	@$(CC) -r -nostdlib $(CFLAGS) $(OBJS) -o $(BUILD_DIR)/libunit.o
	@$(AR) qcs $(NAME) $(LIBFT) $(BUILD_DIR)/libunit.o

all: $(NAME)


$(LIBFT):
	@$(MAKE) -C libft bonus

clean:
	@rm -rf $(BUILD_DIR)
	@$(MAKE) -C libft clean
	@echo Clean done

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re
