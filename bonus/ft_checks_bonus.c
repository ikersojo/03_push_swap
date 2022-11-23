/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:09:34 by isojo-go          #+#    #+#             */
/*   Updated: 2022/11/23 16:09:28 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

static char	*ft_get_inst(void)
{
	char	*str;
	int		bytes;
	int		i;
	char	c;

	str = (char *)malloc(24001);
	i = 0;
	while (i < 24000)
	{
		bytes = read(1, &c, 1);
		if (bytes == 0)
			break ;
		*(str + i++) = c;
	}
	*(str + i) = '\0';
	return (str);
}

static int	ft_is_inst_aux(char *str, t_intlst **a, t_intlst **b)
{
	if (ft_strcmp(str, "pa") == 0)
		ft_intlst_push(b, a);
	else if (ft_strcmp(str, "pb") == 0)
		ft_intlst_push(a, b);
	else if (ft_strcmp(str, "sa") == 0)
		ft_intlst_swap(a);
	else if (ft_strcmp(str, "sb") == 0)
		ft_intlst_swap(b);
	else if (ft_strcmp(str, "ra") == 0)
		ft_intlst_rotate(a);
	else if (ft_strcmp(str, "rb") == 0)
		ft_intlst_rotate(b);
	else if (ft_strcmp(str, "rra") == 0)
		ft_intlst_reverse_rotate(a);
	else if (ft_strcmp(str, "rrb") == 0)
		ft_intlst_reverse_rotate(b);
	else
		return (0);
	return (1);
}

static int	ft_is_inst(char *str, t_intlst **a, t_intlst **b)
{
	if (ft_is_inst_aux(str, a, b) == 0)
	{
		if (ft_strcmp(str, "ss") == 0)
		{
			ft_intlst_swap(a);
			ft_intlst_swap(b);
		}
		else if (ft_strcmp(str, "rr") == 0)
		{
			ft_intlst_rotate(a);
			ft_intlst_rotate(b);
		}
		else if (ft_strcmp(str, "rrr") == 0)
		{
			ft_intlst_reverse_rotate(a);
			ft_intlst_reverse_rotate(b);
		}
		else
			return (0);
	}
	return (1);
}

int	ft_check(t_intlst **a, t_intlst **b)
{
	char	*str;
	char	**tab;
	int		i;
	int		res;

	str = ft_get_inst();
	tab = ft_split(str, '\n');
	res = 1;
	i = 0;
	while (*(tab + i))
	{
		if (!ft_is_inst(*(tab + i), a, b))
		{
			if (res == 1)
			{
				ft_putstr_fd("\033[0;31mError\n", 2);
				res = 0;
			}
		}
		free(*(tab + i++));
	}
	free (tab);
	free (str);
	return (res);
}
