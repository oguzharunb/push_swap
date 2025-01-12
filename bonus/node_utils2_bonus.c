/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:58:41 by obastug           #+#    #+#             */
/*   Updated: 2025/01/11 20:26:43 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include <unistd.h>

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

int	where_is_max(t_node *stack)
{
	int	i;

	i = 0;
	while (stack && stack->next && stack->data > stack->next->data)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	max_to_first_node(t_node **stack)
{
	int		max_loc;
	t_node	*temp;
	int		i;

	temp = *stack;
	if (last_node(temp)->data < temp->data)
		return ;
	max_loc = where_is_max(temp);
	if (max_loc > list_size(*stack) / 2 - 1)
	{
		while (max_loc++ < list_size(*stack) - 1)
		{
			r_rotate(stack);
			write(1, "rrb\n", 4);
		}
	}
	else
	{
		i = 0;
		while (i++ < max_loc + 1)
		{
			rotate(stack);
			write(1, "rb\n", 3);
		}
	}
}

int	is_there_duplicate(t_node *stack)
{
	t_node	*temp;

	temp = stack;
	while (temp->next)
	{
		temp = temp->next;
		if (stack->data == temp->data)
			return (1);
	}
	if (stack->next)
		return (is_there_duplicate(stack->next));
	return (0);
}
