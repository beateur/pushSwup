# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alamorth <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/06 10:05:36 by alamorth          #+#    #+#              #
#    Updated: 2021/10/06 10:05:42 by alamorth         ###   ########.fr        #
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
	 ft_strdup.c\
	 ft_strjoin.c\
	 ft_free_array.c\
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
