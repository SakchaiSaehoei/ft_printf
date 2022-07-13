# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssaehoei <ssaehoei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/04 23:44:15 by ssaehoei          #+#    #+#              #
#    Updated: 2022/07/14 03:36:48 by ssaehoei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror

NAME = ft_printf.a

SRCS = ft_printf.c ft_put_ptr.c ft_put_unsigned_int_nbr.c ft_put.c ft_puthex.c

SRC_DIR = ./srcs

INCLUDE_DIR = ./includes

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)


$(NAME) : $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o: $(SRC_DIR)/%.c
	gcc $(FLAGS)  -I $(INCLUDE_DIR) -c $< -o $@


clean:
	rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean re fcleans
