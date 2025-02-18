/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_base.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaulnie <asaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:12:40 by asaulnie          #+#    #+#             */
/*   Updated: 2025/02/18 19:43:19 by asaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*pop(t_stack *stack)
{
	t_node	*popped_node;

	if (!stack->head)
		return (NULL);
	popped_node = stack->head;
	if (stack->size == 1)
	{
		stack->head = NULL;
		stack->tail = NULL;
	}
	else
	{
		stack->head = popped_node->next;
		stack->head->prev = NULL;
	}
	popped_node->next = NULL;
	popped_node->prev = NULL;
	stack->size--;
	return (popped_node);
}

t_node	*pop_back(t_stack *stack)
{
	t_node	*popped_node;

	if (!stack->tail)
		return (NULL);
	popped_node = stack->tail;
	if (stack->size == 1)
	{
		stack->head = NULL;
		stack->tail = NULL;
	}
	else
	{
		popped_node->prev->next = NULL;
		stack->tail = popped_node->prev;
	}
	popped_node->next = NULL;
	popped_node->prev = NULL;
	stack->size--;
	return (popped_node);
}

int	push(t_stack *stack, t_node *pushed_node)
{
	if (!pushed_node)
		return (1);
	if (stack->size == 0)
	{
		stack->head = pushed_node;
		stack->tail = pushed_node;
	}
	else
	{
		stack->head->prev = pushed_node;
		pushed_node->next = stack->head;
		stack->head = pushed_node;
	}
	stack->size++;
	return (0);
}

int	push_back(t_stack *stack, t_node *pushed_node)
{
	if (!pushed_node)
		return (1);
	if (stack->size == 0)
	{
		stack->head = pushed_node;
		stack->tail = pushed_node;
	}
	else
	{
		stack->tail->next = pushed_node;
		pushed_node->prev = stack->tail;
		stack->tail = pushed_node;
	}
	stack->size++;
	return (0);
}
