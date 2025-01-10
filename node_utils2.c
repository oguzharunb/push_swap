/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:58:41 by obastug           #+#    #+#             */
/*   Updated: 2025/01/10 15:57:40 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_linked_list(t_node *list)
{
	while (list)
	{
		ft_putnbr(list->data);
		ft_putchar('\n');
		list = list->next;
	}
}

int	list_size(t_node *list)
{
	int	i;

	i = 0;
	while (list)
	{
		i++;
		list = list->next;		
	}
	return (i);
}
