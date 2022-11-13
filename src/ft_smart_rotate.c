/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smart_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:11:38 by isojo-go          #+#    #+#             */
/*   Updated: 2022/11/13 19:27:43 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

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
