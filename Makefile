# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bihattay <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/06 10:07:33 by bihattay          #+#    #+#              #
#    Updated: 2021/10/06 10:09:56 by bihattay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
						sources/find_elem_in_range.c\
						sources/quicksort.c\
						sources/low_cases.c\
						sources/errors.c\
						sources/parse.c

OBJS			= $(SRCS:.c=.o)

all:		 $(NAME)

$(NAME):		$(LIBFT)  $(OBJS)
		gcc ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT}

$(LIBFT):
		@$(MAKE) -C libft

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY:			all clean fclean re
