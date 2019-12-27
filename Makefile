# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/02 13:56:52 by esnowpea          #+#    #+#              #
#    Updated: 2019/12/27 20:30:37 by esnowpea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

CFLAGS = -Wall -Werror -Wextra

LDFLAGS = -L./libft

LDHEAD = ./libft/inc/

LDLIBS = -lft

SRC_NAME = main.c \
		   filling_map.c \
		   filling_map2.c \
		   dancing_links.c \
		   cover_knut.c \
		   read_file.c \
		   check_figure.c \
		   read_file.c \
		   list_f.c \
		   printing_map.c

OBJ = ./obj/

SRC = ./src/

OBJ_NAME = $(SRC_NAME:.c=.o)

HEAD = ./inc/

.PHONY: all clean fclean re

all: create_obj $(NAME)

$(NAME): $(addprefix $(OBJ), $(OBJ_NAME))
	@make -C ./libft
	@$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) $^ -o $@
	@echo "\033[0;32mfillit's program created.\033[0m"

$(OBJ)%.o: $(SRC)%.c
	@$(CC) $(CFLAGS) -I $(HEAD) -I $(LDHEAD) -o $@ -c $<

create_obj:
	@mkdir -p $(OBJ)

clean:
	@rm -rf $(addprefix $(OBJ), $(OBJ_NAME))
	@rm -rf $(OBJ)
	@make -C ./libft clean
	@echo "\033[0;32mfillit's .o files deleted.\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@make -C ./libft fclean
	@echo "\033[0;32mfillit Project fully cleaned.\033[0m"

re: fclean all
