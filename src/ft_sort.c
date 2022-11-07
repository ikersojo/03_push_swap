/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:55:08 by isojo-go          #+#    #+#             */
/*   Updated: 2022/11/07 20:51:09 by isojo-go         ###   ########.fr       */
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
	if (ft_intlst_minval(lst) > target)
		return (0); // realmente es uno pero como lo uso de contador, lo dejo en cero mvtos
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

void	ft_move_min(t_intlst **src, t_intlst **dst, unsigned int min)
{
	t_intlst	*tmp;
	int			rotate_src;
	int			rotate_dst;

	tmp = *src;
	while (tmp)
	{
		if (tmp->cost == min)
		{
			rotate_src = tmp->src_pos_cost;
			rotate_dst = tmp->dst_pos_cost;
			ft_smart_rotate_a(src, rotate_src);
			ft_smart_rotate_b(dst, rotate_dst);
			ft_pb(src, dst);
			if ((*dst)->value < ft_intlst_last(*dst)->value)
				ft_rrb(dst); // esta parte de aquí tengo que pulirla, cuando esté de humor...
			// else
			// 	ft_rrb(dst);
			return ;
		}
		tmp = tmp->next;
	}
}

void ft_sort_big(t_intlst **a, t_intlst **b, int n)
{
	// t_intlst 		*tmp;
	unsigned int	min;
	unsigned int	i;

	(void)n;
	i = 3;
	while (i--)
		ft_pb(a, b);
	ft_revsort_3(b);
	while (*a)
	{
		ft_putstr_fd("a:\n-------\n", 1);
		ft_intlst_print(*a);
		ft_putstr_fd("-------\n\n", 1);
		ft_putstr_fd("b:\n-------\n", 1);
		ft_intlst_print(*b);
		ft_putstr_fd("-------\n\n", 1);

		min = ft_derive_cost(a, b);
		ft_move_min(a, b, min);
	}
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
