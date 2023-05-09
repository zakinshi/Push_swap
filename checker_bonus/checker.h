/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbouhami <zbouhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 11:15:55 by zbouhami          #+#    #+#             */
/*   Updated: 2023/05/09 18:00:39 by zbouhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "get_next_line/get_next_line.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// COLORS __ DEFINES
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define WHITE "\033[1;37m"

// --> stack struct
typedef struct checker
{
	int				data;
	struct checker	*next;
}	t_stack;

// --> checker.c
void	args_protect(int ac);
void	fill_stack_a(t_stack **stack_a, char *data);
void	fill_stack(t_stack **stack_a, int ac, char **av);

// --> list_generator.c
t_stack	*new_node(int data);
void	display_node(t_stack *start, char c);
int		lst_len(t_stack *start);
void	ft_addnode_back(t_stack **stack, t_stack *node);

// --> Parsing.c
bool	is_digit(char c);
int		ft_atoi(char *s);
void	str_to_int(t_stack **stack, char *s);
bool	is_duplicate(t_stack *start);
void	check_string(char *s);

// -->libft_tools.c
void	put_str(char *s);
void	free_all(char **sc);
char	**ft_splited(char const *str, char c);
int		ft_count_words(char const *str, char c);

// -->tools.c
void	ins_protect(char *ins);
bool	is_sorted(t_stack *stack);
bool	is_here(char c, char *s2);
void	exit_message(char *msg, char *color);
void	stacks_protection(t_stack **stack_a, t_stack **stack_b, char s);

// -->instructions.c
void	push_to_stack(t_stack **from, t_stack **to);
void	swap_node(t_stack *s1, t_stack *s2);
void	ft_rev_rotate(t_stack **stack);
void	ft_rotate(t_stack **stack);

// -->call_instru.c
void	call_swap(t_stack *stack_a, t_stack *stack_b, char which_stack);
void	call_push(t_stack **stack_a, t_stack **stack_b, char which_stack);
void	call_instruction(t_stack **stack_a, t_stack **stack_b, char *ins);
void	call_rotate(t_stack **stack_a, t_stack **stack_b, char which_stack);
void	call_rev_rotate(t_stack **stack_a, t_stack **stack_b, char which_stack);

// -->free_stacks.c
void	free_stack(t_stack **stack);
void	stack_check(t_stack *stack_a, t_stack *stack_b);

#endif
