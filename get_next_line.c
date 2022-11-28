/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburlacu <tburlacu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:10:31 by tburlacu          #+#    #+#             */
/*   Updated: 2022/11/24 14:38:32 by tburlacu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
 * Reads from a file descriptor, and returns a string
  containing the contents of the file
 * 
 * @param fd file descriptor
 * @param buffer This is the buffer that will be used to read the file.
 * @param text the string that will be returned
 * 
 * @return a pointer to a string.
 */
char	*ft_read(int fd, char *buffer, char *text)
{
	int		index;
	char	*temp;

	index = 1;
	temp = NULL;
	while (index > 0)
	{
		index = read(fd, buffer, BUFFER_SIZE);
		if (index < 0)
		{
			text = NULL;
			index = '\0';
			return (NULL);
		}
		buffer[index] = '\0';
		temp = text;
		text = ft_strjoin(temp, buffer);
		free(temp);
		if (ft_strchr(buffer, '\n') != '\0')
			break ;
	}
}



char *get_next_line(int fd)
{
	
}












int main(void)
{
	int fd;

	fd = open("tst.txt", O_RDONLY);
	
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}