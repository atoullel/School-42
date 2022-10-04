/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoullel <atoullel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:50:24 by atoullel          #+#    #+#             */
/*   Updated: 2021/12/21 12:50:24 by atoullel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

#define MIN(a, b)	((a > b) ? a : b)
#define MAX(a, b)	((a < b) ? a : b)

typedef struct s_info
{
	int		width;
	int		precision;
	int 	preci_bool;
}		t_info;


/* ======================================================== */
/*							UTILITIES						*/
/* ======================================================== */

size_t	ft_strlen(const char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
		x++;
	return (x);
}

int	ft_isdigit(int c)
{
	if (c <= 57 && c >= 48)
		return (1);
	return (0);
}

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	write(1, s, ft_strlen(s));
}

char	*ft_str_reverse(char *str)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*result;

	k = i = ft_strlen(str);
	result = (char *)malloc(sizeof(char) * (i + 1));
	if (!result)
		return (NULL);
	j = 0;
	while (j < k)
		result[j++] = str[--i];
	result[j] = '\0';
	free(str);
	return (result);
}

/* ======================================================== */
/*							STRING							*/
/* ======================================================== */

void	ft_s_output(t_info info, int *total_printed, char *s)
{
	size_t len;
	int x;

	if (!s)
	{
		if (!(info.preci_bool && info.precision >=6))
			info.precision = 0;
		else
			info.precision = 6;
		while (info.width-- > info.precision)
		{
			write(1, " ", 1);
			*total_printed += 1 ;
		}
		if (!(info.preci_bool) || (info.preci_bool && info.precision >=6))
		{
		ft_putstr("(null)");
		*total_printed += 6;
		}
	}
	else
	{
		len = ft_strlen(s);
		if (!(info.preci_bool))
		{
			while (info.width-- > len)
			{
				write(1, " ", 1);
				*total_printed += 1;
			}
			ft_putstr(s);
			*total_printed += len;
		}
		else
		{
			x = MAX(info.precision, len);
			while (info.width-- > x)
			{
				write(1, " ", 1);
				*total_printed += 1;
			}
			while (info.precision-- && *s)
			{
				write(1, s, 1);
				s++;
				*total_printed += 1;
			}
		}
	}
}

/* ======================================================== */
/*							DECIMAL							*/
/* ======================================================== */

char *ft_putnbr(int n)
{
	unsigned int	nb;
	char			*result;
	int 			negative;
	int 			i;

	result = (char *)malloc(sizeof(char) * 20);
	if (!result)
		return (NULL);
	negative = 0;
	if (n == 0)
	{
		result[0] = '0';
		result[1] = '\0';
		return (result);
	}
	if (n < 0)
	{
		nb = -n;
		negative = 1;
	}
	else
		nb = n;
	i = 0;
	while (nb != 0)
	{
		result[i++] = '0' + (nb % 10);
		nb = nb / 10;
	}
	if (negative)
		result[i++] = '-';
	result[i] = '\0';
	return (ft_str_reverse(result));
}

void	ft_printdec(t_info info, int *total_printed, int n)
{
	char *result;
	char *tmp;
	int len;
	int x;
	int negative;

	negative = 0;
	tmp = result = ft_putnbr(n);
	len = ft_strlen(result);
	if (!(info.preci_bool))
	{
		while (info.width-- > len)
		{
			write(1, " ", 1);
			*total_printed += 1;
		}
		ft_putstr(result);
		*total_printed += len;
	}
	else
	{
		if (result[0] == '-')
		{
			negative = 1;
			result++;
			(info.precision)++;
		}
			x = MIN(info.precision, len);
		while (info.width-- > x)
		{
			write(1, " ", 1);
			*total_printed += 1;
		}
		if (negative)
		{
			write(1, "-", 1);
			*total_printed += 1;
		}
		while (info.precision-- > len)
		{
			write(1, "0", 1);
			*total_printed += 1;
		}
		ft_putstr(result);
		*total_printed += ft_strlen(result);
	}
	free(tmp);
}

/* ======================================================== */
/*							HEX								*/
/* ======================================================== */

char	*ft_itoh(unsigned int nb)
{
	unsigned int	quotient;
	unsigned int	remainder;
	char			*result;
	int				x;

	x = 0;
	quotient = nb;
	remainder = 0;
	result = (char *)malloc(sizeof(char) * 20);
	if (!result)
		return (NULL);
	if (nb == 0)
	{
		result[0] = '0';
		result[1] = '\0';
		return (result);
	}
	while (quotient != 0)
	{
		remainder = quotient % 16;
		if (remainder >= 10)
			result[x++] = remainder + 87;
		else
			result[x++] = remainder + 48;
		quotient = quotient / 16;
	}
	result[x] = '\0';
	return (ft_str_reverse(result));
}

void	ft_printhex(t_info info, int *total_printed, unsigned int n)
{
	char *result;
	int len;
	int x;

	result = ft_itoh(n);
	len = ft_strlen(result);
	if (!(info.preci_bool))
	{
		while (info.width-- > len)
		{
			write(1, " ", 1);
			*total_printed += 1;
		}
		ft_putstr(result);
		*total_printed += len;
	}
	else
	{
		x = MIN(info.precision, len);
		while (info.width-- > x)
		{
			write(1, " ", 1);
			*total_printed += 1;
		}
		while (info.precision-- > len)
		{
			write(1, "0", 1);
			*total_printed += 1;
		}
		ft_putstr(result);
		*total_printed += len;
	}
	free(result);
}

/* ======================================================== */
/*						PRINTF								*/
/* ======================================================== */

static int	flags(int *total_printed, char *format, va_list ap)
{
	int i;
	t_info	info;

	info.width = 0;
	info.precision = 0;
	info.preci_bool = 0;
	i = 1;
	while (ft_isdigit(format[i]) && format[i])
		info.width = (info.width * 10) + (format[i++] - 48);
	if (format[i] == '.')
	{
		info.preci_bool = 1;
		i++;
		while (ft_isdigit(format[i]) && format[i])
			info.precision = (info.precision * 10) + (format[i++] - 48);
	}
	if (format[i] == 's')
		ft_s_output(info, total_printed, va_arg(ap, char *));
	else if (format[i] == 'd')
		ft_printdec(info, total_printed, va_arg(ap, int));
	else if (format[i] == 'x')
		ft_printhex(info, total_printed, va_arg(ap, unsigned int));
	else
	{
		if (!(format[i]))
		{
			ft_putstr(format);
			*total_printed += ft_strlen(format);
			return (i);
		}
		else
		{
			write(1, format, (i + 1));
			*total_printed += i + 1;
		}
	}
	return (++i);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	i;
	int		total_printed;
	char *form;

	form = (char *)format;
	i = 0;
	total_printed = 0;
	va_start(ap, format);
	if (!format)
		return (0);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i += flags(&total_printed, &form[i], ap);
		}
		else
		{
			write(1, &format[i], 1);
			total_printed++;
			i++;
		}
	}
	va_end(ap);
	return (total_printed);
}
