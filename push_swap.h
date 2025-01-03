/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 14:18:43 by obastug           #+#    #+#             */
/*   Updated: 2025/01/03 17:30:30 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


typedef struct	s_node
{
	int		data;
	t_node	*next;
}	t_node;

t_node	*second_from_last_node(t_node *list_first_elem);
t_node	*last_node(t_node *list_first_elem);

int		r_rotate(t_node **stack);
int		rotate(t_node **stack);
int		push(t_node **stack_from, t_node **stack_to);
int		swap(t_node **stack);