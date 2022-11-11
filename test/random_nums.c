/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_nums.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:17:26 by isojo-go          #+#    #+#             */
/*   Updated: 2022/11/11 10:42:22 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/inc/libft.h"
#include <time.h>

int	ft_is_in_tab(int *tab, int num, unsigned int size)
{
	unsigned int	i;

	if (size == 0)
		return (0);
	i = 0;
	while (i < size)
	{
		if (num == *(tab + i))
			return (1);
		i++;
	}
	return (0);
}

void	ft_print_toconsole(int *tab, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		ft_putnbr_fd(*(tab + i), 1);
		if (i != size - 1)
			ft_putchar_fd(' ', 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	unsigned int	size;
	unsigned int	i;
	int				num;
	int				*tab;

	if (argc == 2)
	{
		size = ft_atoi(*(argv + 1));
		tab = (int *)malloc(sizeof(int) * size);
		i = 0;
		srand(time(NULL));
		while (i < size)
		{
			num = (rand() - rand()) % 2147483647;
			while (ft_is_in_tab(tab, num, i))
				num = (rand() - rand()) % 2147483647;
			*(tab + i) = num;
			i++;
		}
		ft_print_toconsole(tab, size);
		free (tab);
	}
	return (0);
}
