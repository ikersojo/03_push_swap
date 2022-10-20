/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:38:30 by isojo-go          #+#    #+#             */
/*   Updated: 2022/10/20 17:13:43 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/inc/libft.h"

void	ft_swap_nbr(int *a, int *b)
{
	int	temp;

	if (a && b)
	{
		temp = *a;
		*a = *b;
		*b = temp;
	}
}

/*	sa (swap a):
	Swap the first 2 elements at the top of stack a. 
	Do nothing if there is only one or no elements. */
void	sa(t_intlst **a)
{
	if (*a)
	{
		ft_swap_nbr(&((*a)->value), &(((*a)->next)->value));
		ft_putstr_fd("sa\n", 1);
	}
}

/*	sb (swap b):
	Swap the first 2 elements at the top of stack b. 
	Do nothing if there is only one or no elements. */
void	sb(t_intlst **b)
{
	if (*b)
	{
		ft_swap_nbr(&((*b)->value), &(((*b)->next)->value));
		ft_putstr_fd("sb\n", 1);
	}
}

/*	ss : sa and sb at the same time. */
void	ss(t_intlst **a, t_intlst **b)
{
	sa(a);
	sb(b);
	ft_putstr_fd("ss\n", 1);
}

/*	pa (push a): Take first element at the top of b and put it at the top of a.
	Do nothing if b is empty. */
void	pa(t_intlst **a, t_intlst **b)
{
	if (*a)
	{
		ft_intlst_addfront(&a, b);
	}
}

/*	pb (push b): Take first element at the top of a and put it at the top of b.
	Do nothing if a is empty. */
// void	pb(t_intlst **a, t_intlst **b)

/*	ra (rotate a): Shift up all elements of stack a by 1.
	The first element becomes the last one. */
// void	ra(t_intlst **a)

/*	rb (rotate b): Shift up all elements of stack b by 1.
	The first element becomes the last one. */
// void	rb(t_intlst **b)

/*	rr : ra and rb at the same time. */
// void	rr(t_intlst **a, t_intlst **b)

/*	rra (reverse rotate a): Shift down all elements of stack a by 1.
	The last element becomes the first one. */
// void	rra(t_intlst **a)

/*	rrb (reverse rotate b): Shift down all elements of stack b by 1.
	The last element becomes the first one. */
// void	rrb(t_intlst **b)

/*	rrr : rra and rrb at the same time. */
// void	rrr(t_intlst **a, t_intlst **b)

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
	t_intlst	*b;

	if (argc > 2)
	{
		if (ft_input_error(argc, argv))
			return (0);
		a = ft_args_to_intlst(argc, argv);
		b = NULL;
		ft_intlst_print(a);
		ss(&a, &b);
		ft_intlst_print(a);
		ft_intlst_free(&a);
	}
	return (0);
}
