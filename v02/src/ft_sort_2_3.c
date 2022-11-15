/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_2_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:49:28 by isojo-go          #+#    #+#             */
/*   Updated: 2022/11/15 17:59:23 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

void	ft_sort_2(t_intlst **lst)
{
	if ((*lst)->value > (*lst)->next->value)
		ft_sa(lst);
}

void	ft_sort_3_a(t_intlst **lst)
{
	int	a;
	int	b;
	int	c;

	while (!ft_intlst_issorted(*lst))
	{
		a = (*lst)->value;
		b = (*lst)->next->value;
		c = (*lst)->next->next->value;
		if (a < c)
			ft_sa(lst);
		else
		{
			if (b > a)
				ft_rra(lst);
			else
				ft_ra(lst);
		}
	}
}

void	ft_revsort_2(t_intlst **lst)
{
	if ((*lst)->value < (*lst)->next->value)
		ft_sa(lst);
}

void	ft_revsort_3_b(t_intlst **lst)
{
	int	a;
	int	b;
	int	c;

	while (!ft_intlst_isrevsorted(*lst))
	{
		a = (*lst)->value;
		b = (*lst)->next->value;
		c = (*lst)->next->next->value;
		if (a > c)
			ft_sb(lst);
		else
		{
			if (b < a)
				ft_rrb(lst);
			else
				ft_rb(lst);
		}
	}
}
