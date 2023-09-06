# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmigoya- <jmigoya-@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/06 17:23:11 by jmigoya-          #+#    #+#              #
#    Updated: 2023/09/06 19:09:46 by migmanu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = push_swap
CC = cc
CFLAGS = -Werror -Wall -Wextra 
HEADER = ./srcs/push_swap.h
LIBFT = ./libft

FILES = push_swap.c stk_utils.c rev_rotate_operations.c \
		swap_operations.c push_operations.c rotate_operations.c \
		test_functions.c control_args.c create_stack.c simulate.c\
		simulate_utils.c
FILES_PATH = ./srcs/

SRCS = $(addprefix $(FILES_PATH), $(FILES))

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	cp libft/libft.a .
	mv libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

clean :
	rm -f $(OBJS)
	make clean -C $(LIBFT)

fclean : clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re : fclean all

.PHONY : all clean fclean re
