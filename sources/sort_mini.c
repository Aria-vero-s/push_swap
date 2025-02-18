/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_mini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaulnie <asaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:50:59 by asaulnie          #+#    #+#             */
/*   Updated: 2025/02/18 19:16:08 by asaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *stack)
{
	int	top;
	int	mid;
	int	bottom;

	top = stack->head->index;
	mid = stack->head->next->index;
	bottom = stack->tail->index;
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

void	sort_four_or_two(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
	{
		if (stack_a->head->index > stack_a->head->next->index)
			sa(stack_a);
	}
	else if (stack_a->size == 4)
	{
		push_smallest_to_b(stack_a, stack_b);
		sort_three(stack_a);
		pa(stack_a, stack_b);
	}
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	push_smallest_to_b(stack_a, stack_b);
	push_smallest_to_b(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
