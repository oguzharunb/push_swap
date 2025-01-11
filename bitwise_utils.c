/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitwise_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:40:14 by obastug           #+#    #+#             */
/*   Updated: 2025/01/11 18:40:20 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long	left32bit(unsigned long number)
{
	return (number >> 32);
}

unsigned long	right32bit(unsigned long number)
{
	return ((number << 32) >> 32);
}
