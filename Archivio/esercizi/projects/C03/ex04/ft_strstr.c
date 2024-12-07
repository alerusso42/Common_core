/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 09:27:35 by alerusso          #+#    #+#             */
/*   Updated: 2024/09/13 09:27:50 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(char *str, char *to_find);

/*
int main()
{
	char   argv1[20] = "Gabibbo";
	char   argv2[20] = "";
	char   *needle;

	needle = strstr(argv1, argv2);
	printf("\nrisultato: %s\n", needle);
	needle = ft_strstr(argv1, argv2);
	printf("\nreplica: %s\n", needle);
	return (0);
}
*/
char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;
	char	*needle;

	i = 0;
	j = 0;
	if (to_find[j] == '\0')
		return (str);
	while (str[i] & to_find[j])
	{
		if (str[i] == to_find[j])
		{
			if (j == 0)
				needle = &str[i];
			++j;
		}
		else
			j = 0;
		++i;
	}
	if (to_find[j])
		return (NULL);
	else
		return (needle);
}
