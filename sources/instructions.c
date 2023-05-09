/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbouhami <zbouhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 21:05:44 by zbouhami          #+#    #+#             */
/*   Updated: 2023/05/09 18:02:40 by zbouhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_data_lst(t_stack *s1, t_stack *s2)
{
	if (!s1 || !s2)
		return ;
	s1->data ^= s2->data;
	s2->data ^= s1->data;
	s1->data ^= s2->data;
	s1->rank ^= s2->rank;
	s2->rank ^= s1->rank;
	s1->rank ^= s2->rank;
}

void	ft_rotate(t_stack **stack)
{
	t_stack	*tmp_head;
	t_stack	*tmp_2;

	tmp_2 = *stack;
	tmp_head = *stack;
	*stack = (*stack)->next;
	while (tmp_head)
	{
		if (tmp_head->next == NULL)
		{
			tmp_head->next = tmp_2;
			tmp_2->next = NULL;
			break ;
		}
		tmp_head = tmp_head->next;
	}
}

void	ft_rev_rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*last;

	head = *stack;
	while (head)
	{
		if (head->next == NULL)
			last = head;
		head = head->next;
	}
	head = *stack;
	last->next = head;
	while (head)
	{
		if (head->next == last)
			head->next = NULL;
		head = head->next;
	}
	*stack = last;
}

void	push_to_stack(t_stack **from, t_stack **to)
{
	t_stack	*tmp_head;

	tmp_head = NULL;
	if (*from == NULL)
		return ;
	tmp_head = *from;
	*from = ((*from)->next);
	tmp_head->next = *to;
	*to = tmp_head;
}
