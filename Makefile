# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cguerrei <cguerrei@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/09 17:00:29 by cguerrei          #+#    #+#              #
#    Updated: 2023/05/22 18:27:09 by cguerrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

LIB = ar rcs

SRC = ft_printf.c ft_putstr.c ft_putnbr.c

OBJ = $(SRC:.c=.o)

RM = rm -f

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME): $(OBJ)
		$(LIB) $(NAME) $(OBJ) 

clean:
		$(RM) $(OBJ)

fclean: clean
				$(RM) $(NAME)
re : fclean all

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<
comp:
		$(CC) $(CFLAGS)

.PHONY: all clean fclean re comp
