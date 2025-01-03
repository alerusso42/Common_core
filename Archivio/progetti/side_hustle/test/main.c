#include "header.h"

int	main()
{
	t_typelist	**struct_list;
	char		**struct_list_names;
	t_typelist	*list;
	t_typelist	*temp;
	int			counter;

	struct_list = NULL;
	if (get_struct_list(&struct_list, &struct_list_names) != 0)
		return (printf("ERROR!\n"));
	list = NULL;
	temp = NULL;
	del_pointer((void **)&struct_list, 1);
	del_pointer((void **)&struct_list_names, 1);
	while ((struct_list) && (*struct_list))
	{
		counter = 1;
		list = *struct_list;
		printf("\nLIST %s:\n", *struct_list_names);
		while ((list) && (list->next))
		{
			printf("type n_%d: %s\n", counter, (char *)list->type);
			printf("name n_%d: %s\n\n", counter, (char *)list->content);
			del_pointer((void **)&(list->content), 0);
			del_pointer((void **)&(list->type), 0);
			temp = list;
			list = list->next;
			del_pointer((void **)&(temp), 0);
			++counter;
		}
		del_pointer((void **)&(list), 0);
		del_pointer((void **)&(*struct_list_names), 0);
		++struct_list;
		++struct_list_names;
	}
	del_pointer(NULL, 2);
	del_pointer(NULL, 2);
	return (0);
}