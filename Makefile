# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: keokim <keokim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/23 21:45:09 by keokim            #+#    #+#              #
#    Updated: 2022/08/24 03:12:23 by keokim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bitmap
CC = gcc
FLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I$(HEADERS_DIRECTORY)

HEADERS_LIST = bitmap.h
HEADERS_DIRECTORY = ./includes/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

SOURCES_DIRECTORY = ./sources/
SOURCES_LIST =	main.c\
				mapfile.c\
				inversion.c
SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

OBJECTS_DIRECTORY = ./objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS = $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

RED = \033[0;31m
BLUE = \033[0;34m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJECTS_DIRECTORY) $(OBJECTS)
	@$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS) -o $(NAME)
	@echo "\n$(BLUE)$(NAME) : object files created$(RESET)"
	@echo "$(BLUE)$(NAME) : $(NAME) created$(RESET)"

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "$(BLUE)$(NAME) : $(OBJECTS_DIRECTORY) created$(RESET)"

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(BLUE).$(RESET)\c"

clean:
	@rm -f output.bmp
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo "$(RED)$(NAME) : $(OBJECTS_DIRECTORY) deleted$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)$(NAME) : $(NAME) deleted$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re