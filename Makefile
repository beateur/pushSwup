#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fberger <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 17:33:34 by fberger           #+#    #+#              #
#    Updated: 2019/03/07 06:51:11 by bihattay         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC				= gcc
RM				= rm -f
CFLAGS		= -Wall -Wextra -Werror
LIBFT			= libft/libft.a
NAME			= push_swap
SRCS			= sources/fill_piles.c\
						sources/main.c\
						sources/piles_utils.c\
						sources/push.c\
						sources/rotations.c\
						sources/sorting.c\
						sources/swap_a.c\
						sources/free.c\
						sources/parse.c

OBJS			= $(SRCS:.c=.o)

all:			$(LIBFT) $(NAME)

$(NAME):	 $(OBJS)
		gcc ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT}

$(LIBFT):
		@$(MAKE) -C libft

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY:			all clean fclean re
