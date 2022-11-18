/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:38:30 by isojo-go          #+#    #+#             */
/*   Updated: 2022/11/18 23:14:23 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/ft_push_swap.h"

#ifndef PR
# define PR 0
#endif

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

static int	ft_free_args(int i, char ***argv)
{
	if (i != 0)
	{
		while (i--)
			free (*(*(argv) + i));
		free (*argv);
	}
	return (2);
}

int	main(int argc, char **argv)
{
	t_intlst	*a;
	t_intlst	*b;

	if (argc > 1)
	{
		argc = ft_input_to_args(argc, &argv);
		if (argc == 0)
			return (ft_free_args(argc + 1, &argv));
		if (ft_input_error(argc, argv))
			return (ft_free_args(argc + 1, &argv));
		a = ft_args_to_intlst(argc, argv);
		b = NULL;
		if (PR)
			ft_visualize_stacks(&a, &b);
		ft_sort(&a, &b, argc - 1);
		if (PR)
			ft_visualize_stacks(&a, &b);
		ft_intlst_free(&a);
		ft_intlst_free(&b);
		ft_free_args(argc + 1, &argv);
	}
	return (0);
}
