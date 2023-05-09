/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbouhami <zbouhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 11:26:33 by zbouhami          #+#    #+#             */
/*   Updated: 2023/05/09 17:59:40 by zbouhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <string.h>

bool	is_sorted(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

void	exit_message(char *msg, char *color)
{
	put_str(color);
	put_str(msg);
	put_str(WHITE);
	exit(0);
}

void	stacks_protection(t_stack **stack_a, t_stack **stack_b, char s)
{
	if (!stack_a && !stack_b)
		exit_message("Error : STACK_NOT_EXIST..", RED);
	if (!*stack_a && !*stack_b)
		exit_message("Error : STACK EMPTY..", RED);
	if (s == 'a' && !*stack_a)
		exit_message("Error : STACK A EMPTY..", RED);
	else if (s == 'b' && !*stack_b)
		exit_message("Error : STACK B EMPTY..", RED);
	else if (s == 's' && (!*stack_a || !*stack_b))
		exit_message("Error : One Of Stacks is EMPTY..", RED);
}

bool	is_here(char c, char *s2)
{
	int	j;

	j = 0;
	while (s2[j])
	{
		if (c == s2[j])
			return (true);
		j++;
	}
	return (false);
}

void	ins_protect(char *ins)
{
	if (!is_here(ins[0], "psr"))
		exit_message("Error : Invalide Instruction..", BLUE);
	else if ((ins[0] == 's' || ins[0] == 'p') && ft_strlen(ins) > 3)
		exit_message("Error : Invalide Instruction..", BLUE);
	if (!is_here(ins[1], "absr"))
		exit_message("Error : 2 Invalide Instruction..", BLUE);
	if (ins[2] != '\n' && !is_here(ins[2], "abr"))
		exit_message("Error : 3 Invalide Instruction..", BLUE);
	if (ins[3] != '\n' && ins[3] != '\0')
		exit_message("Error : 4 Invalide Instruction..", BLUE);
}
