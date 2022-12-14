/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 21:02:47 by isojo-go          #+#    #+#             */
/*   Updated: 2022/11/22 22:46:58 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

void	ft_intlst_push(t_intlst **src, t_intlst **dst)
{
	t_intlst	*temp;

	if (*src)
	{
		temp = (*src)->next;
		(*src)->next = *dst;
		*dst = *src;
		*src = temp;
	}	
}

/*	pa (push a): Take first element at the top of b and put it at the top of a.
	Do nothing if b is empty. */
void	ft_pa(t_intlst **a, t_intlst **b)
{
	if (*b)
	{
		ft_intlst_push(b, a);
		ft_putstr_fd("pa\n", 1);
	}
}

/*	pb (push b): Take first element at the top of a and put it at the top of b.
	Do nothing if a is empty. */
void	ft_pb(t_intlst **a, t_intlst **b)
{
	if (*a)
	{
		ft_intlst_push(a, b);
		ft_putstr_fd("pb\n", 1);
	}
}
