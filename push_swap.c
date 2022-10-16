/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:38:30 by isojo-go          #+#    #+#             */
/*   Updated: 2022/10/16 10:50:59 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/inc/libft.h"

/*
INITIALIZE:
- Read argument(s) to initalize stack a.
- Initialize an empty stack b of the same size as a.

INSTRUCTIONS:
- sa (swap a): Swap the first 2 elements at the top of stack a. 
  Do nothing if there is only one or no elements.
- sb (swap b): Swap the first 2 elements at the top of stack b. 
  Do nothing if there is only one or no elements.
- ss : sa and sb at the same time.
- pa (push a): Take first element at the top of b and put it at the top of a.
  Do nothing if b is empty.
- pb (push b): Take first element at the top of a and put it at the top of b.
  Do nothing if a is empty.
- ra (rotate a): Shift up all elements of stack a by 1.
  The first element becomes the last one.
- rb (rotate b): Shift up all elements of stack b by 1.
  The first element becomes the last one.
- rr : ra and rb at the same time.
- rra (reverse rotate a): Shift down all elements of stack a by 1.
  The last element becomes the first one.
- rrb (reverse rotate b): Shift down all elements of stack b by 1.
  The last element becomes the first one.
- rrr : rra and rrb at the same time.
*/

static int	ft_repeated(int argc, char **argv, int i)
{
	int	j;
	int	num;

	num = ft_atoi(*(argv + i));
	j = i + 1;
	while (j < argc)
	{
		if (ft_atoi(*(argv + j)) == num)
			return (1);
		j++;
	}
	return (0);
}

static int	ft_input_error(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_isint(*(argv + i)) || ft_repeated(argc, argv, i))
		{
			ft_putstr_fd("Error\n", 1);
			return (1);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_intlst	*a;
	// t_intlst	*b;

	if (argc > 2)
	{
		if (ft_input_error(argc, argv))
			return (0);
		a = ft_args_to_intlst(argc, argv);
		ft_intlst_print(a);
		ft_intlst_free(&a);
	}
	return (0);
}
