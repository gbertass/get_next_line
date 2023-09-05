/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertass <gbertass@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:51:13 by gbertass          #+#    #+#             */
/*   Updated: 2023/09/05 17:59:19 by gbertass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_file(int fd, char *stt)
{
	int		len;
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
			free (buff);
			return (NULL);
		}
		buff[len] = '\0';
		stt = ft_strjoin(stt, buff);
	}
	free (buff);
	return (stt);
}

char	*read_line(char *stt)
{
	char	*line;
	size_t	n;

	if (!*stt)
		return (NULL);
	n = 0;
	while (stt[n] != '\0' && stt[n] != '\n')
		n++;
	line = (char *)malloc(sizeof(char) * (n + 2));
	if (!line)
		return (NULL);
	ft_strlcpy(line, stt, n + 1);
	if (stt[n] == '\n')
		line[n++] = '\n';
	line[n] = '\0';
	return (line);
}

char	*del_line(char *stt)
{
	char	*new;
	int		i;
	int		n;

	i = 0;
	while (stt[i] != '\0' && stt[i] != '\n')
		i++;
	if (!stt[i])
	{
		free (stt);
		return (NULL);
	}
	new = (char *)malloc(sizeof(char) * ft_strlen(stt) - i + 1);
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
	static char		*stt[FILE_MAX];
	char			*line;

	if (fd < 0 || BUFFER_SIZE < 1 || fd >= FILE_MAX)
		return (NULL);
	stt[fd] = read_file(fd, stt[fd]);
	if (!stt[fd])
		return (NULL);
	line = read_line(stt[fd]);
	stt[fd] = del_line(stt[fd]);
	return (line);
}
int	main()
{
	int	a = open("file1.txt", O_RDONLY);
	printf("%d\n", a);
	printf("%s", get_next_line(a));

	int	b = open("file2.txt", O_RDONLY);
	printf("%d\n", b);
	printf("%s", get_next_line(b));

	printf("%s", get_next_line(a));
	printf("%s", get_next_line(b));
}