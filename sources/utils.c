/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaulnie <asaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:05:55 by ariane            #+#    #+#             */
/*   Updated: 2025/02/03 15:31:56 by asaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(char *msg)
{
	ft_printf("%s", msg);
	exit (0);
}

void	check_if_duplicates(t_stack *stack_a, t_stack *stack_b)
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
			{
				free_stack(stack_a);
				free_stack(stack_b);
				error_exit("Error\n");
			}
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
		ft_printf("%d\n", current->value);
		current = current->next;
	}
}

void	print_values(int *values, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_printf("%d\n", values[i]);
		i++;
	}
}
