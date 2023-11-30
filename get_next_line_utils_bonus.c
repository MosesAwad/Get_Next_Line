/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawad <mawad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 20:10:38 by mawad             #+#    #+#             */
/*   Updated: 2023/11/30 22:46:31 by mawad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*free_bird(char *pointer, char **store)
{
	if (pointer == NULL)
	{
		free(*store);
		*store = NULL;
		return (NULL);
	}
	return (pointer);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*buffer;

	i = 0;
	if (s == NULL)
		return (NULL);
	buffer = (char *)malloc(sizeof(*buffer) * (ft_strlen(s) + 1));
	if (buffer == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		buffer[i] = s[i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	if (c == '\0')
		return ((char *)s + i);
	return (NULL);
}

char	*ft_strjoin(char **s1, const char *s2)
{
	int		i;
	int		j;
	char	*buffer;

	if (*s1 == NULL)
		*s1 = ft_strdup("");
	if (s2 == NULL || (*s1) == NULL)
		return (NULL);
	buffer = malloc(sizeof(*buffer) * (ft_strlen(*s1) + ft_strlen(s2) + 1));
	if (!buffer)
		return (free(*s1), NULL);
	i = 0;
	while ((*s1)[i] != '\0')
	{
		buffer[i] = (*s1)[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		buffer[i++] = s2[j++];
	buffer[i] = '\0';
	free(*s1);
	return (buffer);
}
