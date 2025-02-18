/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaulnie <asaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:47:32 by asaulnie          #+#    #+#             */
/*   Updated: 2025/02/18 19:50:40 by asaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_duplicates(t_stack *stack_a)
{
	t_node	*current;
	t_node	*temp;

	temp = stack_a->head;
	while (temp)
	{
		current = temp->next;
		while (current)
		{
			if (temp->value == current->value)
				return (1);
			current = current->next;
		}
		temp = temp->next;
	}
	return (0);
}

int	is_sorted(t_stack *stack_a)
{
	t_node	*current;

	current = stack_a->head;
	if (current == NULL || stack_a->size <= 1)
		return (1);
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	free_stack(stack_a);
	return (1);
}
