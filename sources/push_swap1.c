/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaulnie <asaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:59:16 by asaulnie          #+#    #+#             */
/*   Updated: 2025/01/20 21:21:53 by asaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (stack->size < 2)
		return ;
	first = stack->node;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack->node = second;
	printf("sa\n");
}

void	ra(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (stack->size < 2)
		return ;
	first = stack->node;
	last = stack->node;
	while (last->next)
		last = last->next;
	stack->node = first->next;
	first->next = NULL;
	last->next = first;
	printf("ra\n");
}

void	rra(t_stack *stack)
{
	t_node	*second_last;
	t_node	*last;

	if (stack->size < 2)
		return ;
	second_last = NULL;
	last = stack->node;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = stack->node;
	stack->node = last;
	printf("rra\n");
}

void	sort_three(t_stack *stack)
{
	int	top;
	int	mid;
	int	bottom;

	top = stack->node->value;
	mid = stack->node->next->value;
	bottom = stack->node->next->next->value;
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
}

void	sort_four_or_two(t_stack *a, t_stack *b)
{
	if (a->size == 2)
	{
		if ((a->node->value) > (a->node->next->value))
			sa(a);
	}
	else if (a->size == 4)
	{
		push_smallest_to_b(a, b);
		sort_three(a);
		pa(a, b);
	}
}
