/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:48:15 by isojo-go          #+#    #+#             */
/*   Updated: 2022/10/29 17:27:18 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

static void	ft_pushtob_minmax(t_intlst **a, t_intlst **b, int n)
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

static void	ft_pushback_minmax(t_intlst **a, t_intlst **b, int n)
{
	ft_pa(a, b);
	if (!ft_intlst_issorted(*a))
		ft_ra(a);
	if (n == 4)
		return ;
	ft_pa(a, b);
	if (!ft_intlst_issorted(*a))
		ft_ra(a);
}

void	ft_sort_5(t_intlst **a, t_intlst **b, int n)
{
	ft_pushtob_minmax(a, b, n);
	ft_sort_3(a);
	ft_pushback_minmax(a, b, n);
}
