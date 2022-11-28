/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburlacu <tburlacu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:45:03 by tburlacu          #+#    #+#             */
/*   Updated: 2022/11/24 14:39:46 by tburlacu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * It counts the number of characters in a string.
 * 
 * @param s The string to be measured.
 * 
 * @return The length of the string.
 */
int	ft_strlen(char *s)
{
	int	i;

	i = 0;

	while (s[i] != '\n' || s[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * It takes two strings and joins them together.
 * 
 * @param s1 The first string to be joined.
 * @param s2 the string to be appended to s1
 * 
 * @return A pointer to a new string.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	j = 0;
	i = 0;
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
	str[j] = s1[i];
			i++;
			j++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		str[j] = s2[i];
			i++;
			j++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;

	while (s)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i + 1]);
		if ((char)c == s[i])
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}
