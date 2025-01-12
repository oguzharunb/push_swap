/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:26:50 by obastug           #+#    #+#             */
/*   Updated: 2025/01/11 22:01:53 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include <stddef.h>
#include <stdlib.h>

t_node	*last_node(t_node *list_first_elem)
{
	if (!list_first_elem)
		return (NULL);
	while (list_first_elem->next)
		list_first_elem = list_first_elem->next;
	return (list_first_elem);
}

t_node	*second_from_last_node(t_node *list_first_elem)
{
	t_node	*second_from_last;

	if (!list_first_elem)
		return (NULL);
	second_from_last = NULL;
	while (list_first_elem->next)
	{
		second_from_last = list_first_elem;
		list_first_elem = list_first_elem->next;
	}
	return (second_from_last);
}

t_node	*create_node(int number)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->data = number;
	node->next = NULL;
	return (node);
}

void	add_to_list(t_node **list, t_node *new_node)
{
	t_node	*last;

	if (*list == NULL)
	{
		*list = new_node;
		return ;
	}
	last = last_node(*list);
	last->next = new_node;
}

void	free_linked_list(t_node *list)
{
	if (list && list->next)
		free_linked_list(list->next);
	if (list)
		free(list);
	return ;
}
