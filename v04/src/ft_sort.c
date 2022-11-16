/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:55:08 by isojo-go          #+#    #+#             */
/*   Updated: 2022/11/13 19:26:59 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

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
