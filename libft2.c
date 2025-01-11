/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:41:55 by obastug           #+#    #+#             */
/*   Updated: 2025/01/11 18:51:45 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	max_of_2(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	min_of_2(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	min_of_4(int a, int b, int c, int d)
{
	if (a < b && a < c && a < d)
		return (a);
	if (b < c && b < d)
		return (b);
	if (c < d)
		return (c);
	return (d);
}

unsigned long	which_one_is_min(int first, int second, int third, int fourth)
{
	if (first < second && first < third && first < fourth)
		return (1);
	if (second < third && second < fourth)
		return (2);
	if (third < fourth)
		return (3);
	return (4);
}
