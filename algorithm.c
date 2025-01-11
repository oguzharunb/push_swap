/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:51:06 by obastug           #+#    #+#             */
/*   Updated: 2025/01/11 18:54:25 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <unistd.h>
// in a list {1,2,3,5} and input 4
// it will return index 3 (5 will be pushed to 4 from 3)

// push excluded
unsigned long	calculate_number_of_ops(int a_size, int ia, int b_size, int ib)
{
	int				b_diff_rr;
	int				a_diff_rr;
	int				rr_optimized;
	int				r_optimized;
	unsigned long	ret;

	a_diff_rr = a_size - ia;
	b_diff_rr = b_size - ib;
	rr_optimized = a_diff_rr;
	if (b_diff_rr > a_diff_rr)
		rr_optimized = b_diff_rr;
	r_optimized = ia;
	if (ib > ia)
		r_optimized = ib;
	ret = min_of_4(r_optimized, rr_optimized, ia + b_diff_rr, ib + a_diff_rr);
	ret += which_one_is_min(r_optimized, rr_optimized, ia + b_diff_rr, ib + a_diff_rr) << 32;
	return (ret);
}

// it returns correctly till its a sorted linked list
int	find_place_for_number_in_list(t_node *stack_b, int number)
{
	t_node	*temp;
	int		order;

	if (number == stack_b->data || last_node(stack_b)->data == number || (last_node(stack_b)->data >= stack_b->data && number > stack_b->data && number < last_node(stack_b)->data) || (last_node(stack_b)->data < stack_b->data && (number < last_node(stack_b)->data || number > stack_b->data)))
		return (0);
	order = 0;
	while (stack_b->next)
	{
		order++;
		if (number == stack_b->next->data || stack_b->data == number || (stack_b->data >= stack_b->next->data && number > stack_b->next->data && number < stack_b->data) || (stack_b->data < stack_b->next->data && (number < stack_b->data || number > stack_b->next->data)))
			break;
		stack_b = stack_b->next;
	}
	return (order);
}

//1-rr, 2-rrr, 3-ra:rrb, 4-rra:rb
void	move_node_sorted(t_node **stack_a, t_node **stack_b, unsigned long indexes, int op)
{
	int	ia;
	int	ib;
	int	i;

	ia = right32bit(indexes);
	ib = left32bit(indexes);
	
	i = 0;
	if (op == 1)
	{
		while (i < min_of_2(ia, ib))
		{
			rotate_both(stack_a, stack_b);
			write(1, "rr\n", 3);
			i++;
		}
		while (i < ia)
		{
			rotate(stack_a);
			write(1, "ra\n", 3);
			i++;
		}
		while (i < ib)
		{
			rotate(stack_b);
			write(1, "rb\n", 3);
			i++;
		}
	}
	else if (op == 2)
	{
		while (i < min_of_2(list_size(*stack_a) - ia, list_size(*stack_b) - ib))
		{
			reverse_rotate_both(stack_a, stack_b);
			write(1, "rrr\n", 4);
			i++;
		}
		while (i < list_size(*stack_a) - ia)
		{
			r_rotate(stack_a);
			write(1, "rra\n", 4);
			i++;
		}
		while (i < list_size(*stack_b) - ib)
		{
			r_rotate(stack_b);
			write(1, "rrb\n", 4);
			i++;
		}
	}
	else if (op == 3)
	{
		while (i < ia)
		{
			rotate(stack_a);
			write(1, "ra\n", 3);
			i++;
		}
		i = 0;
		while (i < list_size(*stack_b) - ib)
		{
			r_rotate(stack_b);
			write(1, "rrb\n", 4);
			i++;
		}
	}
	else if (op == 4)
	{
		while (i < list_size(*stack_a) - ia)
		{
			r_rotate(stack_a);
			write(1, "rra\n", 4);
			i++;
		}
		i = 0;
		while (i < ib)
		{
			rotate(stack_b);
			write(1, "rb\n", 3);
			i++;
		}
	}
}

//returns the number of instructions, if fully sorted returns 0
int	find_best_solution_apply_and_print(t_node **stack_a, t_node **stack_b)
{
	unsigned long		replace_a;
	unsigned long		replace_b;
	int					i;
	t_node				*temp;
	int					as_place_in_b;
	unsigned long		min;
	unsigned long		minn;

	if (!*stack_a)
		return (0);
	if (*stack_b == NULL && (*stack_a)->next)
	{
		push(stack_a, stack_b);
		push(stack_a, stack_b);
		write(1, "pb\npb\n", 6);
		return (2);
	}
	temp = *stack_a;
	replace_a = 0;
	i = 0;
	min = INT_MAX;
	while (temp)
	{
		as_place_in_b = find_place_for_number_in_list(*stack_b, temp->data);
		minn = calculate_number_of_ops(list_size(*stack_a), i, list_size(*stack_b), as_place_in_b);
		if (right32bit(minn) < right32bit(min))
		{
			min = minn;
			replace_a = i;
			replace_b = as_place_in_b;
		}
		i++;
		temp = temp->next;
	}
	move_node_sorted(stack_a, stack_b, replace_a + (replace_b << 32), left32bit(min));
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
	return (min);
}

void	print_ops_for_linked_list(t_node **list)
{
	t_node	*stack_b;
	int		total_instruction;

	stack_b = NULL;
	if (list_size(*list) == 1)
		return ;
	while (*list)
		find_best_solution_apply_and_print(list, &stack_b);
	max_to_first_node(&stack_b);
	while (stack_b)
	{
		push(&stack_b, list);
		write(1, "pa\n", 3);
	}
	return ;
}
