/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:51:06 by obastug           #+#    #+#             */
/*   Updated: 2025/01/10 19:40:36 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// in a list {1,2,3,5} and input 4
// it will return index 3 (5 will be pushed to 4 from 3)
#include <stdio.h>

int	min_of_4(int a, int b, int c, int d)
{
	if (a < b && a < c && a < d)
		return (a);
	if (b < c && b < d)
		return (b);
	if (c < d)
		return (c);
	return (d);
}

// push excluded
int	calculate_number_of_ops(int stack_a_size, int index_a, int stack_b_size, int index_b)
{
	int	b_diff_using_rr;
	int	a_diff_using_rr;
	int	rr_optimized;
	int	r_optimized;

	a_diff_using_rr = stack_a_size - index_a;
	b_diff_using_rr = stack_b_size - index_b;
	rr_optimized = a_diff_using_rr;
	if (b_diff_using_rr > a_diff_using_rr)
		rr_optimized = b_diff_using_rr;
	r_optimized = index_a;
	if (index_b > index_a)
		r_optimized = index_b;
	return (min_of_4(r_optimized, rr_optimized, index_a + b_diff_using_rr, index_b + a_diff_using_rr));
}

int	find_place_for_number_in_list(t_node *stack_b, int number)
{
	t_node	*temp;
	int		order;

	order = 0;
	if (number < stack_b->data && stack_b->data >= last_node(stack_b)->data)
		return (0);
	while (stack_b->next)
	{
		order++;
		if (number <= stack_b->data && number >= stack_b->next->data)
			break;
		stack_b = stack_b->next;
	}
	return (order);
}

//returns the number of instructions, if fully sorted returns 0
int	find_best_solution_apply_and_print(t_node *stack_a, t_node *stack_b)
{
	int		replace_a;
	int		replace_b;
	int		i;
	t_node	*temp;
	int		as_place_in_b;
	int		min;
	int		minn;

	temp = stack_a;
	replace_a = 0;
	i = 0;
	while (temp)
	{
		as_place_in_b = find_place_for_number_in_list(stack_b, temp->data);
		minn = calculate_number_of_ops(list_size(stack_a), i, list_size(stack_b), as_place_in_b);
		if (min && as_place_in_b < min)
		{
			min = minn;
			replace_a = i;
			replace_b = as_place_in_b;
		}
		temp = temp->next;
	}
	printf("a's %d. value will be in b's %d. value with %d operations.\n", replace_a, replace_b, min);
	return (min);
}

void	print_ops_for_linked_list(t_node *list)
{
	t_node	*stack_b;
	int		total_instruction;
	int		temp;

	total_instruction = 0;
	temp = 1;
	while (temp)
	{
		temp = find_best_solution_apply_and_print(list, stack_b);
		total_instruction += temp;
	}
	return ;
}
