#!/bin/sh

# CC = gcc
# CFLAGS = -Wall -Wextra -Werror
# SOURCE = cd.c cd_2.c cd_3.c change_pwd.c echo.c echo_2.c check_command_in_bin.c check_command_in_bin_2.c get_next_line.c minishell.c my_splits.c other_features_2.c other_features.c parsing.c parse_and_exec.c read_line_words.c setenv.c unsetenv.c
# OBJECTS = $(SOURCE:.c=.o)
# NAME = minishell.a

# all: $(NAME)

# $(NAME):
# 	$(CC)  $(CFLAGS) -c $(SOURCE)
# 	ar rc $(NAME) *.o
# 	ranlib $(NAME)

# clean:
# 	rm -rf $(OBJECTS)

# fclean: clean
# 	rm -rf $(NAME)

# re: clean all

NAME    = minishell

SRC        =    cd.c cd_2.c cd_3.c change_pwd.c echo.c echo_2.c check_command_in_bin.c check_command_in_bin_2.c get_next_line.c minishell.c my_splits.c other_features_2.c other_features.c parsing.c parse_and_exec.c read_line_words.c setenv.c unsetenv.c

OBJ        = $(SRC:.c=.o)

CFLAGS    = -Wall -Wextra -Werror

$(NAME): $(OBJ)
	@make -C libft/
	@gcc $(OBJ) -o $(NAME) -L libft/ -lft

all: $(NAME)

clean:
	@make -C libft/ clean
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME) $(OBJ)

re:	fclean $(NAME)
