/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_square_brackets.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:30:19 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/09 22:38:05 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <malloc.h>

int	cut_string(char **string, size_t start, size_t end);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(const char *string);

int	add_sign_left(char **string, char sign)
{
	size_t	len;
	char	*new_string;

	if ((!string) || (!*string))
		return (1);
	len = strlen(*string);
	new_string = (char *)calloc(len + 2, sizeof(char));
	if (!new_string)
		return (1);
	new_string[0] = sign;
	strcpy(new_string + 1, *string);
	free(*string);
	*string = new_string;
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*stringona;
	int		index;
	int		size;

	if ((!s1) || (!s2))
		return (NULL);
	index = 0;
	while (s1[index])
		++index;
	size = index;
	index = 0;
	while (s2[index])
		++index;
	size += index;
	stringona = (char *)malloc(size + 1);
	if (!stringona)
		return (NULL);
	index = -1;
	while (s1[++index])
		stringona[index] = s1[index];
	size = -1;
	while (s2[++size])
		stringona[index++] = s2[size];
	return (stringona);
}

int	move_square_br(char **old, char **new, short int flag)
{
	int		start;
	int		end;
	int		len;
	char	*gen_new_string;

	start = 0;
	while (((*old)[start]) && ((*old)[start] != '['))
		++start;
	if ((*old)[start] == 0)
		return (2);
	end = start;
	while (((*old)[end]) && ((*old)[end] != ']'))
		++end;
	len = ft_strlen(*old);
	*new = ft_calloc(len + 1, sizeof(char));
	if (!(*new))
		return (1);
	strcpy(*new, *old);
	if (cut_string(new, start, end) == 1)
		return (1);
	if (add_sign_left(new, '*') == 1)
		return (free(*new), 1);
	if (flag == 1)
		free(*old);
	if (flag == 1)
		*old = NULL;
	gen_new_string = NULL;
	if (move_square_br(new, &gen_new_string, 1) == 1)
		return (free(*new), 1);
	if (gen_new_string)
	{
		free(*new);
		*new = gen_new_string;
	}
	return (0);
}

int	main()
{
	char	*new;
	char	*old = "string[22][22][22]";

	new = NULL;
	move_square_br(&old, &new, 0);
	printf("new: %s\n", new);
	if (new)
		free(new);
	new = NULL;
	return (0);
}