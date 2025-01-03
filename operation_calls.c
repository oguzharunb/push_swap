/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_calls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 14:20:47 by obastug           #+#    #+#             */
/*   Updated: 2025/01/03 17:35:06 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **stack)
{
	t_node	*temp;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->next = temp;
}

void	push(t_node **stack_from, t_node **stack_to)
{

}

void	rotate(t_node **stack)
{
	
}

void	r_rotate(t_node **stack)
{
	
}