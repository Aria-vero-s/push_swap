/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaulnie <asaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:30:10 by asaulnie          #+#    #+#             */
/*   Updated: 2025/02/06 21:47:16 by asaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smallest(t_stack *stack_a)
{
	t_node	*current_node;
	int		smallest;

	current_node = stack_a->node;
	smallest = current_node->value;
	while (current_node)
	{
		if (current_node->value < smallest)
			smallest = current_node->value;
		current_node = current_node->next;
	}
	return (smallest);
}

int	find_biggest(t_stack *stack_a)
{
	t_node	*current_node;
	int		biggest;

	current_node = stack_a->node;
	biggest = current_node->value;
	while (current_node)
	{
		if (current_node->value > biggest)
			biggest = current_node->value;
		current_node = current_node->next;
	}
	return (biggest);
}

int	find_position(t_stack *stack, int smallest)
{
	t_node	*current_node;
	int		position;

	current_node = stack->node;
	position = 0;
	while (current_node)
	{
		if (current_node->value == smallest)
			return (position);
		position++;
		current_node = current_node->next;
	}
	return (-1);
}

void	push_smallest_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int	smallest;
	int	position;

	smallest = find_smallest(stack_a);
	position = find_position(stack_a, smallest);
	if (position <= (stack_a->size / 2))
	{
		while (position > 0)
		{
			ra(stack_a);
			position--;
		}
	}
	else
	{
		while (position < stack_a->size)
		{
			rra(stack_a);
			position++;
		}
	}
	pb(stack_a, stack_b);
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	push_smallest_to_b(stack_a, stack_b);
	push_smallest_to_b(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
