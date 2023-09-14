# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmigoya- <jmigoya-@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/06 17:23:11 by jmigoya-          #+#    #+#              #
#    Updated: 2023/09/14 13:08:48 by migmanu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = push_swap
CC = cc
CFLAGS = -Werror -Wall -Wextra 
HEADER = ./srcs/push_swap.h
LIBFT = ./libft

FILES = push_swap.c run_push_swap.c stk_utils.c swap_operations.c \
		push_operations.c rotation_operations.c utils.c push_to_stk_a.c \
		control_args.c create_stack.c simulate.c solve_three.c\
		simulate_utils.c cleaning.c sync_rotations.c unsync_rotations.c \

FILES_PATH = ./srcs/

SRCS = $(addprefix $(FILES_PATH), $(FILES))

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	cp libft/libft.a .
	mv libft.a $(NAME)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT) -lft

clean :
	rm -f $(OBJS)
	make clean -C $(LIBFT)

fclean : clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re : fclean all

.PHONY : all clean fclean re
