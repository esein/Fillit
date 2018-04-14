# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/13 18:05:30 by gcadiou           #+#    #+#              #
#    Updated: 2016/12/13 18:11:52 by gcadiou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = 		main.c \
			ft_checktetri.c \
			ft_have_place.c \
			ft_back.c \

all: $(NAME)

OBJ = $(SRC:.c=.o)

$(NAME):
	gcc -c -Wall -Werror -Wextra $(SRC) -I includes/
	gcc -o $(NAME) -I Includes/ $(OBJ)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

