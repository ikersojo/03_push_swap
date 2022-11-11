/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:55:08 by isojo-go          #+#    #+#             */
/*   Updated: 2022/11/11 14:01:14 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

int	ft_get_dstcost_max_first(t_intlst *lst)
{
	unsigned int	current_pos;
	unsigned int	size;
	int				rotate;
	int				max;

	max = ft_intlst_maxval(lst);
	if (max == (lst)->value)
		return (0);
	size = ft_intlst_size(lst);
	current_pos = 0;
	while (lst)
	{
		if (lst->value == max)
		{
			if (current_pos < (size / 2 + 1))
				rotate = current_pos;
			else
				rotate = current_pos - size;
		}
		current_pos++;
		lst = lst->next;
	}
	return (rotate);
}

int	ft_get_dstcost(t_intlst *lst, int target)
{
	unsigned int	cost;
	unsigned int	current_pos;
	unsigned int	size;

	if (lst->value < target && ft_intlst_last(lst)->value > target)
		return (0);
	if ((ft_intlst_maxval(lst) < target) || (ft_intlst_minval(lst) > target))
		return (ft_get_dstcost_max_first(lst));
	size = ft_intlst_size(lst);
	current_pos = 0;
	cost = 0;
	while (lst)
	{
		cost++;
		if (lst->value > target && lst->next->value < target)
		{
			if (current_pos < ((size / 2) + 1))
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
		if (current_pos < (size / 2 + 1))
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

void	ft_smart_rotate_a(t_intlst **lst, int cost)
{
	while (cost != 0)
	{
		if (cost > 0)
		{
			ft_ra(lst);
			cost--;
		}
		else
		{
			ft_rra(lst);
			cost++;
		}
	}
}

void	ft_smart_rotate_b(t_intlst **lst, int cost)
{
	while (cost != 0)
	{
		if (cost > 0)
		{
			ft_rb(lst);
			cost--;
		}
		else
		{
			ft_rrb(lst);
			cost++;
		}
	}
}

void	ft_move_min(t_intlst **a, t_intlst **b, unsigned int min)
{
	t_intlst	*tmp;
	int			rotate_a;
	int			rotate_b;

	tmp = *a;
	while (tmp)
	{
		if (tmp->cost == min)
		{
			// ft_printf("         %d\n", min); // DEBUG
			rotate_a = tmp->src_pos_cost;
			rotate_b = tmp->dst_pos_cost;
			ft_smart_rotate_a(a, rotate_a);
			ft_smart_rotate_b(b, rotate_b);
			ft_pb(a, b);
			if (ft_intlst_minval(*b) == (*b)->value)
				ft_rb(b);
			return ;
		}
		tmp = tmp->next;
	}
}

void	ft_max_first_b(t_intlst **lst)
{
	t_intlst 		*tmp;
	unsigned int	current_pos;
	unsigned int	size;
	int				rotate;
	int				max;

	max = ft_intlst_maxval(*lst);
	if (max == (*lst)->value)
		return ;
	size = ft_intlst_size(*lst);
	current_pos = 0;
	tmp = *lst;
	while (tmp)
	{
		if (tmp->value == max)
		{
			if (current_pos < (size / 2 + 1))
				rotate = current_pos;
			else
				rotate = current_pos - size;
		}
		current_pos++;
		tmp = tmp->next;
	}
	ft_smart_rotate_b(lst, rotate);
}

void	ft_sort_big(t_intlst **a, t_intlst **b, int n)
{
	unsigned int	min;
	unsigned int	i;

	i = 3;
	while (i--)
		ft_pb(a, b);
	ft_revsort_3(b);
	while (*a)
	{
		min = ft_derive_cost(a, b);
		ft_move_min(a, b, min);
	}
	ft_max_first_b(b);
	while (n--)
		ft_pa(a, b);
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
