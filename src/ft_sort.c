/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:55:08 by isojo-go          #+#    #+#             */
/*   Updated: 2022/11/01 08:15:53 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

unsigned int	ft_get_dstcost(t_intlst *lst, int target)
{
	unsigned int	cost;
	unsigned int	pos;

	if (ft_intlst_maxval(lst) < target)
		return (0);
	if (lst->value < target && ft_intlst_last(lst)->value > target)
		return (0);
	while (lst)
	{
		cost++;
		if (lst->value > target && lst->next->value < target)
			return (cost);
		lst = lst->next;
	}
	return (0);
}

void	ft_derive_cost(t_intlst **src, t_intlst **dst)
{
	t_intlst 		*tmp;
	unsigned int	pos;
	unsigned int	src_pos_cost;
	unsigned int	size;

	tmp = *src;
	pos = 0;
	size = ft_intlst_size(*src);
	while (tmp)
	{
		if (pos < size / 2)
			src_pos_cost = pos;
		else
			src_pos_cost = size - pos;
		tmp->cost = 1 + src_pos_cost + ft_get_dstcost(*dst, tmp->value);
		pos++;
		tmp = tmp->next;
	}
}

void ft_sort_big(t_intlst **a, t_intlst **b, int n)
{
	ft_derive_cost(a, b);
}



void	ft_sort(t_intlst **a, t_intlst **b, int n)
{
	if (!ft_intlst_issorted(*a))
	{
		if (n == 2)
			ft_sort_2(a);
		else if (n == 3)
			ft_sort_3(a);
		else if (n == 4 || n == 5)
			ft_sort_5(a, b, n);
		else
			ft_sort_big(a, b, n);
	}
}
