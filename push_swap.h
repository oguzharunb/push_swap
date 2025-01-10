/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 14:18:43 by obastug           #+#    #+#             */
/*   Updated: 2025/01/10 19:19:00 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}	t_node;

t_node	*second_from_last_node(t_node *list_first_elem);
t_node	*last_node(t_node *list_first_elem);
void	add_to_list(t_node **list, t_node *new_node);
t_node	*create_node(int number);
void	free_linked_list(t_node *list);
void	print_linked_list(t_node *list);
int		list_size(t_node *list);

void	r_rotate(t_node **stack);
void	rotate(t_node **stack);
void	push(t_node **stack_from, t_node **stack_to);
void	swap(t_node **stack);

void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putnbr(int n);
int		ft_strlen(const char *str);
char	**ft_split(char const *s, char c);
int		ft_atol(const char *nptr);

int		find_best_solution_apply_and_print(t_node *stack_a, t_node *stack_b);
int		find_place_for_number_in_list(t_node *stack_b, int number);
int		calculate_number_of_ops(int stack_a_size, int index_a, int stack_b_size, int index_b);
#endif