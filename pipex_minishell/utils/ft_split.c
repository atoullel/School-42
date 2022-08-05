/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoullel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 18:46:02 by atoullel          #+#    #+#             */
/*   Updated: 2021/07/07 16:22:37 by atoullel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_ccount(char *str, char c)
{
	int	x;

	x = 0;
	while (str[x] != c && str[x])
		x++;
	return (x);
}

static int	ft_wcount(char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str)
			count++;
		while (*str && *str != c)
			str++;
	}
	return (count);
}

static char	**ft_fill_board(char **board, char const *s, char c, size_t w)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (x < w)
	{
		while (*s == c)
			s++;
		board[x] = (char *)malloc(sizeof(char) * (ft_ccount((char *)s, c) + 1));
		if (board[x] == NULL)
			return (0);
		while (*s != c && *s != '\0')
			board[x][y++] = *s++;
		board[x++][y] = '\0';
		y = 0;
	}
	return (board);
}

char	**ft_split(char const *s, char c)
{
	char		**board;
	size_t		w;

	if (!s)
		return (NULL);
	w = ft_wcount((char *)s, c);
	board = (char **) malloc(sizeof(char *) * (w + 1));
	if (board == NULL)
		return (NULL);
	board[w] = NULL;
	board = ft_fill_board(board, s, c, w);
	return (board);
}
