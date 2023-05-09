/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbouhami <zbouhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:01:51 by zbouhami          #+#    #+#             */
/*   Updated: 2023/04/15 14:20:40 by zbouhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (!(*stack))
		return ;
	tmp = (*stack);
	while (tmp)
	{
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
}
