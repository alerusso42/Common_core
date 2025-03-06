/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_strjoin_var copy.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:38:48 by alerusso          #+#    #+#             */
/*   Updated: 2025/03/06 17:23:36 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "other.h"

char	*var_strjoin(int num, ...);

int	main()
{
	char	*s;

	//NO STRINGS TEST
	s = NULL;
	s = var_strjoin(0);
	l_printf("\nStringa 1:\t%s", s);
	//ONE STRING TEST
	s = NULL;
	s = var_strjoin(1, "One");
	l_printf("\nStringa 2:\t%s", s);
	free(s);
	//TWO STRINGS TEST
	s = NULL;
	s = var_strjoin(2, "One", " two");
	l_printf("\nStringa 3:\t%s", s);
	free(s);
	//MULTIPLE STRINGS TEST
	s = NULL;
	s = var_strjoin(5, "One", " two", " three", " four", " five");
	l_printf("\nStringa 4:\t%s", s);
	free(s);
	//FREE FIRST
	s = NULL;
	s = var_strjoin(5, ft_strdup("one"), " two", " three", " four",\
	 " five");
	l_printf("\nStringa 5:\t%s", s);
	free(s);
	//FREE SECOND
	s = NULL;
	s = var_strjoin(5, "one", ft_strdup(" two"), " three", " four",\
	 " five");
	l_printf("\nStringa 6:\t%s", s);
	free(s);
	//FREE ALL
	s = NULL;
	s = var_strjoin(5, ft_strdup("one"), ft_strdup(" two"), \
	ft_strdup(" three"), ft_strdup(" four"), ft_strdup(" five"));
	l_printf("\nStringa 7:\t%s", s);
	free(s);
	l_printf("\n\nOK!\n\n");
	return (0);
}

static char	*manage_free(char *temp, char *s);

/*
	var_strjoin manages a VARIADIC strjoin.
	It assures no memory leak.

	USAGE EXAMPLE:

	s = var_strjoin(NULL, 3, "One", " two", " three");
	RESULT: "One two three".

	ARGUMENTS TAKEN:

	strings:	the number of strings to join.
	...	   :	a variadic number of strings, that
				can be in stack or heap.
				Heap strings will be freed.
				Non-stack strings will NOT be freed.
	
	RETURN VALUE:

	the new string if everything went fine, else NULL.

*/
char	*var_strjoin(int num, ...)
{
	va_list	ptr;
	char	*new_string;
	char	*temp;
	char	*s;

	if (num <= 0)
		return (NULL);
	va_start(ptr, num);
	temp = NULL;
	s = va_arg(ptr, char *);
	new_string = ft_strdup(s);
	while (--num && new_string)
	{
		manage_free(temp, s);
		temp = new_string;
		s = va_arg(ptr, char *);
		new_string = ft_strjoin(temp, s);
	}
	va_end(ptr);
	manage_free(temp, s);
	return (new_string);
}

static char	*manage_free(char *temp, char *s)
{
	void	*placeholder_address;
	char	placeholder;

	placeholder_address = (void *)&placeholder;
	free(temp);
	if ((void *)&s > placeholder_address)
		free(s);
	return (NULL);
}

