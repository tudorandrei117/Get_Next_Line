/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburlacu <tburlacu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 23:02:26 by pedperei          #+#    #+#             */
/*   Updated: 2022/11/24 14:21:03 by tburlacu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>

/*+2 por cuase do \n e do null terminator*/
char	*ft_current_line(char *str)
{
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	if (!(str) || str[i] == '\0')
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		i--;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!(line))
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

/*aloca-se memoria para a string atual (ft_strlen) 
menos a linha que vai ser	retornada(i)*/
char	*ft_next_line(char *str)
{
	char	*new_line;
	char	*temp;
	int		i;

	new_line = NULL;
	temp = NULL;
	if (!(str))
		return (NULL);
	if (ft_strchr_mod(str, '\n') != NULL)
		temp = ft_strchr_mod(str, '\n');
	else
	{
		free(str);
		return (NULL);
	}
	new_line = (char *)malloc(sizeof(char) * (ft_strlen_mod(temp) + 1));
	if (!(new_line))
		return (NULL);
	i = -1;
	while (temp[++i] != '\0')
		new_line[i] = temp[i];
	new_line[i] = '\0';
	free(str);
	return (new_line);
}



char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*list;
	char		*temp;

	if (fd < 0 || fd > 4096 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!(buffer))
		return (NULL);
	list = ft_read(fd, buffer, list);
	temp = ft_current_line(list);
	list = ft_next_line(list);
	free(buffer);
	return (temp);
}

int main(void)
{
	int fd;

	fd = open("tst.txt", O_RDONLY);
	
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}