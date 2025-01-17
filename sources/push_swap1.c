/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariane <ariane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:59:16 by asaulnie          #+#    #+#             */
/*   Updated: 2025/01/17 22:22:37 by ariane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (stack->size < 2)
		return;
	first = stack->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack->top = second;
}

void	ra(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (stack->size < 2)
		return;
	first = stack->top;
	last = stack->top;
	while (last->next)
		last = last->next;
	stack->top = first->next;
	first->next = NULL;
	last->next = first;
}

void	rra(t_stack *stack)
{
	t_node	*second_last;
	t_node	*last;

	if (stack->size < 2)
		return;
	second_last = NULL;
	last = stack->top;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = stack->top;
	stack->top = last;
}

void	sort_three(t_stack *stack)
{
	int	top;
	int	mid;
	int	bottom;
		
	top = stack->top->value;
	mid = stack->top->next->value;
	bottom = stack->top->next->next->value;
	if (top > mid && mid < bottom && top < bottom)
		sa(stack);
	else if (top > mid && mid > bottom && top > bottom)
	{
		sa(stack);
		rra(stack);
	}
	else if (top > mid && mid < bottom && top > bottom)
		ra(stack);
	else if (top < mid && mid > bottom && top < bottom)
	{
		sa(stack);
		ra(stack);
	}
	else if (top < mid && mid > bottom && top > bottom)
		rra(stack);
	print_stack(stack);
}