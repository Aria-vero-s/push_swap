/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaulnie <asaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:22:53 by asaulnie          #+#    #+#             */
/*   Updated: 2025/02/12 22:24:36 by asaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	values_to_array(t_stack *stack, int *values)
{
	t_node	*current;
	int		i;

	current = stack->node;
	i = 0;
	while (current)
	{
		values[i] = current->value;
		i++;
		current = current->next;
	}
}

void	sort_values(int *values, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (values[i] > values[j])
			{
				temp = values[i];
				values[i] = values[j];
				values[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	set_positions(t_stack *stack)
{
	int		*values;
	t_node	*current;
	int		i;

	values = malloc(stack->size * sizeof(int));
	if (!values)
		error_exit("Error\n");
	values_to_array(stack, values);
	sort_values(values, stack->size);
	current = stack->node;
	while (current)
	{
		i = 0;
		while (i < stack->size)
		{
			if (current->value == values[i])
			{
				current->index = i;
				break ;
			}
			i++;
		}
		current = current->next;
	}
	free(values);
}
