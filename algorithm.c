/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:51:06 by obastug           #+#    #+#             */
/*   Updated: 2025/01/11 19:44:13 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <unistd.h>
// in a list {1,2,3,5} and input 4
// it will return index 3 (5 will be pushed to 4 from 3)

// push excluded
unsigned long	min_number_of_ops(int a_size, int ia, int b_size, int ib)
{
	int				b_diff;
	int				a_diff;
	int				rr_use;
	int				r_use;
	unsigned long	ret;

	a_diff = a_size - ia;
	b_diff = b_size - ib;
	rr_use = a_diff;
	if (b_diff > a_diff)
		rr_use = b_diff;
	r_use = ia;
	if (ib > ia)
		r_use = ib;
	ret = min_of_4(r_use, rr_use, ia + b_diff, ib + a_diff);
	ret += which_one_is_min(r_use, rr_use, ia + b_diff, ib + a_diff) << 32;
	return (ret);
}

// it returns correctly till its a sorted linked list
int	find_place_for_number_in_list(t_node *s_b, int number)
{
	t_node	*temp;
	int		order;

	if (number == s_b->data || last_node(s_b)->data == number
		|| (last_node(s_b)->data >= s_b->data && number > s_b->data
			&& number < last_node(s_b)->data) || (last_node(s_b)->data
			< s_b->data && (number < last_node(s_b)->data
				|| number > s_b->data)))
		return (0);
	order = 0;
	while (s_b->next)
	{
		order++;
		if (number == s_b->next->data || s_b->data == number
			|| (s_b->data >= s_b->next->data && number
				> s_b->next->data && number < s_b->data)
			|| (s_b->data < s_b->next->data && (number
					< s_b->data || number > s_b->next->data)))
			break ;
		s_b = s_b->next;
	}
	return (order);
}

//1-rr, 2-rrr, 3-ra:rrb, 4-rra:rb
void	move_node_sorted(t_node **s_a, t_node **s_b, unsigned long is, int op)
{
	int	ia;
	int	ib;
	int	i;

	ia = right32bit(is);
	ib = left32bit(is);
	i = 0;
	if (op == 1)
		move_node_op1(s_a, s_b, ia, ib);
	else if (op == 2)
		move_node_op2(s_a, s_b, ia, ib);
	else if (op == 3)
		move_node_op3(s_a, s_b, ia, ib);
	else if (op == 4)
		move_node_op4(s_a, s_b, ia, ib);
	push(s_a, s_b);
	write(1, "pb\n", 3);
}

//returns the number of instructions, if fully sorted returns 0
// function(stack_a, stack_b, 0, 0)
int	apply_and_print(t_node **s_a, t_node **s_b, int i, unsigned long replace_a)
{
	unsigned long		replace_b;
	t_node				*temp;
	int					a_to_b;
	unsigned long		min;
	unsigned long		minn;

	if (!*s_a)
		return (0);
	temp = *s_a;
	min = INT_MAX;
	while (temp)
	{
		a_to_b = find_place_for_number_in_list(*s_b, temp->data);
		minn = min_number_of_ops(list_size(*s_a), i, list_size(*s_b), a_to_b);
		if (right32bit(minn) < right32bit(min))
		{
			min = minn;
			replace_a = i;
			replace_b = a_to_b;
		}
		i++;
		temp = temp->next;
	}
	move_node_sorted(s_a, s_b, replace_a + (replace_b << 32), left32bit(min));
	return (min);
}

void	print_ops_for_linked_list(t_node **list)
{
	t_node	*s_b;
	int		total_instruction;

	s_b = NULL;
	if (list_size(*list) == 1)
		return ;
	if (s_b == NULL && (*list)->next)
	{
		push(list, &s_b);
		push(list, &s_b);
		write(1, "pb\npb\n", 6);
	}
	while (*list)
	{
		apply_and_print(list, &s_b, 0, 0);
	}
	max_to_first_node(&s_b);
	while (s_b)
	{
		push(&s_b, list);
		write(1, "pa\n", 3);
	}
	return ;
}
