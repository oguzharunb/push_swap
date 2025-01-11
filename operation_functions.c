/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:34:38 by obastug           #+#    #+#             */
/*   Updated: 2025/01/11 14:19:51 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
