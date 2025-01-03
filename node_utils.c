/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:21:37 by obastug           #+#    #+#             */
/*   Updated: 2025/01/03 17:29:03 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>

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
