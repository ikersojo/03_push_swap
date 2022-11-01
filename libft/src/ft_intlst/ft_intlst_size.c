/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlst_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 10:37:46 by isojo-go          #+#    #+#             */
/*   Updated: 2022/10/30 10:40:46 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/* DESCRIPTION:
Takes as a parameter the pointer to the first element of a list of
integers and return the size of the list (number of elements).
---------------------------------------------------------------------------- */
unsigned int	ft_intlst_size(t_intlst *lst)
{
	unsigned int	size;
	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}
