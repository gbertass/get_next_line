/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    get_next_line_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertass <gbertass@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:01:57 by gbertass          #+#    #+#             */
/*   Updated: 2023/08/10 18:08:58 by gbertass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	j;

	j = 0;
	if (size > 0)
	{
		while (src[j] != '\0' && j < size - 1)
		{
			dst[j] = src[j];
			j++;
		}
		dst[j] = '\0';
	}
	while (src[j] != '\0')
	{
		j++;
	}
	return (j);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*ss1;
	char	*ss2;
	char	*end;

	i = 0;
	j = 0;
	ss1 = (char *) s1;
	ss2 = (char *) s2;
	end = (char *) malloc(sizeof(char) * (ft_strlen(ss1) + ft_strlen(ss2) + 1));
	if (end == NULL)
		return (NULL);
	while (ss1[i] != '\0')
	{	
		end[i] = ss1[i];
		i++;
	}
	while (ss2[j] != '\0')
	{
		end[i + j] = ss2[j];
		j++;
	}
	end[i + j] = '\0';
	return (end);
}

char	*ft_strchr(const char *s, int c)
{	
	unsigned int	i;
	const char		*str;

	str = s;
	i = 0;
	while (str[i] != '\0')
	{
		if ((unsigned char)str[i] == (unsigned char)c)
			return ((char *)str + i);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)str + i);
	return (NULL);
}