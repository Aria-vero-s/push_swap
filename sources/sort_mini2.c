/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_mini2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaulnie <asaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:53:54 by asaulnie          #+#    #+#             */
/*   Updated: 2025/02/18 19:53:57 by asaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smallest(t_stack *stack_a)
{
	t_node	*current_node;
	int		smallest;

	current_node = stack_a->head;
	smallest = current_node->index;
	while (current_node)
	{
		if (current_node->index < smallest)
			smallest = current_node->index;
		current_node = current_node->next;
	}
	return (smallest);
}

t_node	*get_biggest(t_stack *stack)
{
	t_node	*current_node;
	t_node	*biggest;

	if (!stack->head)
		return (NULL);
	current_node = stack->head;
	biggest = stack->head;
	while (current_node)
	{
		if (current_node->index > biggest->index)
			biggest = current_node;
		current_node = current_node->next;
	}
	return (biggest);
}

int	find_position(t_stack *stack, int index)
{
	t_node	*current_node;
	int		position;

	current_node = stack->head;
	position = 0;
	while (current_node)
	{
		if (current_node->index == index)
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
