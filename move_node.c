/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:08:07 by obastug           #+#    #+#             */
/*   Updated: 2025/01/11 19:18:35 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	move_node_op1(t_node **s_a, t_node **s_b, int ia, int ib)
{
	int	i;

	i = 0;
	while (i < min_of_2(ia, ib))
	{
		rotate_both(s_a, s_b);
		write(1, "rr\n", 3);
		i++;
	}
	while (i < ia)
	{
		rotate(s_a);
		write(1, "ra\n", 3);
		i++;
	}
	while (i < ib)
	{
		rotate(s_b);
		write(1, "rb\n", 3);
		i++;
	}
}

void	move_node_op2(t_node **s_a, t_node **s_b, int ia, int ib)
{
	int	i;

	i = 0;
	while (i < min_of_2(list_size(*s_a) - ia, list_size(*s_b) - ib))
	{
		reverse_rotate_both(s_a, s_b);
		write(1, "rrr\n", 4);
		i++;
	}
	while (i < list_size(*s_a) - ia)
	{
		r_rotate(s_a);
		write(1, "rra\n", 4);
		i++;
	}
	while (i < list_size(*s_b) - ib)
	{
		r_rotate(s_b);
		write(1, "rrb\n", 4);
		i++;
	}
}

void	move_node_op3(t_node **s_a, t_node **s_b, int ia, int ib)
{
	int	i;

	i = 0;
	while (i < ia)
	{
		rotate(s_a);
		write(1, "ra\n", 3);
		i++;
	}
	i = 0;
	while (i < list_size(*s_b) - ib)
	{
		r_rotate(s_b);
		write(1, "rrb\n", 4);
		i++;
	}
}

void	move_node_op4(t_node **s_a, t_node **s_b, int ia, int ib)
{
	int	i;

	i = 0;
	while (i < list_size(*s_a) - ia)
	{
		r_rotate(s_a);
		write(1, "rra\n", 4);
		i++;
	}
	i = 0;
	while (i < ib)
	{
		rotate(s_b);
		write(1, "rb\n", 3);
		i++;
	}
}
