/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_calls_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 14:20:47 by obastug           #+#    #+#             */
/*   Updated: 2025/01/12 13:53:26 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include <stddef.h>

void	swap(t_node **stack)
{
	t_node	*temp;

	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
}

void	push(t_node **stack_from, t_node **stack_to)
{
	t_node	*temp;

	if (!*stack_from)
		return ;
	temp = (*stack_from);
	(*stack_from) = (*stack_from)->next;
	temp->next = (*stack_to);
	(*stack_to) = temp;
}

void	rotate(t_node **stack)
{
	t_node	*temp;

	if (!*stack)
		return ;
	temp = (*stack);
	(*stack) = (*stack)->next;
	last_node(*stack)->next = temp;
	temp->next = NULL;
}

void	r_rotate(t_node **stack)
{
	t_node	*temp;

	if (!*stack)
		return ;
	temp = second_from_last_node(*stack);
	temp->next->next = *stack;
	*stack = temp->next;
	temp->next = NULL;
}
