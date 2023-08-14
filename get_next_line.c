/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertass <gbertass@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:49:55 by gbertass          #+#    #+#             */
/*   Updated: 2023/08/10 18:00:26 by gbertass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_file(int fd, char *stt)
{
	int	len;
	char	*buff;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	len = 13;
	while (len > 0 && !ft_strchr(stt, '\n'))
	{
		len = read(fd, buff, BUFFER_SIZE);
		if (len < 0)
		{
			free(stt);
			fre (buff);
			return (NULL);
		}
		buff[len] = '\0';
		stt = ft_strjoin(stt, buff);
	}
	free (buff);
	return (stt);
}


static char *read_line(char *stt)
{
	char	*line;
	size_t	n;
	if (!*stt)
		return (NULL);
	n = 0;
	while (stt[n] != '\0' && stt[n] != '\n')
		n++;
	line = (char*) malloc(sizeof(char) * (n + 2));
	if (!line)
		return (NULL);
	ft_strlcpy(line, stt, n + 1);
	if (stt[n] == '\n')
		line[n++] = '\n';
	line[n] = '\0';
	return (line);
}

static char *del_line(char *stt)
{
	char	*new;
	int	i;
	int n;
	i = 0;
	while (stt[i] != '\0' && stt[i] != '\n')
		i++;
	if (!stt[i])
	{
		free (stt);
		return (NULL);
	}
	new = (char*) malloc(sizeof(char) * ft_strlen(stt) - i + 1);
	if (!new)
		return (NULL);
	i++;
	n = 0;
	while (stt[i] != '\0')
		new[n++] = stt[i++];
	new[n] = '\0';
	free(stt);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*stt;
	char	*line;
	
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	stt = read_file(fd, stt); // fun ler a linha atual
	if (!stt)
		return (NULL);
	line = read_line(stt); // func para ler a linha
	stt = remove_line(stt); // func remover a antiga linha
	return (line);
}

