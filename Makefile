# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/01 12:55:30 by belinore          #+#    #+#              #
#    Updated: 2025/02/04 13:03:06 by belinore         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

HDR = push_swap.h

SRC = main.c add_args_to_stack.c general_utils.c list_utils.c ft_split.c \
	  operations_push.c operations_rotate_fwd.c operations_rotate_rev.c \
	  operations_swap.c sorting_algorithm.c sorting_calculation.c sorting_utils.c

OBJS := $(SRC:%.c=%.o)

CC = cc -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) -I. -o $@ -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all


.PHONY: all clean fclean re
