/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburlacu <tburlacu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:10:31 by tburlacu          #+#    #+#             */
/*   Updated: 2022/12/06 15:05:00 by tburlacu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	b[BUFFER_SIZE + 1];
	char		*str;

	str = NULL;
	if (fd < 0 || fd > FOPEN_MAX)
		return (NULL);
	if (!b[0])
		b[read(fd, b, BUFFER_SIZE)] = 0;
	while (b[0])
	{
		str = ft_strjoin(str, b);
		if (!str)
			return (NULL);
		if (organizer(b) == 1)
			break;
		if (read(fd, b, 0) < 0)
		{
			free(str);
			return (NULL);
		}
		b[read(fd, b, BUFFER_SIZE)] = 0;
	}
	return (str);
}

/* int main()
{
	char *line;
	int		fd1;

	fd1 = open("tst.txt", O_RDONLY);
	line = get_next_line(fd1);
	printf("T1:%s", line);
	free(line);
	line = get_next_line(fd1);
	printf("T1:%s", line);
	free(line);
		line = get_next_line(fd1);
	printf("T1:%s", line);
	free(line);
	line = get_next_line(fd1);
	printf("T1:%s", line);
	free(line);

} */








