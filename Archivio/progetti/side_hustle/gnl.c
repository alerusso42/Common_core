/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:43:57 by negambar          #+#    #+#             */
/*   Updated: 2024/11/25 11:47:46 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

char	*gnl_strdup(char *s)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = gnl_strlen(s) + 1;
	str = (char *)gnl_calloc((j), sizeof(char));
	if (!str)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_join_free(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1)
		return (gnl_strdup(s2));
	str = (char *)gnl_calloc((gnl_strlen(s1) + gnl_strlen(s2) + 1), sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i] != '\0')
		str[i] = s1[i];
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	free (s1);
	return (str);
}

char	*ft_str(char *s)
{
	int		slen;
	int		tlen;
	char	*buf;

	if (s == NULL)
		return (NULL);
	slen = 0;
	tlen = gnl_strlen(s);
	while ((s[slen]) != '\n' && (s[slen]))
		slen++;
	if (s[slen] == '\0')
	{
		free (s);
		return (NULL);
	}
	buf = (char *)gnl_calloc((tlen - slen + 2), sizeof(char));
	if (!buf)
		return (NULL);
	tlen = 0;
	while (s[slen + 1] != '\0')
		buf[tlen++] = s[(slen++) + 1];
	buf[tlen + 1] = '\0';
	free (s);
	return (buf);
}

char	*ft_get_line(int fd, char *buffer, char *nextl)
{
	int		read_check;

	read_check = 1;
	while (read_check > 0)
	{
		read_check = read(fd, buffer, BUFFER_SIZE);
		if (read_check == -1)
		{
			if (nextl != NULL)
				free(nextl);
			return (NULL);
		}
		if (read_check == 0)
			break ;
		buffer[read_check] = '\0';
		nextl = ft_join_free(nextl, buffer);
		if (gnl_strchr(buffer, '\n'))
			break ;
	}
	return (nextl);
}

char	*gnl(int fd)
{
	char		*res;
	static char	*nextl = NULL;
	char		*buffer;

	buffer = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (nextl != NULL)
			free (nextl);
		return (NULL);
	}
	res = NULL;
	buffer = (char *)gnl_calloc((BUFFER_SIZE + 1), sizeof(char));
	nextl = ft_get_line(fd, buffer, nextl);
	free (buffer);
	buffer = NULL;
	res = gnl_substr(nextl, 0, '\n');
	nextl = ft_str(nextl);
	return (res);
}

/* int main(void)
{
	int fd;
	int i;

	i = 0;
	fd = open("testing.txt", O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		return (0);
	}
	while (i < 32)
	{
		char *s = gnl(fd);
		printf("%s", s);
		i++;
		free(s);
	}
	close(fd);
	return 0;
} */