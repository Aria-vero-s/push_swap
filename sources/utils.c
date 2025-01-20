/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaulnie <asaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:05:55 by ariane            #+#    #+#             */
/*   Updated: 2025/01/20 14:03:04 by asaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(char *msg)
{
	printf("%s\n", msg);
	exit (1);
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

void	print_before(t_stack *stack_a)
{
	t_node	*current;

	current = stack_a->node;
	while (current != NULL)
	{
		printf("before: %d\n", current->value);
		current = current->next;
	}
}
