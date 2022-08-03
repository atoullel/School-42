/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoullel <atoullel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:50:03 by atoullel          #+#    #+#             */
/*   Updated: 2021/12/21 12:50:03 by atoullel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include "libft.h"
# include <stdio.h>

# ifdef __APPLE__
#  define PTR_NULL "0x0"
# else
#  define PTR_NULL "(nil)"
# endif

int		ft_printf(const char *format, ...);
int		ft_putunnbr_len(unsigned int nb);
int		ft_putchar_len(char c);
int		ft_putstr_len(char *s);
int		ft_putnbr_len(int n);
int		ft_putpointer(void *p);
int		ft_s_output(char *s);
int		ft_printhex(char c, unsigned int x);

#endif //PRINTF_H