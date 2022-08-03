/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoullel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 13:35:51 by atoullel          #+#    #+#             */
/*   Updated: 2021/12/12 14:54:10 by atoullel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
		x++;
	return (x);
}

char	*ft_strchr(const char *s, int c)
{
	int	x;

	x = 0;
	if (!s)
		return (NULL);
	while (s[x] != c && s[x])
		x++;
	if (s[x] == c)
		return ((char *)s + x);
	return (NULL);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	if (!(dest || src))
		return (0);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	x;
	char	*str;

	if (!(s1 && s2))
		return (NULL);
	x = ft_strlen(s1) + ft_strlen(s2);
	str = (char *) malloc(sizeof(char) * (x + 1));
	if (str == NULL)
		return (NULL);
	x = 0;
	while (*s1)
		str[x++] = *s1++;
	while (*s2)
		str[x++] = *s2++;
	str[x] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	y;
	char	*substr;

	y = 0;
	if (!(s))
		return (NULL);
	if (ft_strlen(s) > start)
	{
		substr = (char *)malloc(sizeof(char) * (len + 1));
		if (substr == NULL)
			return (NULL);
		while (s[start] && y < len)
			substr[y++] = s[start++];
	}
	else
		substr = (char *)malloc(sizeof(char));
	substr[y] = '\0';
	return (substr);
}
