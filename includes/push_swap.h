/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaulnie <asaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:07:22 by asaulnie          #+#    #+#             */
/*   Updated: 2025/01/18 19:59:28 by asaulnie         ###   ########.fr       */
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
}	t_node;

typedef struct s_stack
{
	int		size;
	t_node	*node;
}	t_stack;

// input.c
t_stack	*parse_input(int argc, char **argv);
void	free_stack(t_stack *stack);

// stack.c
t_stack	*init_stack(void);
void	push(t_stack *stack, int value);
int		pop(t_stack *stack);
void	print_stack(t_stack *stack);
void	free_stack(t_stack *stack);

// operations.c
void	pb(t_stack *stack_a, t_stack *stack_b);

// utils.c
void	error_exit(char *msg);
void	print_before(t_stack *stack_a);

// push_swap1.c
void	sa(t_stack *stack);
void	ra(t_stack *stack);
void	rra(t_stack *stack);
void	sort_three(t_stack *stack);

// push_swap2.c
int		find_smallest(t_stack *stack);
int		find_position(t_stack *stack, int value);
void	push_smallest(t_stack *stack_a, t_stack *stack_b);
void	sort_five(t_stack *a, t_stack *b);
void	push_smallest_to_b(t_stack *a, t_stack *b);

#endif