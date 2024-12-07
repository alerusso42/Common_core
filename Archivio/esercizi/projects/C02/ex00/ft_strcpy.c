/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:49:26 by alerusso          #+#    #+#             */
/*   Updated: 2024/07/25 17:50:20 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = src[i];
	return (dest);
}
/*
int	main(void)
{
	char	src[] = "boiade";
	char	dest[20];
	char	*ptr;

	ptr = ft_strcpy(dest, src);
	//printf("%s\n", dest);
	return (0);
}*/
