/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaulnie <asaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:07:22 by asaulnie          #+#    #+#             */
/*   Updated: 2025/01/21 18:37:49 by asaulnie         ###   ########.fr       */
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
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

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
int		is_valid_int(char *str);
t_stack	*init_stack(void);
t_stack	*parse_input(int argc, char **argv);
void	free_stack(t_stack *stack);

// push_pop.c
void	push(t_stack *stack, int num);
int		pop(t_stack *stack);
void	free_stack(t_stack *stack);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *a, t_stack *b);

// utils.c
void	error_exit(char *msg);
void	check_if_duplicates(t_stack *stack_a, t_stack *stack_b);
void	print_stack(t_stack *stack);
void	print_values(int *values, int size);

// push_swap1.c
void	sa(t_stack *stack);
void	ra(t_stack *stack);
void	rra(t_stack *stack);
void	sort_three(t_stack *stack);
void	sort_four_or_two(t_stack *stack_a, t_stack *stack_b);

// push_swap2.c
int		find_smallest(t_stack *stack_a);
int		find_position(t_stack *stack, int smallest);
void	sort_five(t_stack *stack_a, t_stack *stack_b);
void	push_smallest_to_b(t_stack *stack_a, t_stack *stack_b);

// radix.c
void	radix_sort(t_stack *stack_a, t_stack *stack_b);
void	set_positions(t_stack *stack);
void	sort_values(int *values, int size);
void	values_to_array(t_stack *stack, int *values);

#endif