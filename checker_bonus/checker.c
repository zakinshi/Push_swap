/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbouhami <zbouhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 11:17:05 by zbouhami          #+#    #+#             */
/*   Updated: 2023/04/17 14:42:24 by zbouhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	args_protect(int ac)
{
	if (ac < 2)
		exit(0);
}

void	fill_stack_a(t_stack **stack_a, char *data)
{
	t_stack	*node;
	int		n_nbr;

	n_nbr = ft_count_words(data, ' ');
	if (n_nbr == 1)
	{
		node = new_node(ft_atoi(data));
		ft_addnode_back(stack_a, node);
	}
	else if (n_nbr > 1)
		str_to_int(stack_a, data);
	else
		exit_message("Error : Empty Number Zone..", YELLOW);
}

void	fill_stack(t_stack **stack_a, int ac, char **av)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		check_string(av[i]);
		fill_stack_a(stack_a, av[i]);
	}
}

void	checker_driver(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (ft_count_words(line, ' ') != 1)
		{
			free(line);
			exit_message("Error : Enter instruction without white sp", RED);
		}
		call_instruction(stack_a, stack_b, line);
		free(line);
		line = get_next_line(0);
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	args_protect(ac);
	fill_stack(&stack_a, ac, av);
	is_duplicate(stack_a);
	checker_driver(&stack_a, &stack_b);
	stack_check(stack_a, stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
