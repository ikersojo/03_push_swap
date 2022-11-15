/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 22:19:26 by isojo-go          #+#    #+#             */
/*   Updated: 2022/10/15 23:47:12 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static void	init_params(unsigned int *n, unsigned int *i, int *sign)
{
	*n = 0;
	*i = 0;
	*sign = 1;
}

/* DESCRIPTION:
The function tests for a valid integer in a full null terminated string.
Returns zero if the character tests false and returns non-zero if tests true.
---------------------------------------------------------------------------- */
int	ft_isint(char *s)
{
	unsigned int	n;
	unsigned int	i;
	int				sign;

	init_params(&n, &i, &sign);
	if (*(s + i) == '+' || *(s + i) == '-')
	{
		if (*(s + i++) == '-')
			sign = -1;
	}
	while (*(s + i))
	{
		if (ft_isdigit(*(s + i)))
		{
			if (n >= 214748364 && (sign == -1 && *(s + i) > '8'))
				return (0);
			if (n >= 214748364 && (sign == 1 && *(s + i) > '7'))
				return (0);
			n = n * 10 + (*(s + i++) - '0');
		}
		else
			return (0);
	}
	return (1);
}
