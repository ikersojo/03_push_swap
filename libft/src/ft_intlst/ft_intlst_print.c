/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlst_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 22:20:04 by isojo-go          #+#    #+#             */
/*   Updated: 2022/10/20 19:44:19 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"
#include <stdio.h>

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
		ft_putchar_fd('\n', 1);
		lst = next_item;
	}
}
