/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariane <ariane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:07:22 by asaulnie          #+#    #+#             */
/*   Updated: 2025/01/19 20:24:42 by ariane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	int				index;
}	t_node;

typedef struct s_stack
{
	int		size;
	t_node	*node;
}	t_stack;

// input.c
int			is_valid_int(char *str);
t_stack		*init_stack(void);
t_stack		*parse_input(int argc, char **argv);
void		free_stack(t_stack *stack);

// stack.c
void	push(t_stack *stack, int value);
int		pop(t_stack *stack);
void	print_stack(t_stack *stack);
void	free_stack(t_stack *stack);

// operations.c
void	pb(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *a, t_stack *b);

// utils.c
void	error_exit(char *msg);
void	print_before(t_stack *stack_a);

// push_swap1.c
void	sa(t_stack *stack);
void	ra(t_stack *stack);
void	rra(t_stack *stack);
void	sort_three(t_stack *stack);
void	sort_four_or_two(t_stack *a, t_stack *b);

// push_swap2.c
int		find_smallest(t_stack *stack);
int		find_position(t_stack *stack, int value);
void	push_smallest(t_stack *stack_a, t_stack *stack_b);
void	sort_five(t_stack *a, t_stack *b);
void	push_smallest_to_b(t_stack *a, t_stack *b);

// radix.c
void	radix_sort(t_stack *a, t_stack *b);
void	normalize_positions(t_stack *stack);
void	sort_values(int *values, int size);
void	copy_values_to_array(t_stack *stack, int *values);

#endif