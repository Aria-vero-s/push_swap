/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaulnie <asaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 19:58:52 by asaulnie          #+#    #+#             */
/*   Updated: 2025/01/20 15:52:28 by asaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stack, int num)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		error_exit("Error: malloc() failed");
	new_node->value = num;
	new_node->next = stack->node;
	stack->node = new_node;
	stack->size++;
}

int	pop(t_stack *stack)
{
	t_node	*temp;
	int		num;

	if (stack->size == 0)
		error_exit("Error: empty stack");
	temp = stack->node;
	num = temp->value;
	stack->node = temp->next;
	free(temp);
	stack->size--;
	return (num);
}

void	free_stack(t_stack *stack)
{
	while (stack->size > 0)
		pop(stack);
	free(stack);
}

void pb(t_stack *a, t_stack *b)
{
	int value;

	if (a->size == 0)
		return ;
	value = pop(a);
	push(b, value);
	printf("pb\n");
}

void pa(t_stack *a, t_stack *b)
{
	int	value;

	if (b->size == 0)
		return ;
	value = pop(b);
	push(a, value);
	printf("pa\n");
}