/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_functions_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:34:38 by obastug           #+#    #+#             */
/*   Updated: 2025/01/12 13:55:12 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	swap_both(t_node **stack_a, t_node **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}

void	rotate_both(t_node **stack_a, t_node **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}

void	reverse_rotate_both(t_node **stack_a, t_node **stack_b)
{
	r_rotate(stack_a);
	r_rotate(stack_b);
}

int	apply_operation(t_node **stack_a, t_node **stack_b, char *op)
{
	if (!ft_strcmp(op, "ra\n"))
		rotate(stack_a);
	else if (!ft_strcmp(op, "rb\n"))
		rotate(stack_b);
	else if (!ft_strcmp(op, "rr\n"))
		rotate_both(stack_a, stack_b);
	else if (!ft_strcmp(op, "sa\n"))
		swap(stack_a);
	else if (!ft_strcmp(op, "sb\n"))
		swap(stack_b);
	else if (!ft_strcmp(op, "pa\n"))
		push(stack_b, stack_a);
	else if (!ft_strcmp(op, "pb\n"))
		push(stack_a, stack_b);
	else if (!ft_strcmp(op, "rra\n"))
		r_rotate(stack_a);
	else if (!ft_strcmp(op, "rrb\n"))
		r_rotate(stack_b);
	else if (!ft_strcmp(op, "rrr\n"))
		reverse_rotate_both(stack_a, stack_b);
	else
		return (0);
	return (1);
}
