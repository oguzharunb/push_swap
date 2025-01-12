/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils3_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 13:54:24 by obastug           #+#    #+#             */
/*   Updated: 2025/01/12 13:54:37 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

// returns 1 if sorted
int	check_is_sorted(t_node *stack_a, t_node *stack_b)
{
	if (stack_b)
		return (0);
	while (stack_a)
	{
		if (stack_a->next && stack_a->data > stack_a->next->data)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}
