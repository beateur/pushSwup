# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bihattay <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/29 03:38:43 by bihattay          #+#    #+#              #
#    Updated: 2021/09/29 03:38:47 by bihattay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=libft.a
SRCS=ft_atoi.c\
	 ft_intdel.c\
	 ft_max_in_range.c\
	 ft_isdigit.c\
	 ft_strsplit.c\
	 ft_strlen.c\
	 utils_range.c\
	 ft_doublons_in_range.c

OBJS=$(SRCS:.c=.o)

all: $(NAME)

$(NAME):	 $(OBJS)
	$(CC) $(CFLAGS) -c $(SRCS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
