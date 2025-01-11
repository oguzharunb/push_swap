/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 14:18:43 by obastug           #+#    #+#             */
/*   Updated: 2025/01/11 19:21:14 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}	t_node;

t_node			*second_from_last_node(t_node *list_first_elem);
t_node			*last_node(t_node *list_first_elem);
void			add_to_list(t_node **list, t_node *new_node);
t_node			*create_node(int number);
void			free_linked_list(t_node *list);
void			print_linked_list(t_node *list);
int				list_size(t_node *list);
void			max_to_first_node(t_node **stack);

void			r_rotate(t_node **stack);
void			rotate(t_node **stack);
void			push(t_node **stack_from, t_node **stack_to);
void			swap(t_node **stack);
void			swap_both(t_node **stack_a, t_node **stack_b);
void			rotate_both(t_node **stack_a, t_node **stack_b);
void			reverse_rotate_both(t_node **stack_a, t_node **stack_b);

void			move_node_op1(t_node **s_a, t_node **s_b, int ia, int ib);
void			move_node_op2(t_node **s_a, t_node **s_b, int ia, int ib);
void			move_node_op3(t_node **s_a, t_node **s_b, int ia, int ib);
void			move_node_op4(t_node **s_a, t_node **s_b, int ia, int ib);

void			ft_putchar(char c);
void			ft_putstr(char *s);
void			ft_putnbr(int n);
int				ft_strlen(const char *str);
char			**ft_split(char const *s, char c);
int				ft_atol(const char *nptr);
int				min_of_2(int a, int b);
int				max_of_2(int a, int b);
unsigned long	which_one_is_min(int first, int second, int third, int fourth);
int				min_of_4(int a, int b, int c, int d);
unsigned long	right32bit(unsigned long number);
unsigned long	left32bit(unsigned long number);

int				apply_and_print(t_node **a, t_node **b, int i, __u_long r_a);
int				find_place_for_number_in_list(t_node *stack_b, int number);
unsigned long	min_number_of_ops(int a_size, int ia, int b_size, int ib);
void			print_ops_for_linked_list(t_node **list);

#endif