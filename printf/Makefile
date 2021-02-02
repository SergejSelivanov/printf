# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Wjena <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/24 16:03:54 by Wjena             #+#    #+#              #
#    Updated: 2020/07/24 16:37:41 by Wjena            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SOURCES = ft_printf.c\
		  ft_libft_functions3.c\
		  ft_libft_functions2.c\
		  ft_printf_hex_low.c\
		  ft_printf_hex_up.c\
		  ft_printf_ptr.c\
		  ft_printf_unsigned.c\
		  ft_printf_char.c\
		  ft_printf_nbr.c\
		  ft_printf_str.c\
		  ft_libft_functions.c\
		  ft_choose_prm.c\
		  ft_printf_hex_low1.c\
		  ft_printf_unsigned1.c\
		  ft_printf_nbr1.c\
		  ft_printf_nbr2.c\
		  ft_printf_nbr3.c\
		  ft_printf_str1.c\
		  ft_libft_functions1.c
OBJ = $(SOURCES:.c=.o)
COMPILER = gcc -c -Wall -Werror -Wextra
HEADER = ./libftprintf.h

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c $(HEADER)
	$(COMPILER) $< -o $@

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all

