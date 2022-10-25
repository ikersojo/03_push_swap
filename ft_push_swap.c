/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:38:30 by isojo-go          #+#    #+#             */
/*   Updated: 2022/10/25 16:32:42 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/ft_push_swap.h"

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

		if (ft_intlst_issorted(a))
			return (ft_putstr_fd("Sorted!\n", 1));
		return (ft_putstr_fd("NOT Sorted!\n", 1));

		// ft_putstr_fd("Initial lists:\na:\n", 1);
		// ft_intlst_print(a);
		// ft_putstr_fd("b:\n", 1);
		// ft_intlst_print(b);

		// ft_pb(&a, &b);
		
		// ft_putstr_fd("\n\nAfter mod:\na:\n", 1);
		// ft_intlst_print(a);
		// ft_putstr_fd("b:\n", 1);
		// ft_intlst_print(b);
		
		// ft_pb(&a, &b);
		// ft_putstr_fd("\n\nAfter mod:\na:\n", 1);
		// ft_intlst_print(a);
		// ft_putstr_fd("b:\n", 1);
		// ft_intlst_print(b);

		// ft_ss(&a, &b);

		// ft_putstr_fd("\n\nAfter mod:\na:\n", 1);
		// ft_intlst_print(a);
		// ft_putstr_fd("b:\n", 1);
		// ft_intlst_print(b);

		// ft_rr(&a, &b);

		// ft_putstr_fd("\n\nAfter mod:\na:\n", 1);
		// ft_intlst_print(a);
		// ft_putstr_fd("b:\n", 1);
		// ft_intlst_print(b);

		// ft_pa(&b, &a);

		// ft_putstr_fd("\n\nAfter mod:\na:\n", 1);
		// ft_intlst_print(a);
		// ft_putstr_fd("b:\n", 1);
		// ft_intlst_print(b);

		// ft_rr(&b, &a);

		// ft_putstr_fd("\n\nAfter mod:\na:\n", 1);
		// ft_intlst_print(a);
		// ft_putstr_fd("b:\n", 1);
		// ft_intlst_print(b);
		

		// ft_rrr(&b, &a);

		// ft_putstr_fd("\n\nAfter mod:\na:\n", 1);
		// ft_intlst_print(a);
		// ft_putstr_fd("b:\n", 1);
		// ft_intlst_print(b);






		ft_intlst_free(&a);
		ft_intlst_free(&b);
	}
	return (0);
}
