/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:24:07 by isojo-go          #+#    #+#             */
/*   Updated: 2022/11/15 17:59:23 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

static int	ft_get_dstcost_min_first(t_intlst *lst)
{
	unsigned int	current_pos;
	unsigned int	size;
	int				rotate;
	int				min;

	min = ft_intlst_minval(lst);
	if (min == (lst)->value)
		return (0);
	size = ft_intlst_size(lst);
	current_pos = 0;
	while (lst)
	{
		if (lst->value == min)
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

static int	ft_get_dstcost(t_intlst *lst, int target)
{
	unsigned int	cost;
	unsigned int	current_pos;
	unsigned int	size;

	if (lst->value > target && ft_intlst_last(lst)->value < target)
		return (0);
	if ((ft_intlst_maxval(lst) < target) || (ft_intlst_minval(lst) > target))
		return (ft_get_dstcost_min_first(lst)); // BUG
	size = ft_intlst_size(lst);
	current_pos = 0;
	cost = 0;
	while (lst)
	{
		cost++;
		if (lst->value < target && lst->next->value > target)
		{
			if (current_pos < ((size / 2) + 1))
				return (cost);
			return (current_pos - size + 1);
		}
		current_pos++;
		lst = lst->next;
	}
	return (0);
}

static int	ft_get_dstcost_chunks(t_intlst *lst, unsigned int target)
{
	unsigned int	cost;
	unsigned int	current_pos;
	unsigned int	size;

	if (lst->chunk > target && ft_intlst_last(lst)->chunk < target)
		return (0);
	// if ((ft_intlst_maxval(lst) < target) || (ft_intlst_minval(lst) > target))
	// 	return (ft_get_dstcost_min_first(lst)); // BUG
	size = ft_intlst_size(lst);
	current_pos = 0;
	cost = 0;
	while (lst)
	{
		cost++;
		if (lst->chunk < target && lst->next->chunk > target)
		{
			if (current_pos < ((size / 2) + 1))
				return (cost);
			return (current_pos - size + 1);
		}
		current_pos++;
		lst = lst->next;
	}
	return (0);
}

static unsigned int	ft_derive_cost(t_intlst **src, t_intlst **dst)
{
	t_intlst		*tmp;
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

static unsigned int	ft_derive_cost_chunks(t_intlst **src, t_intlst **dst)
{
	t_intlst		*tmp;
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
		ft_visualize_stacks(src, dst); // DEBUG <----------------------------------------
		tmp->dst_pos_cost = ft_get_dstcost_chunks(*dst, tmp->chunk);
		tmp->cost = 1 + ft_abs(tmp->src_pos_cost) + ft_abs(tmp->dst_pos_cost);
		if (tmp->cost < min)
			min = tmp->cost;
		current_pos++;
		tmp = tmp->next;
	}
	return (min);
}

static void	ft_move_min_to_a(t_intlst **a, t_intlst **b, unsigned int min)
{
	t_intlst	*tmp;
	int			rotate_a;
	int			rotate_b;

	tmp = *b;
	while (tmp)
	{
		if (tmp->cost == min)
		{
			rotate_b = tmp->src_pos_cost;
			rotate_a = tmp->dst_pos_cost;
			ft_smart_rotate_a(a, rotate_a);
			ft_smart_rotate_b(b, rotate_b);
			ft_pa(a, b);
			if (ft_intlst_maxval(*a) == (*a)->value)
				ft_ra(a);
			return ;
		}
		tmp = tmp->next;
	}
}

static void	ft_move_min_to_b(t_intlst **a, t_intlst **b, unsigned int min)
{
	t_intlst	*tmp;
	int			rotate_a;
	int			rotate_b;

	tmp = *a;
	while (tmp)
	{
		if (tmp->cost == min)
		{
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

static unsigned int	ft_derive_chunks(t_intlst **src, t_intlst **dst)
{

	t_intlst	*tmp;
	int			max;
	int			min;
	int			chunk_size;
	int			i;

	tmp = *src;
	max = ft_intlst_maxval(*src);
	min = ft_intlst_minval(*src);
	chunk_size = (max - min) / 10;
	ft_printf("MAX = %d ; MIN = %d\n", max, min); // DEBUG <-------------
	while (tmp)
	{
		i = 0;
		while (i < (10 - 1))
		{
			if (tmp->value > (max - chunk_size * ( i + 1)) && tmp->value > (max - chunk_size * i))
			{
				tmp->chunk = i;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
	ft_pb(src, dst);
	ft_pb(src, dst);
	ft_pb(src, dst);
	ft_revsort_3_b(dst);
	return (min);
}

void	ft_sort_big(t_intlst **a, t_intlst **b, int n)
{
	unsigned int	min;

	ft_derive_chunks(a, b);
	while ((n--) > 3) // Sustitur este paso a b por bloques
	{
		min = ft_derive_cost_chunks(a, b);
		ft_visualize_stacks(a, b); //DEBUG
		ft_move_min_to_b(a, b, min);
	}
	ft_sort_3_a(a);
	while (*b)
	{
		min = ft_derive_cost(b, a);
		// ft_visualize_stacks(a, b); //DEBUG
		ft_move_min_to_a(a, b, min);
	}
	ft_smart_rotate_a(a, ft_get_dstcost_min_first(*a));
}
