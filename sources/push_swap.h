/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbouhami <zbouhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 23:38:43 by zbouhami          #+#    #+#             */
/*   Updated: 2023/04/15 19:02:38 by zbouhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

//  --> stack strack
typedef struct push_swap
{
	int					rank;
	int					data;
	int					index;
	struct push_swap	*next;
}						t_stack;

/******			FUNCTIONS 		********/

// -->main.c
int		main(int ac, char **av);
void	stack_driver(t_stack **stack_a, t_stack **stack_b);
void	sort_stack(t_stack **stack_a, t_stack **stack_b, int size);

// -->parsing.c
int		ft_atoi(char *s);
bool	is_digit(char c);
void	check_string(char *s);
bool	is_duplicate(t_stack *start);
void	str_to_int(t_stack **stack_a, char *s);

// -->tools_2.c
bool	is_sorted(t_stack *stack);
void	exit_message(char *msg, char *color);
void	stacks_protection(t_stack **stack_a, t_stack **stack_b, char s);

// -->libft.c
void	put_str(char *s);
void	free_all(char **sc);
char	**ft_split(char const *s, char c);
int		ft_count_words(char const *str, char c);

// -->list_operateur.c
t_stack	*new_node(int data);
int		lst_len(t_stack *start);
int		lst_len_non_index(t_stack *start);
void	display_node(t_stack *start, char c);
void	ft_addnode_back(t_stack **node, t_stack *new_node);

// -->instructions.c
void	ft_rotate(t_stack **stack);
void	ft_rev_rotate(t_stack **stack);
void	ft_swap_data_lst(t_stack *s1, t_stack *s2);
void	push_to_stack(t_stack **from, t_stack **to);

// -->call_instructions.c
void	call_swap(t_stack *sack_a, t_stack *stack_b, char which_stack);
void	call_push(t_stack **stack_a, t_stack **stack_b, char which_stack);
void	call_instruction(t_stack **stack_a, t_stack **stack_b, char *ins);
void	call_rotate(t_stack **stack_a, t_stack **stack_b, char which_stack);
void	call_rev_rotate(t_stack **stack_a, t_stack **stack_b, char which_stack);

// -->tools.c
int		is_min(t_stack *stack);
void	set_rank(t_stack *stack);
int		the_small(t_stack *stack);
void	init_all_rank(t_stack **stack);

// -->sort_small_stack.c
void	sort_two(t_stack *stack_a);
void	sort_three(t_stack **stack_a);
void	sort_four(t_stack **stack_a, t_stack **stack_b);
void	sort_five(t_stack **stack_a, t_stack **stack_b);
void	small_sort(t_stack **stack_a, t_stack **stack_b, int size);

// -->sort_small_2.c
void	sort_three_2(t_stack **stack_a, int a, int b, int c);
void	sort_four_2(t_stack **stack_a, t_stack **stack_b, int smallest);
void	sort_five_2(t_stack **stack_a, t_stack **stack_b, int size);

// -->sort_long_stack.c
void	chunks_sort_b(t_stack **stack_a, t_stack **stack_b, int end, int len);
void	long_sort(t_stack **stack_a, t_stack **stack_b, int size, int pieces);

// -->optimize_sort.c
int		reach_in(t_stack *stack, int indx);
int		find_target(t_stack *stack, int rank);
void	head_it(t_stack **stack_b, int rank, int i);
void	chunk_sort_a(t_stack **stack_a, t_stack **stack_b);
void	cible_push(t_stack **stack_a, t_stack **stack_b, int *size, int crush);

// -->free_stacks.c
void	free_stack(t_stack **stack);

#endif
