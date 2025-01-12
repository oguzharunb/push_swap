/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:22:06 by obastug           #+#    #+#             */
/*   Updated: 2025/01/12 13:56:47 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <stddef.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}	t_node;

char			**ft_split(char const *s, char c);
void			ft_bzero(void *s, size_t n);
int				ft_strcmp(char *s1, char *s2);
long			ft_atol(const char *nptr);
void			ft_putnbr(int n);
void			ft_putchar(char c);
int				ft_strlen(const char *str);

t_node			*second_from_last_node(t_node *list_first_elem);
t_node			*last_node(t_node *list_first_elem);
void			add_to_list(t_node **list, t_node *new_node);
t_node			*create_node(int number);
void			free_linked_list(t_node *list);
void			print_linked_list(t_node *list);
int				list_size(t_node *list);
void			max_to_first_node(t_node **stack);
int				is_there_duplicate(t_node *stack);
int				check_is_sorted(t_node *stack_a, t_node *stack_b);

void			r_rotate(t_node **stack);
void			rotate(t_node **stack);
void			push(t_node **stack_from, t_node **stack_to);
void			swap(t_node **stack);
void			swap_both(t_node **stack_a, t_node **stack_b);
void			rotate_both(t_node **stack_a, t_node **stack_b);
void			reverse_rotate_both(t_node **stack_a, t_node **stack_b);
int				apply_operation(t_node **stack_a, t_node **stack_b, char *op);
#endif