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

char	*get_next_line(int fd)
{
	static char	*stt;
	char	*line;
	
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	stt = read_file(fd, stt); // fun ler a linha atual
	if (!stt)
		return (NULL);
	line = read_line(); // func para ler a linha
	stt = remove_line(); // func remover a antiga linha
	return (line);
}