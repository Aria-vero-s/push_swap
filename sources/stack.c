/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariane <ariane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:05:22 by ariane            #+#    #+#             */
/*   Updated: 2025/01/19 19:53:09 by ariane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		error_exit("Error: malloc() failed");
	new_node->value = value;
	new_node->next = stack->node;
	stack->node = new_node;
	stack->size++;
}

int	pop(t_stack *stack)
{
	t_node	*temp;
	int		value;

	if (stack->size == 0)
		error_exit("Error: empty stack");
	temp = stack->node;
	value = temp->value;
	stack->node = temp->next;
	free(temp);
	stack->size--;
	return (value);
}

void	free_stack(t_stack *stack)
{
	while (stack->size > 0)
		pop(stack);
	free(stack);
}

void	print_stack(t_stack *stack)
{
	t_node	*current;

	current = stack->node;
	while (current)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
}
