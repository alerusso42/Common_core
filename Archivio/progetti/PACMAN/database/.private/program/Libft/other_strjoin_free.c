/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_strjoin_free.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:26:15 by alerusso          #+#    #+#             */
/*   Updated: 2025/05/31 20:21:07 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "other.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*stringona;
	int		index;
	int		size;

	if ((!s1) || (!s2))
		return (SDL_free(s1), SDL_free(s2), NULL);
	index = 0;
	while (s1[index])
		++index;
	size = index;
	index = 0;
	while (s2[index])
		++index;
	size += index;
	stringona = (char *)ft_calloc(size + 2, sizeof(char));
	if (!stringona)
		return (SDL_free(s1), SDL_free(s2), NULL);
	index = -1;
	while (s1[++index])
		stringona[index] = s1[index];
	size = -1;
	while (s2[++size])
		stringona[index++] = s2[size];
	return (SDL_free(s1), SDL_free(s2), stringona);
}

static void	to_free(char *s1, char *s2, char which)
{
	if (which == 1 || which >= 3)
		SDL_free(s1);
	if (which >= 2)
		SDL_free(s2);
}

/*
	A strjoin, but:
1)	which == 0:	free NOTHING
	which == 1:	free s1
	which == 2: free s2
	which == 3: free BOTH

2)	if s1 or s2 are NULL, returns a strdup of other string.

3)	Always frees string chosen by which, even in case of errors.
*/
char	*ft_strjoin_which(char *s1, char *s2, char which)
{
	char	*stringona;
	int		index;
	int		index2;

	stringona = NULL;
	if ((!s1) || (!s2))
	{
		if (s1)
			stringona = ft_strdup(s1);
		else if (s2)
			stringona = ft_strdup(s2);
		return (to_free(s1, s2, which), stringona);
	}
	index = ft_strlen(s1) + ft_strlen(s2);
	stringona = (char *)ft_calloc(index + 2, sizeof(char));
	if (!stringona)
		return (to_free(s1, s2, which), NULL);
	index = -1;
	while (s1[++index])
		stringona[index] = s1[index];
	index2 = -1;
	while (s2[++index2])
		stringona[index++] = s2[index2];
	return (to_free(s1, s2, which), stringona);
}
