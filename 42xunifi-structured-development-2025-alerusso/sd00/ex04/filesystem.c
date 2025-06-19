#include "filesystem.h"

FSNode *create_file(const char *name, int size)
{
	FSNode *node;

	node = malloc(sizeof(FSNode));
	if (!node)
		return (NULL);
	node->name = (char *)strdup(name);
	node->size = size;
	node->type = FILE;
	node->father = NULL;
	node->children = NULL;
	return (node);
}

FSNode *create_folder(const char *name)
{
	FSNode *node;

	node = malloc(sizeof(FSNode));
	if (!node)
		return (NULL);
	node->name = (char *)strdup(name);;
	node->size = 0;
	node->type = (int)FOLDER;
	node->father = NULL;
	node->children = NULL;
	return (node);

}

void add_child(FSNode *parent, FSNode *child)
{
	if (!parent || !child)
		return ;
	if(parent->type == (int)FILE)
	{
		write(2, "parent is a file", 17);
		return;
	}
	while(parent->children != NULL)
		parent = parent->children;
	parent->children = child;
	child->father = parent;
	//parent->size+=child->size;
}
FSNode *get_children(const FSNode *parent)
{
	return(parent->children);
}

FSNode *get_sibling(const FSNode *node)
{
	FSNode *sibl;

	sibl = (FSNode *) node;
	while(sibl->children != NULL)
		sibl = node->children;
	return (sibl);
}

// int	main()
// {
// 	char	line[15];
// 	FSNode	root;
// 	FSNode	*current;

// 	root = (FSNode){0};
// 	current = &root;
// 	printf("FILESYSTEM ON\n");
// 	while ("Loop")
// 	{
// 		printf("\nPlease insert an operation. Help for instructions.\n");
// 		read(0, line, 14);
// 		line[13] = 0;
// 		if (!strcmp(line, "create file"))
// 			create_file(line, strlen(line));
// 		else if (!strcmp(line, "create folder"))
// 			create_folder(line);
// 		else if (!strcmp(line, "add child"))
// 			add_child(current->father, current->children);
// 		else if (!strcmp(line, "get children"))
// 			get_children(current->father);
// 		else if (!strcmp(line, "get sibling"))
// 			get_sibling(current);
// 		else if (!strcmp(line, "help"))
// 			;
// 		else if (!strcmp(line, "exit"))
// 			break ;
// 		else
// 			;
// 	}
// 	printf("FILESYSTEM OFF\n");
// 	return (0);
// }
