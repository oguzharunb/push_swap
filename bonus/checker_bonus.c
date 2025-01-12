/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:27:19 by obastug           #+#    #+#             */
/*   Updated: 2025/01/12 13:59:26 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include <stdlib.h>
#include <unistd.h>

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

void	read_and_apply(t_node **stack_a, t_node **stack_b)
{
	char	buffer[10];
	int		ret;

	while (1)
	{
		ret = read(STDIN_FILENO, buffer, 5);
		if (!ret)
			return ;
		if (*buffer == '\n')
			return ;
		buffer[ret] = '\0';
		if (!apply_operation(stack_a, stack_b, buffer))
		{
			free_linked_list(*stack_a);
			free_linked_list(*stack_b);
			write(2, "Error\n", 6);
			exit(1);
		}
	}
}

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;

	if (argc == 1)
		return (1);
	control_args(argv + 1);
	stack_a = str_to_linked_list(argv + 1);
	if (is_there_duplicate(stack_a))
	{
		free_linked_list(stack_a);
		write(STDERR_FILENO, "Error\n", 6);
		return (1);
	}
	stack_b = NULL;
	read_and_apply(&stack_a, &stack_b);
	if (check_is_sorted(stack_a, stack_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_linked_list(stack_a);
	free_linked_list(stack_b);
	return (0);
}
