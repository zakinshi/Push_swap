/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_generator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbouhami <zbouhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 11:29:02 by zbouhami          #+#    #+#             */
/*   Updated: 2023/04/17 14:40:38 by zbouhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack	*new_node(int data)
{
	t_stack	*start;

	start = (t_stack *)malloc(sizeof(t_stack));
	if (!start)
		exit_message("New-Node Allocation Failed..", BLUE);
	start->data = data;
	start->next = NULL;
	return (start);
}

void	ft_addnode_back(t_stack **stack, t_stack *node)
{
	t_stack	*tmp;

	if (!(*stack))
	{
		*stack = node;
		return ;
	}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
}

void	display_node(t_stack *start, char c)
{
	t_stack	*tmp;

	if (!start)
		printf("node is empty\n");
	else
	{
		tmp = start;
		printf("%s", GREEN);
		printf("\t|    STACK %c\t|\n", c);
		printf("\t|_______________|\n");
		while (tmp)
		{
			printf("\t|\t%d\t|\n", tmp->data);
			tmp = tmp->next;
		}
		printf("\t|_______________|\n\n");
	}
	printf("%s", WHITE);
}

int	lst_len(t_stack *start)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = start;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
