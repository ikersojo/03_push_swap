/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:38:30 by isojo-go          #+#    #+#             */
/*   Updated: 2022/11/16 20:09:08 by isojo-go         ###   ########.fr       */
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

static int	ft_string_to_args(char ***argv)
{
	int		argc;
	char	*str1;
	char	*str2;
	char	**arg_list;

	str1 = ft_strjoin(*(*(argv) + 0), " ");
	str2 = ft_strjoin(str1, *(*(argv) + 1));
	arg_list = ft_split(str2, ' ');
	free (str1);
	free (str2);
	argc = 0;
	while (*(arg_list + argc))
		argc++;
	*argv = arg_list;
	return (argc);
}

static void	ft_free_all(t_intlst **a, t_intlst **b, int i, char ***argv)
{
	ft_intlst_free(a);
	ft_intlst_free(b);
	if (i != 0)
	{
		while (i--)
			free (*(*(argv) + i));
		free (*argv);
	}
}

int	main(int argc, char **argv)
{
	t_intlst	*a;
	t_intlst	*b;
	int			to_be_freed;

	to_be_freed = 0;
	if (argc == 2)
	{
		argc = ft_string_to_args(&argv);
		to_be_freed = argc;
	}
	if (argc > 2)
	{
		if (ft_input_error(argc, argv))
			return (0);
		a = ft_args_to_intlst(argc, argv);
		b = NULL;
		if (PR)
			ft_visualize_stacks(&a, &b);
		ft_sort(&a, &b, argc - 1);
		if (PR)
			ft_visualize_stacks(&a, &b);
		ft_free_all(&a, &b, to_be_freed, &argv);
	}
	return (0);
}
