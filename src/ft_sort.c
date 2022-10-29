/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:55:08 by isojo-go          #+#    #+#             */
/*   Updated: 2022/10/29 12:43:52 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

void	ft_sort_2(t_intlst **lst)
{
	if ((*lst)->value > (*lst)->next->value)
		ft_sa(lst);
}

void	ft_sort_3(t_intlst **lst)
{
	int	a;
	int	b;
	int	c;

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

int	ft_intlst_maxval(t_intlst *lst)
{
	int	max;

	max = -2147483648;
	while (lst)
	{
		if (lst->value > max)
			max = lst->value;
		lst = lst->next;
	}
	return (max);
}

int	ft_intlst_minval(t_intlst *lst)
{
	int	min;

	min = 2147483647;
	while (lst)
	{
		if (lst->value < min)
			min = lst->value;
		lst = lst->next;
	}
	return (min);
}

void	ft_pushtob_minmax(t_intlst **a, t_intlst **b, int n)
{
	int	max;
	int	min;
	int	last;
	int	i;

	max = ft_intlst_maxval(*a);
	min = ft_intlst_minval(*a);
	i = 0;
	while (i < (n - 3))
	{
		last = ft_intlst_last(*a)->value;
		if ((*a)->value == max || (*a)->value == min)
		{
			ft_pb(a, b);
			i++;
		}
		else if (last == max || last == min)
			ft_rra(a);
		else
			ft_ra(a);
	}	
}

void	ft_pushback_minmax(t_intlst **a, t_intlst **b, int n)
{
	int	min;

	min = ft_intlst_minval(*b);
	if (n == 4)
		ft_pa(a, b);
	else
	{
		if ((*b)->value == min)
		{
			ft_pa(a, b);
			ft_pa(a, b);
			ft_ra(a);
		}
		else
		{
			ft_pa(a, b);
			ft_ra(a);
			ft_pa(a, b);
		}
	}	
}

void	ft_sort_5(t_intlst **a, t_intlst **b, int n)
{
	ft_pushtob_minmax(a, b, n);
	ft_sort_3(a);
	ft_pushback_minmax(a, b, n);
}

void	ft_sort(t_intlst **a, t_intlst **b, int n)
{
	while (!ft_intlst_issorted(*a) && *b == NULL)
	{
		if (n == 2)
			ft_sort_2(a);
		else if (n == 3)
			ft_sort_3(a);
		else if (n == 4 || n == 5)
			ft_sort_5(a, b, n);
	}
}
