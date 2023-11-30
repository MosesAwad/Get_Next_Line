/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawad <mawad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:57:06 by mawad             #+#    #+#             */
/*   Updated: 2023/11/30 22:47:33 by mawad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extraction(char *s)
{
	int		i;
	char	*buffer;

	i = 0;
	while ((s[i] != '\0') && (s[i] != '\n'))
		i++;
	if (s[i] == '\0')
		buffer = (char *) malloc((i + 1) * sizeof(*buffer));
	else
		buffer = (char *) malloc((i + 1 + 1) * sizeof(*buffer));
	if (buffer == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
	{
		buffer[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
		buffer[i++] = '\n';
	buffer[i] = '\0';
	return (buffer);
}

static char	*remaining(char *s)
{
	int		i;
	int		j;
	char	*buffer;

	i = 0;
	j = 0;
	while ((s[i] != '\0') && (s[i] != '\n'))
		i++;
	if ((s[i] == '\0') || (s[i] == '\n' && s[i + 1] == '\0'))
	{
		free(s);
		return (NULL);
	}
	buffer = malloc(((ft_strlen(s) - i) + 1) * (sizeof(*buffer)));
	if (!buffer)
		return (free(s), NULL);
	i++;
	while (s[i] != '\0')
		buffer[j++] = s[i++];
	buffer[j] = '\0';
	free(s);
	return (buffer);
}

static int	checker(int nb_read, char **store, char *buffer)
{
	if ((nb_read == 0 && *store == NULL) || (nb_read == -1))
	{
		if (nb_read == -1)
		{
			free(*store);
			*store = NULL;
		}
		free(buffer);
		return (1);
	}
	return (0);
}

static char	*buffer_read(int fd, char *store)
{
	char		*buffer;
	int			nb_read;

	nb_read = -1;
	while (nb_read != 0 && !ft_strchr(store, '\n'))
	{
		buffer = (char *)malloc(sizeof(*buffer) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (free(store), NULL);
		nb_read = read(fd, buffer, BUFFER_SIZE);
		if (checker(nb_read, &store, buffer) == 1)
			return (NULL);
		buffer[nb_read] = '\0';
		store = ft_strjoin(&(store), buffer);
		if (!store)
			return (free(buffer), NULL);
		free(buffer);
	}
	return (store);
}

char	*get_next_line(int fd)
{
	static char	*store;
	char		*extract;

	if (BUFFER_SIZE >= 2147483647 || BUFFER_SIZE <= 0)
		return (NULL);
	store = buffer_read(fd, store);
	if (!store)
		return (NULL);
	extract = extraction(store);
	if (!free_bird(extract, &store))
		return (NULL);
	store = remaining(store);
	return (extract);
}
