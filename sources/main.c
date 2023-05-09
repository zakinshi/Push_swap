/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbouhami <zbouhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 23:36:13 by zbouhami          #+#    #+#             */
/*   Updated: 2023/05/09 16:31:30 by zbouhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fill_stack_a(t_stack **stack_a, char *av)
{
	t_stack	*node;
	int		n_nbr;

	n_nbr = ft_count_words(av, ' ');
	if (n_nbr == 1)
	{
		node = new_node(ft_atoi(av));
		ft_addnode_back(stack_a, node);
	}
	else if (n_nbr > 1)
		str_to_int(stack_a, av);
	else
		exit_message("Empty Number Zone...", BLUE);
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (!is_sorted(*stack_a))
	{
		if (size < 6)
			small_sort(stack_a, stack_b, size);
		else if (size < 200)
			long_sort(stack_a, stack_b, size, 5);
		else
			long_sort(stack_a, stack_b, size, 9);
	}
	else
		exit(0);
}

void	stack_driver(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = lst_len(*stack_a);
	init_all_rank(stack_a);
	set_rank(*stack_a);
	sort_stack(stack_a, stack_b, size);
}

void	args_protect(int ac, char **av)
{
	if (ac <= 2)
	{
		if (ac <= 1)
			exit(0);
		else if (ac == 2)
		{
			if (ft_count_words(av[1], ' ') <= 1)
				exit(0);
		}
	}
}

int	main(int ac, char **av)
{
	int		i;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	args_protect(ac, av);
	i = 0;
	while (++i < ac)
	{
		check_string(av[i]);
		fill_stack_a(&stack_a, av[i]);
	}
	is_duplicate(stack_a);
	stack_driver(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
