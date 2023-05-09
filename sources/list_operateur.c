/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operateur.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbouhami <zbouhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 02:46:28 by zbouhami          #+#    #+#             */
/*   Updated: 2023/04/15 20:22:50 by zbouhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_node(int data)
{
	t_stack	*start;

	start = (t_stack *)malloc(sizeof(t_stack));
	if (!start)
		exit_message("Null Allocation For sata in -new_node()-\n", BLUE);
	start->data = data;
	start->next = NULL;
	return (start);
}

void	ft_addnode_back(t_stack **node, t_stack *new_node)
{
	t_stack	*tmp;

	if (!(*node))
	{
		*node = new_node;
		return ;
	}
	tmp = *node;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new_node;
}

// void	display_node(t_stack *start, char c)
// {
// 	t_stack	*tmp;

// 	if (!start)
// 		printf("node is empty\n");
// 	else
// 	{
// 		tmp = start;
// 		printf("%s", GREEN);
// 		printf("\t|\t\t\tSTACK %c\t\t\t|\n", c);
// 		printf("\t|_______________________________________________|\n");
// 		printf("\t|\tDATA\t|\tINDEX\t|\tRANK\t|\n");
// 		printf("\t|_______________|_______________|_______________|\n");
// 		while (tmp)
// 		{
// 			printf("\t|\t%d\t|\t", tmp->data);
// 			printf("%d\t|\t", tmp->index);
// 			printf("%d\t|\t\n", tmp->rank);
// 			tmp = tmp->next;
// 		}
// 		printf("\t|_______________|_______________|_______________|\n\n");
// 	}
// 	printf("%s", WHITE);
// }

int	lst_len_non_index(t_stack *start)
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

int	lst_len(t_stack *start)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = start;
	while (tmp)
	{
		tmp->index = i;
		i++;
		tmp = tmp->next;
	}
	return (i);
}
