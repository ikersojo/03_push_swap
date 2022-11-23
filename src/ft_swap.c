/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 21:02:57 by isojo-go          #+#    #+#             */
/*   Updated: 2022/11/22 22:48:12 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

void	ft_intlst_swap(t_intlst **lst)
{
	int	temp;

	if (*lst && (*lst)->next)
	{
		temp = (*lst)->value;
		(*lst)->value = (*lst)->next->value;
		(*lst)->next->value = temp;
	}
}

/*	sa (swap a):
	Swap the first 2 elements at the top of stack a. 
	Do nothing if there is only one or no elements. */
void	ft_sa(t_intlst **a)
{
	if (*a)
	{
		ft_intlst_swap(a);
		ft_putstr_fd("sa\n", 1);
	}
}

/*	sb (swap b):
	Swap the first 2 elements at the top of stack b. 
	Do nothing if there is only one or no elements. */
void	ft_sb(t_intlst **b)
{
	if (*b)
	{
		ft_intlst_swap(b);
		ft_putstr_fd("sb\n", 1);
	}
}

/*	ss : sa and sb at the same time. */
void	ft_ss(t_intlst **a, t_intlst **b)
{
	ft_intlst_swap(a);
	ft_intlst_swap(b);
	ft_putstr_fd("ss\n", 1);
}
