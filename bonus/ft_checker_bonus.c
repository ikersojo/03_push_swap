/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:00:42 by isojo-go          #+#    #+#             */
/*   Updated: 2022/11/23 16:15:24 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

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
			ft_putstr_fd(RED, 2);
			ft_putstr_fd("Error\n", 2);
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
		if (ft_check(&a, &b))
		{
			if (ft_intlst_issorted(a) && b == NULL)
				ft_putstr_fd("\033[0;92mOK\n", 1);
			else
				ft_putstr_fd("\033[0;31mKO\n", 2);
		}
		ft_intlst_free(&a);
		ft_intlst_free(&b);
		ft_free_args(argc + 1, &argv);
	}
	return (0);
}
