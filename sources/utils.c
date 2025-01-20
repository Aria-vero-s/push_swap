/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaulnie <asaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:05:55 by ariane            #+#    #+#             */
/*   Updated: 2025/01/20 21:18:19 by asaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(char *msg)
{
	printf("%s\n", msg);
	exit (1);
}

void	check_if_duplicates(t_stack *stack_a)
{
	t_node	*current;
	t_node	*temp;

	temp = stack_a->node;
	while (temp)
	{
		current = temp->next;
		while (current)
		{
			if (temp->value == current->value)
				error_exit("error: duplicates found");
			current = current->next;
		}
		temp = temp->next;
	}
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
