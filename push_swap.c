/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 14:17:14 by obastug           #+#    #+#             */
/*   Updated: 2025/01/11 18:39:50 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

//returns number of elements, due to an error returns -1.
void	control_args(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		atol(argv[i]);
		i++;
	}
}

t_node	*str_to_linked_list(char **argv)
{
	int		i;
	t_node	*list;
	t_node	*temp;

	i = 0;
	list = NULL;
	while (argv[i])
	{
		temp = create_node(ft_atol(argv[i]));
		if (!temp)
			return (free_linked_list(list), NULL);
		add_to_list(&list, temp);
		i++;
	}
	return (list);
}

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		deneme;

	if (argc == 1)
		return (1);
	control_args(argv + 1);
	stack_a = str_to_linked_list(argv + 1);
	print_ops_for_linked_list(&stack_a);
	free_linked_list(stack_a);
	return (0);
}
