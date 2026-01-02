/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 20:55:45 by alerusso          #+#    #+#             */
/*   Updated: 2026/01/02 12:09:55 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

static void	_str_garbage_collector(t_str *p, bool delete);

//ANCHOR - _Str_constructor
/*
	!!!This function is private! It shouldn't be used!
	To init a string stack object:
	@usage:	*-------------------------------*	
			|	STR(name, "BUFFER");		|
			|	//code ...					|
			*-------------------------------*
//REVIEW - Initialize a stack string object.
*/
t_str	_str_constructor(t_str *str, const char *buff)
{
	STR_LOG("%s\tconstructor\n", buff);
	*str = (t_str){0};
	str->_str_identifier = _STR_IDENTIFIER;
	str->capacity = -1;
	str->set = str_set_start_index;
	if (_str_get_methods(str, false) != EXIT_SUCCESS)
		return (*str);
	if (sdup(str, buff)->err != 0)
		return (*str);
	str->npos = INT32_MAX;
	_str_set(str);
	return (*str);
}

//ANCHOR - str_new
/*
//	Initialize a heap string object.

	@input:		[t_str **str]----->	pointer to string object
				[const char *buff]->initial buffer content
	@return:	[bool]----------->	success or failure
	@variables:	none
	@usage:	*-------------------------------*	
			|	t_str *str;					|
			|	str_new(&str, "BUFFER");	|
			|	//code ...					|
			|	str_delete(&str);			|
			|	//OR, global delete needed:	|
			|	str_terminate();			|
			*-------------------------------*
*/
bool	str_new(t_str **str, const char *buff)
{
	*str = CALLOC(1, sizeof(t_str));
	if (!*str)
		return (EXIT_FAILURE);
	_str_constructor(*str, buff);
	_str_garbage_collector(*str, false);
	return (EXIT_SUCCESS);
}

//ANCHOR - _str_garbage_collector
/*
	!!!This function is private! It shouldn't be used!
	
	This is the garbage collection of heap string objects.

	@input:		[t_str **str]----->	pointer to string object
				[bool delete]----->	flag to indicate deletion
	@return:	none
	@variables:	[static t_list *garbage_list]--->	list of allocated strings;
	
//REVIEW
//	1)	If delete is false, a new node is created in garbage_list;
	2)	If p is NULL, all allocated strings are deleted;
	3)	If p is the head of the list,
		the head of the list is moved forward.
*/
static void	_str_garbage_collector(t_str *p, bool delete)
{
	static t_list	*garbage_list;

	if (delete == false)
	{
		p->_garbage_coll_node = lst_new(p);
		lst_back(&garbage_list, p->_garbage_coll_node);
		return ;
	}
	if (!p)
		return (lst_clear(&garbage_list, _str_destructor));
	else if (p->_garbage_coll_node == garbage_list)
	{
		garbage_list = garbage_list->next;
	}
}

//ANCHOR - _str_destructor
/*
	!!!This function is private! It shouldn't be used!

	Destructor for both stack and heap string objects.

	@input:		[void *str]----->	pointer to string object
	@return:	none
	@variables:	none
	
//REVIEW
//	If the string is heap allocated,
	it calls the garbage collector to remove it from the list
	and frees the string object itself.
*/
void	_str_destructor(void *str)
{
	STR_LOG("%s\tdestructor\n", ((t_str *)str)->buff);
	_str_get_methods(NULL, false);
	FREE(((t_str *)str)->buff);
	if (((t_str *)str)->_garbage_coll_node)
	{
		_str_garbage_collector(((t_str *)str), true);
		FREE(str);
	}
}

//ANCHOR - str_new
/*
//	Destroys all heap string objects.
	Always safe to call.

	@input:		none
	@return:	none
	@variables:	none
	@usage:	*-------------------------------*	
			|	str_terminate();			|
			*-------------------------------*
*/
void	str_terminate(void)
{
	_str_garbage_collector(NULL, true);
	_str_get_methods(NULL, true);
}
