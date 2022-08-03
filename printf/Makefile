# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atoullel <atoullel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/02 17:43:56 by fmonbeig          #+#    #+#              #
#    Updated: 2021/12/21 19:03:16 by atoullel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =          libftprintf.a

CC =            gcc

CFLAG =         -Wall -Wextra -Werror

LIBFT_PATH =    libft/

INCLUDE_PATH =  include/

LIBFT_LIB =     libft.a

SRC =   ft_printf.c\
        ft_putunnbr_len.c\
        ft_putchar_len.c\
        ft_putstr_len.c\
        ft_putnbr_len.c\
        ft_putpointer.c\
		ft_s_output.c\
		ft_printhex.c\
          
SRC_OBJ =           $(SRC:.c=.o)

LIBFT_OBJ=		${LIBFT_PATH}*.o

LIBFTMAKE=		$(MAKE) -C ${LIBFT_PATH}
	
all: $(NAME)

$(NAME): $(SRC_OBJ) lmake
	ar rcs $(NAME) $(SRC_OBJ) ${LIBFT_OBJ}

lmake:
		$(LIBFTMAKE)

clean:
				make -C ${LIBFT_PATH} clean
				${RM} ${SRC_OBJ}

fclean: 		clean
				rm -f ${NAME} ${LIBFT_PATH}${LIBFT_LIB}

re:         	fclean all

.PHONY:        all clean fclean re lmake