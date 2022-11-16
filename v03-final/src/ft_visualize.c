/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visualize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:54:24 by isojo-go          #+#    #+#             */
/*   Updated: 2022/11/08 22:01:25 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

void	ft_visualize_stacks(t_intlst **a, t_intlst **b)
{
	ft_putstr_fd("\n############################################\n", 1);
	ft_putstr_fd("a:\n-------\n", 1);
	ft_intlst_print(*a);
	ft_putstr_fd("-------\n\n", 1);
	ft_putstr_fd("b:\n-------\n", 1);
	ft_intlst_print(*b);
	ft_putstr_fd("-------\n", 1);
	ft_putstr_fd("##########################################\n\n", 1);
}
