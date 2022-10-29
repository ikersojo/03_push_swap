/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:55:08 by isojo-go          #+#    #+#             */
/*   Updated: 2022/10/29 09:55:05 by isojo-go         ###   ########.fr       */
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
	ft_printf("a = %d\nb = %d\nc = %d\n", a, b, c);  // <-- DEBUG
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

void	ft_sort(t_intlst **a, t_intlst **b, int n)
{
	while (!ft_intlst_issorted(*a) && *b == NULL)
	{
		ft_putstr_fd("sorting...\n", 1); // <-- DEBUG
		if (n == 3)
			ft_sort_2(a);
		if (n == 4)
			ft_sort_3(a);
	}
}
