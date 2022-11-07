/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlst_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 22:20:04 by isojo-go          #+#    #+#             */
/*   Updated: 2022/11/05 11:10:17 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/* DESCRIPTION:
Takes as a parameter the adress of a pointer to the first element of a list of
integers and prints all elements of the list.
---------------------------------------------------------------------------- */
void	ft_intlst_print(t_intlst *lst)
{
	t_intlst	*next_item;

	while (lst)
	{
		next_item = lst->next;
		ft_putnbr_fd((lst->value), 1);
		ft_putstr_fd(" -> cost: ", 1); // DEBUG <--------
		ft_putnbr_fd((lst->cost), 1); // DEBUG <--------
		ft_putstr_fd(" -> src cost: ", 1); // DEBUG <--------
		ft_putnbr_fd((lst->src_pos_cost), 1); // DEBUG <--------
		ft_putstr_fd(" + push cost: 1 + dst cost: ", 1); // DEBUG <--------
		ft_putnbr_fd((lst->dst_pos_cost), 1); // DEBUG <--------
		ft_putchar_fd('\n', 1);
		lst = next_item;
	}
}
