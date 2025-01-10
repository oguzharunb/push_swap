/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 14:17:14 by obastug           #+#    #+#             */
/*   Updated: 2025/01/10 19:35:47 by obastug          ###   ########.fr       */
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

#include <stdio.h>
#include <string.h>
int	main(int argc, char *argv[])
{
//	t_node	*stack_a;
	t_node	*stack_b;
//	int		deneme;
//
	control_args(argv + 2);
	stack_b = str_to_linked_list(argv + 2);
	if (!stack_b)
		return (1);
//	char	*argv2[5] = {strdup("2"), strdup("3"), strdup("4"), strdup("5"), NULL};
//	stack_b = str_to_linked_list((char **)argv2);
//	if (!stack_a)
//		return (1);
//	find_best_solution_apply_and_print(stack_a, stack_b);
	//int op_number = calculate_number_of_ops(5, 4, 5, 4);
	int	place = find_place_for_number_in_list(stack_b, ft_atol(argv[1]));
	print_linked_list(stack_b);
	printf("%d's place is %d\n", ft_atol(argv[1]), place);
	return (0);
}
