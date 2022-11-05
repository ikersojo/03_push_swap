/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:55:08 by isojo-go          #+#    #+#             */
/*   Updated: 2022/11/05 09:37:57 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

int	ft_get_dstcost(t_intlst *lst, int target)
{
	unsigned int	cost;
	unsigned int	current_pos;
	unsigned int	size;

	if (ft_intlst_maxval(lst) < target)
		return (0);
	if (lst->value < target && ft_intlst_last(lst)->value > target)
		return (0);
	size = ft_intlst_size(lst);
	current_pos = 0;
	cost = 0;
	while (lst)
	{
		cost++;
		if (lst->value > target && lst->next->value < target)
		{
			if (current_pos < size / 2)
				return (cost);
			return (current_pos - size);
		}
		current_pos++;
		lst = lst->next;
	}
	return (0);
}

unsigned int	ft_derive_cost(t_intlst **src, t_intlst **dst)
{
	t_intlst 		*tmp;
	unsigned int	current_pos;
	unsigned int	size;
	unsigned int	min;

	tmp = *src;
	current_pos = 0;
	min = 4294967295;
	size = ft_intlst_size(*src);
	while (tmp)
	{
		if (current_pos < size / 2)
			tmp->src_pos_cost = current_pos;
		else
			tmp->src_pos_cost = current_pos - size;
		tmp->dst_pos_cost = ft_get_dstcost(*dst, tmp->value);
		tmp->cost = 1 + ft_abs(tmp->src_pos_cost) + ft_abs(tmp->dst_pos_cost);
		if (tmp->cost < min)
			min = tmp->cost;
		current_pos++;
		tmp = tmp->next;
	}
	return (min);
}

void ft_sort_big(t_intlst **a, t_intlst **b, int n)
{
	// t_intlst 		*tmp;
	unsigned int	min;

	(void)n;
	min = ft_derive_cost(a, b);
	ft_putstr_fd("minimum cost = ", 1); // DEBUG
	ft_putnbr_fd(min, 1);
	ft_putchar_fd('\n', 1);
	// tmp = *a;
	//while !(a lleno y b ordenado al reves)
	// while (tmp)
	// {
	// 	if (tmp->cost == min)
	// 	{
	// 		rotate_src = tmp->src_pos_cost;
	// 		rotate_dst = tmp->dst_pos_cost;
	// 		while (rotate > 0)
	// 		{
	// 			if (tmp->rev == 0)
	// 				ra(a);
	// 			else
	// 				rra(a);
	// 		}
	// 		pb(a, b);
	// 	}
	// 	tmp = tmp->next;
	// }
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
