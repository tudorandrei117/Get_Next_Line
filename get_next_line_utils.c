/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 19:39:07 by pedperei          #+#    #+#             */
/*   Updated: 2022/11/12 11:58:30 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_mod(const char *s)
{
	size_t	i;

	i = 0;
	while (s != NULL && s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr_mod(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
		{
			return ((char *)&str[i + 1]);
		}
		i++;
	}
	if ((char)c == str[i])
	{
		return ((char *)&str[i]);
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*strjoin;
	int		len;

	i = 0;
	j = 0;
	len = ft_strlen_mod(s1) + ft_strlen_mod(s2);
	strjoin = (char *)malloc(sizeof(char) * (len + 1));
	if (!(strjoin))
		return (NULL);
	while (s1 != NULL && s1[i] != '\0')
	{
		strjoin[i] = s1[i];
		i++;
	}
	while (s2 != NULL && s2[j] != '\0')
	{
		strjoin[i + j] = s2[j];
		j++;
	}
	strjoin[i + j] = '\0';
	return (strjoin);
}
