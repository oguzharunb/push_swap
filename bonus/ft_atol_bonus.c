/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:46:47 by obastug           #+#    #+#             */
/*   Updated: 2025/01/11 21:34:39 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	register size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}

static void	between_int_max_and_min(long value)
{
	if (value > INT_MAX || value < INT_MIN)
	{
		write(STDERR_FILENO, "Error\n", 6);
		exit(1);
	}
}

static void	if_not_null_exit(char c)
{
	if (c)
	{
		write(STDERR_FILENO, "Error\n", 6);
		exit(1);
	}
}

// all characters has to be a numeric, number is between INT_MIN 
//and INT_MAX, both included. otherwise it will exit.
long	ft_atol(const char *nptr)
{
	register int	i;
	register long	ret;
	char			sign;

	ret = 0;
	i = 0;
	sign = 1;
	while (nptr[i] == ' ' || nptr[i] == '\t')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		ret = (ret * 10) + (nptr[i] - '0');
		between_int_max_and_min(ret);
		i++;
	}
	if_not_null_exit(nptr[i]);
	return (ret * sign);
}
