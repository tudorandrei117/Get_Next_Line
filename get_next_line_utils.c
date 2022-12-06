/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburlacu <tburlacu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:45:03 by tburlacu          #+#    #+#             */
/*   Updated: 2022/12/06 15:04:56 by tburlacu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\n' && s[i])
	{
		i++;
	}
	return (i + (s[i] == '\n'));
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2 && s2[j] && s2[j] != '\n')
		str[i++] = s2[j++];
	if (s2[j] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	free(s1);
	return (str);
}


int	organizer(char *buf)
{
	int i;
	int j;
	int isnwl;

	i = 0;
	j = 0;
	isnwl = 0;
	while (buf[i])
	{
		if (isnwl)
			buf[j++] = buf[i];
		if (buf[i] == '\n')
			isnwl = 1;
		buf[i++] = '\0';
	}
		return (isnwl);
}

/* int	checkeol(char *buf)
{
	size_t	i;

	i = 0;
	while (buf[i])
		if (buf[i++] == '\n')
			return (1);
	return (0);
}


 */