# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csachdev <csachdev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/31 20:01:10 by csachdev          #+#    #+#              #
#    Updated: 2019/07/31 22:12:24 by csachdev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
SRCS = src/*.c
HEADERS_FOLDER = includes
all: default

default: compile

compile:
	gcc -Wall -Werror -Wextra -g -I$(HEADERS_FOLDER) $(SRCS) -o $(NAME)
clean:
	rm $(NAME)
re:
	make clean
	make
