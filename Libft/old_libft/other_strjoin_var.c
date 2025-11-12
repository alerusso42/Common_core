/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_strjoin_var.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:38:48 by alerusso          #+#    #+#             */
/*   Updated: 2025/03/06 16:56:31 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "other.h"

/*
int	main()
{
	char	*s;

	//NO STRINGS TEST
	s = NULL;
	s = ft_strjoin_var(NULL, 0);
	l_printf("\nStringa 1:\t%s", s);
	//ONE STRING TEST
	s = NULL;
	s = ft_strjoin_var(NULL, 1, "One");
	l_printf("\nStringa 2:\t%s", s);
	free(s);
	//TWO STRINGS TEST
	s = NULL;
	s = ft_strjoin_var(NULL, 2, "One", " two");
	l_printf("\nStringa 3:\t%s", s);
	free(s);
	//MULTIPLE STRINGS TEST
	s = NULL;
	s = ft_strjoin_var(NULL, 5, "One", " two", " three", " four", " five");
	l_printf("\nStringa 4:\t%s", s);
	free(s);
	//FREE FIRST
	s = NULL;
	s = ft_strjoin_var("1", 5, ft_strdup("one"), " two", " three", " four",\
	 " five");
	l_printf("\nStringa 5:\t%s", s);
	free(s);
	//FREE SECOND
	s = NULL;
	s = ft_strjoin_var("01", 5, "one", ft_strdup(" two"), " three", " four",\
	 " five");
	l_printf("\nStringa 6:\t%s", s);
	free(s);
	//FREE ALL
	s = NULL;
	s = ft_strjoin_var("2", 5, ft_strdup("one"), ft_strdup(" two"), \
	ft_strdup(" three"), ft_strdup(" four"), ft_strdup(" five"));
	l_printf("\nStringa 7:\t%s", s);
	free(s);
	l_printf("\n\nOK!\n\n");
	return (0);
}
*/

static char	*manage_free(char **which_del, char *temp, char *s);

/*
	ft_strjoin_var manages a VARIADIC strjoin.
	It assures no memory leak.

	USAGE EXAMPLE:

	s = ft_strjoin_var(NULL, 3, "One", " two", " three");
	RESULT: "One two three".

	ARGUMENTS TAKEN:

	which_del: 	a string that represents what of the
				given strings must be freed by the
				function.

	-	If you give "2", it frees all of them.
	-	If you give NULL or "", it does not free 
		anything.
	-	If you give a string of '0' and '1', it frees,
		in order, when in a string index there is '1'.
		It stops freeing when it finds '\0'.
		EXAMPLE:
		"0110", "a", "b", "c", "d"; b,c will be freed.
	
	strings:	the number of strings to join.
	...	   :	a variadic number of strings, that
				can be in stack or heap.
	
	RETURN VALUE:

	the new string if everything went fine, else NULL.

*/
char	*ft_strjoin_var(char *which_del, int strings, ...)
{
	va_list	ptr;
	char	*new_string;
	char	*temp;
	char	*s;

	if (strings <= 0)
		return (NULL);
	va_start(ptr, strings);
	temp = NULL;
	s = va_arg(ptr, char *);
	new_string = ft_strdup(s);
	while (--strings && new_string)
	{
		manage_free(&which_del, temp, s);
		temp = new_string;
		s = va_arg(ptr, char *);
		new_string = ft_strjoin(temp, s);
	}
	va_end(ptr);
	manage_free(&which_del, temp, s);
	return (new_string);
}

static char	*manage_free(char **which_del, char *temp, char *s)
{
	free(temp);
	if (s && *which_del && **which_del >= '1')
	{
		free(s);
	}
	if (*which_del && **which_del <= '1' && **which_del != '\0')
		(*which_del)++;
	return (NULL);
}
