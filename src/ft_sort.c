/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:55:08 by isojo-go          #+#    #+#             */
/*   Updated: 2022/10/25 21:39:19 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

void	ft_sort(t_intlst **a, t_intlst **b, int n)
{
	(void) n;
	(void) a;
	(void) b;
	while (!ft_intlst_issorted(*a) && *b == NULL)
	{
		ft_putstr_fd("sorting...\n", 1);
		if (n == 3)
			ft_sort_2(a);
		if (n == 4)
			ft_sort_3(a);
	}
}
void	ft_sort_2(t_intlst **a)
{
	if ((*a)->value > (*a)->next->value)
		ft_sa(a);
}

void	ft_sort_3(t_intlst **a)
{

}