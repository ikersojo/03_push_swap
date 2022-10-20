/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlst_removefront.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:07:50 by isojo-go          #+#    #+#             */
/*   Updated: 2022/10/20 17:13:43 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../inc/libft.h"

/* DESCRIPTION:
Takes as a parameter the adress of a pointer to the first element of a list of
integers and adds the element new at the end of the list.
---------------------------------------------------------------------------- */
void	ft_intlst_removefront(t_intlst **lst)
{
	if (new && *lst)
		new->next = *lst;
	else if (new)
		new->next = NULL;
	*lst = new;
}
