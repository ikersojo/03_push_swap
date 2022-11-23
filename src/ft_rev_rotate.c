/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 21:03:24 by isojo-go          #+#    #+#             */
/*   Updated: 2022/11/22 22:48:12 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

void	ft_intlst_reverse_rotate(t_intlst **lst)
{
	t_intlst	*first;
	t_intlst	*last;
	t_intlst	*before_last;

	if (*lst && (*lst)->next)
	{
		first = *lst;
		last = ft_intlst_last(*lst);
		before_last = ft_intlst_before_last(*lst);
		*lst = last;
		(*lst)->next = first;
		before_last->next = NULL;
	}
}

/*	rra (reverse rotate a): Shift down all elements of stack a by 1.
	The last element becomes the first one. */
void	ft_rra(t_intlst **a)
{
	if (*a)
	{
		ft_intlst_reverse_rotate(a);
		ft_putstr_fd("rra\n", 1);
	}
}

/*	rrb (reverse rotate b): Shift down all elements of stack b by 1.
	The last element becomes the first one. */
void	ft_rrb(t_intlst **b)
{
	if (*b)
	{
		ft_intlst_reverse_rotate(b);
		ft_putstr_fd("rrb\n", 1);
	}
}

/*	rrr : rra and rrb at the same time. */
void	ft_rrr(t_intlst **a, t_intlst **b)
{
	ft_intlst_reverse_rotate(a);
	ft_intlst_reverse_rotate(b);
	ft_putstr_fd("rrr\n", 1);
}
