/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 07:40:06 by isojo-go          #+#    #+#             */
/*   Updated: 2022/10/25 07:57:59 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "../libft/inc/libft.h"

void	ft_pa(t_intlst **b, t_intlst **a);
void	ft_pb(t_intlst **a, t_intlst **b);
void	ft_sa(t_intlst **a);
void	ft_sb(t_intlst **b);
void	ft_ss(t_intlst **a, t_intlst **b);
void	ft_ra(t_intlst **a);
void	ft_rb(t_intlst **b);
void	ft_rr(t_intlst **a, t_intlst **b);
void	ft_rra(t_intlst **a);
void	ft_rrb(t_intlst **b);
void	ft_rrr(t_intlst **a, t_intlst **b);

#endif