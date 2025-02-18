/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaulnie <asaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:05:55 by ariane            #+#    #+#             */
/*   Updated: 2025/02/18 19:51:25 by asaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(1);
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	current = stack->head;
	while (current)
	{
		next = current->next;
		free(current);
		current = NULL;
		current = next;
	}
}

void	reindex(t_stack *stack)
{
	t_node	*base;
	t_node	*current;

	base = stack->head;
	while (base)
	{
		base->index = 1;
		current = stack->head;
		while (current)
		{
			if (base->value > current->value)
				base->index++;
			current = current->next;
		}
		base = base->next;
	}
}

void	print_stack(t_stack *stack)
{
	t_node	*current;

	current = stack->head;
	while (current)
	{
		ft_printf("%d   -   %d\n", current->index, current->value);
		current = current->next;
	}
}
