/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:38:30 by isojo-go          #+#    #+#             */
/*   Updated: 2022/10/15 23:41:57 by isojo-go         ###   ########.fr       */
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

// typedef struct s_intlst
// {
// 	int				value;
// 	struct s_intlst	*next;
// }					t_intlst;

// t_intlst	*ft_intlst_new(int value)
// {
// 	t_intlst	*new;

// 	new = (t_intlst *)malloc(sizeof(t_intlst));
// 	if (new == NULL)
// 		return (NULL);
// 	new->value = value;
// 	new->next = NULL;
// 	return (new);
// }

// t_intlst	*ft_intlst_last(t_intlst *lst)
// {
// 	if (lst == NULL)
// 		return (NULL);
// 	while (lst->next)
// 		lst = lst->next;
// 	return (lst);
// }

// void	ft_intlst_addback(t_intlst **lst, t_intlst *new)
// {
// 	t_intlst	*tmp;

// 	if (new && *lst)
// 	{
// 		if (*lst == NULL)
// 			*lst = new;
// 		else
// 		{
// 			tmp = ft_intlst_last(*lst);
// 			tmp->next = new;
// 		}
// 	}
// }

// void	ft_intlst_free(t_intlst **lst)
// {
// 	t_intlst	*next_item;

// 	while (*lst)
// 	{
// 		next_item = (*lst)->next;
// 		free(*lst);
// 		*lst = next_item;
// 	}
// }

// void	ft_intlst_print(t_intlst **lst)
// {
// 	t_intlst	*next_item;

// 	while (*lst)
// 	{
// 		printf("current item in pointer: %p, with value %d\n", *lst, (*lst)->value); //--- DEBUG
// 		next_item = (*lst)->next;
// 		ft_putnbr_fd(((*lst)->value), 1);
// 		ft_putchar_fd('\n', 1);
// 		*lst = next_item;
// 	}
// }

// int	ft_isint(char *str)
// {
// 	int		i;
// 	char	c;

// 	i = 0;
// 	while (*(str + i))
// 	{
// 		c = *(str + i);
// 		if (!(c == '+' || c == '-' || (c >= '0' && c <= '9')))
// 			return (0);
// 		i++;
// 	}
// 	// comprobar si está entre max int y min int
// 	return (1);
// }

// t_intlst	*ft_args_to_intlst(int argc, char **argv)
// {
// 	int			i;
// 	t_intlst	*a;
// 	t_intlst	*tmp;

// 	i = 1;
// 	while (i < argc)
// 	{
// 		if (i == 1)
// 			a = ft_intlst_new(ft_atoi((*(argv + i))));
// 		else
// 		{
// 			tmp = ft_intlst_new(ft_atoi((*(argv + i))));
// 			ft_intlst_addback(&a, tmp);
// 		}
// 		i++;
// 	}
// 	return (a);
// }

int	ft_input_error(int argc, char **argv)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (!ft_isint(*(argv + i)))
		{
			ft_putstr_fd("Error\n", 1);
			return (1);
		}
		i++;
	}
	// comprobar que no se repiten
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
		ft_intlst_print(&a);
		ft_intlst_free(&a);
	}
	return (0);
}
