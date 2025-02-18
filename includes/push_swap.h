/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaulnie <asaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:07:22 by asaulnie          #+#    #+#             */
/*   Updated: 2025/02/18 21:23:52 by asaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <string.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
	int				index;
}	t_node;

typedef struct s_stack
{
	int		size;
	t_node	*head;
	t_node	*tail;
}	t_stack;

int			check_if_duplicates(t_stack *stack_a);
int			is_sorted(t_stack *stack_a);
int			is_valid_int(char *str);
void		init_stack(t_stack *stack);
void		create_and_push_back(t_stack *stack, int value);
void		parse_multiple_args(int argc, char **argv, t_stack *stack);
void		parse_input(int argc, char **argv, t_stack *stack);
void		free_double_array(char **arr);
int			count_tokens(char **tokens);
void		handle_single_token(char **tokens);
void		push_tokens(char **tokens, int count, t_stack *stack);
void		parse_single_arg(char *arg, t_stack *stack);
t_node		*pop(t_stack *stack);
t_node		*pop_back(t_stack *stack);
int			push(t_stack *stack, t_node *pushed_node);
int			push_back(t_stack *stack, t_node *pushed_node);
void		pb(t_stack *a, t_stack *b);
void		pa(t_stack *a, t_stack *b);
void		ra(t_stack *a);
void		rra(t_stack *a);
void		rb(t_stack *b);
void		rrb(t_stack *b);
void		sa(t_stack *a);
int			find_smallest(t_stack *stack_a);
t_node		*get_biggest(t_stack *stack);
int			find_position(t_stack *stack, int index);
void		push_smallest_to_b(t_stack *stack_a, t_stack *stack_b);
void		big_sort_launcher(t_stack *a, t_stack *b);
void		sort_three(t_stack *stack);
void		sort_four_or_two(t_stack *stack_a, t_stack *stack_b);
void		sort_five(t_stack *stack_a, t_stack *stack_b);
void		error_exit(char *msg);
void		free_stack(t_stack *stack);
void		reindex(t_stack *stack);
void		print_stack(t_stack *stack);

#endif
