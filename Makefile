# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mskeleto <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/07 17:53:35 by mskeleto          #+#    #+#              #
#    Updated: 2021/10/07 21:17:11 by mskeleto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker

INC = ps.h

DEFS = 		main.c \
            parser.c \
            preparser.c \
            push.c \
            push_swap.c \
            push_swap_utils.c \
            radix_sort.c \
            reverse_rotate.c \
            rotate.c \
            small_sort.c \
            swap.c
BONUS_DEFS = bonus/get_next_line.c \
             bonus/get_next_line_utils.c \
             bonus/main_bonus.c \
             bonus/parser_bonus.c \
             bonus/preparser_bonus.c \
             bonus/push_bonus.c \
             bonus/push_swap_bonus.c \
             bonus/reverse_rotate_bonus.c \
             bonus/rotate_bonus.c \
             bonus/swap_bonus.c \

OBJS = $(DEFS:.c=.o)
BONUS_OBJ = $(BONUS_DEFS:.c=.o)

all: $(NAME)

%.o: %.c $(INC)
	gcc -Wall -Werror -Wextra -c $< -o $@

$(NAME): $(OBJS) $(INC)
	gcc -Wall -Werror -Wextra $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

bonus: $(BONUS_OBJ) $(INC)
	gcc -Wall -Werror -Wextra $(BONUS_OBJ) -o $(BONUS_NAME)

re: fclean all
