/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariane <ariane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:05:22 by ariane            #+#    #+#             */
/*   Updated: 2025/01/15 13:28:20 by ariane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;
		
	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		error_exit("Error: malloc() failed");
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

void	push(t_stack *stack, int value)
{
	t_node	*new_node;
		
	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		error_exit("Error: malloc() failed");
	new_node->value = value;
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size++;
}

int	pop(t_stack *stack)
{
	t_node	*temp;
	int		value;

	if (is_empty(stack))
		error_exit("Error: empty stack");
	temp = stack->top;
	value = temp->value;
	stack->top = temp->next;
	free(temp);
	stack->size--;
	return (value);
}

int	is_empty(t_stack *stack)
{
	return (stack->size == 0);
}

void	free_stack(t_stack *stack)
{
	while (!is_empty(stack))
		pop(stack);
	free(stack);
}

void	print_stack(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	while (current)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
}
