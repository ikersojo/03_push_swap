/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlst_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 22:20:13 by isojo-go          #+#    #+#             */
/*   Updated: 2022/10/15 22:38:04 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/* DESCRIPTION:
Takes as a parameter the adress of a pointer to the first element of a list of
integers and frees all elements of the list.
---------------------------------------------------------------------------- */
void	ft_intlst_free(t_intlst **lst)
{
	t_intlst	*next_item;

	while (*lst)
	{
		next_item = (*lst)->next;
		free(*lst);
		*lst = next_item;
	}
}
