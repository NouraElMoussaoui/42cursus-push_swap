# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 09:58:27 by nel-mous          #+#    #+#              #
#    Updated: 2023/03/17 09:03:43 by nel-mous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=  ft_atoi.c ft_isdigit.c ft_putstr.c ft_strcmp.c ft_strjoin.c ft_strlen.c ft_substr.c ft_strdup.c ft_split.c ft_lstadd_back.c ft_lstnew.c ft_lstsize.c get_next_line.c

OBJS	=$(SRCS:.c=.o)

NAME	=libft.a 

CC	=gcc

CFLAGS	=-Wall -Werror -Wextra 

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)
	ranlib $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re