/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:50:49 by nseropia          #+#    #+#             */
/*   Updated: 2023/05/17 13:14:35 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_gnl_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != (char)c && s[i] != '\0')
		i++;
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}

int	ft_gnl_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	int		i;
	char	*p;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	p = (char *)malloc(sizeof(char) * (ft_gnl_strlen(s1) + \
	ft_gnl_strlen(s2) + 1));
	if (p == (NULL))
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		p[i] = s1[i];
	i = 0;
	while (s2[i] != '\0')
	{
		p[ft_gnl_strlen(s1) + i] = s2[i];
		i++;
	}
	p[ft_gnl_strlen(s1) + i] = '\0';
	free(s1);
	return (p);
}
