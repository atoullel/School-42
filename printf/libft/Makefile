# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atoullel <atoullel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/14 18:06:25 by atoullel          #+#    #+#              #
#    Updated: 2021/12/21 13:39:09 by atoullel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

SRC = ft_atoi.c\
      ft_bzero.c\
      ft_calloc.c\
      ft_isalnum.c\
      ft_isalpha.c\
      ft_isascii.c\
      ft_isdigit.c\
      ft_isprint.c\
      ft_itoa.c\
      ft_memccpy.c\
      ft_memchr.c\
      ft_memcmp.c\
      ft_memcpy.c\
      ft_memmove.c\
      ft_memset.c\
      ft_putchar_fd.c\
      ft_putendl_fd.c\
      ft_putnbr_fd.c\
      ft_putstr_fd.c\
      ft_split.c\
      ft_strchr.c\
      ft_strdup.c\
      ft_strjoin.c\
      ft_strlcat.c\
      ft_strlcpy.c\
      ft_strlen.c\
      ft_strmapi.c\
      ft_strncmp.c\
      ft_strnstr.c\
      ft_strrchr.c\
      ft_strtrim.c\
      ft_substr.c\
      ft_tolower.c\
      ft_toupper.c\
      ft_striteri.c\
      ft_str_reverse.c\
      ft_str_toupper.c\
      ft_itoh.c\

SRC_BONUS = ft_lstnew.c\
	    ft_lstadd_front.c\
	    ft_lstsize.c\
	    ft_lstlast.c\
	    ft_lstadd_back.c\
	    ft_lstdelone.c\
	    ft_lstclear.c\
	    ft_lstiter.c\
	    ft_lstmap.c\

		   
OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(OBJ) $(SRC_BONUS:.c=.o)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)
	@ranlib $(NAME)

bonus: $(OBJ_BONUS)
	$(AR) $(NAME) $(OBJ_BONUS)
	@ranlib $(NAME)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I includes -o $@ -c $<

clean:
	@rm -rf $(OBJ_BONUS) $(OBJ_NAME)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: re clean fclean all