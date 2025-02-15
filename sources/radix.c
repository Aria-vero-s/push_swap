/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaulnie <asaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:22:03 by asaulnie          #+#    #+#             */
/*   Updated: 2025/02/12 22:02:29 by asaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	process_bit(t_stack *stack_a, t_stack *stack_b, int bit)
{
	int	i;
	int	size;

	size = stack_a->size;
	i = 0;
	while (i < size)
	{
		if (((stack_a->node->index >> bit) & 1) == 1)
			ra(stack_a);
		else
			pb(stack_a, stack_b);
		i++;
	}
	while (stack_b->size > 0)
		pa(stack_a, stack_b);
}

int	calculate_max_bits(t_stack *stack_a)
{
	int	max_bits;
	int	max_index;

	max_bits = 0;
	max_index = stack_a->size - 1;
	while ((max_index >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

int	is_sorted(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current;

	current = stack_a->node;
	if (current == NULL)
		return (1);
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	free_stack(stack_a);
	free_stack(stack_b);
	return (1);
}

void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	bit;
	int	max_bits;

	bit = 0;
	set_positions(stack_a);
	max_bits = calculate_max_bits(stack_a);
	while (bit < max_bits)
	{
		process_bit(stack_a, stack_b, bit);
		bit++;
	}
	while (stack_a->node->index != 0)
		ra(stack_a);
}
