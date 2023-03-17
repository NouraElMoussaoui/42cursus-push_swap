# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/11 10:21:28 by nel-mous          #+#    #+#              #
#    Updated: 2023/03/17 09:31:28 by nel-mous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= main.c utils.c instructions.c sorting.c parsing.c push_swap.c

SRCS_BONUS = checker_bonus.c instructions2_bonus.c instructions_bonus.c utils_bonus.c parsing_bonus.c main_bonus.c

OBJS	= $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

NAME	= Small_libft/libft.a

NAME_P	= push_swap

NAME_B  = checker

CC 		= cc 

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f 

%.o: %.c push_swap.h checker.h
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME_P)

bonus: $(NAME_B)

$(NAME_P): $(OBJS) $(NAME) 
	$(CC) $(CFLAGS) $(OBJS) $(NAME) -o $@
	
$(NAME_B): $(OBJS_BONUS) $(NAME) 
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(NAME) -o $@

$(NAME):
	make -sC Small_libft all

clean:
	make -sC Small_libft fclean
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME_P)
	$(RM) $(NAME_B)

re: fclean all bonus

