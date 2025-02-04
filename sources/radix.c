/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaulnie <asaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:22:03 by asaulnie          #+#    #+#             */
/*   Updated: 2025/02/03 15:40:16 by asaulnie         ###   ########.fr       */
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
	int		j;

	values = malloc(stack->size * sizeof(int));
	if (!values)
		error_exit ("Error\n");
	values_to_array(stack, values);
	sort_values(values, stack->size);
	current = stack->node;
	while (current)
	{
		j = 0;
		while (j < stack->size)
		{
			if (current->value == values[j])
			{
				current->index = j;
				break ;
			}
			j++;
		}
		current = current->next;
	}
	free(values);
}

void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	max_bits;
	int	max_index;
	int	i;
	int	size;

	max_bits = 0;
	max_index = stack_a->size - 1;
	while ((max_index >> max_bits) != 0)
		max_bits++;
	set_positions(stack_a);
	i = 0;
	while (i < max_bits)
	{
		size = stack_a->size;
		while (size-- > 0)
		{
			// printf("index value : %d\n", stack_a->node->index);
			if (((stack_a->node->index >> i) & 1) == 1)
					ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (stack_b->size > 0)
			pa(stack_a, stack_b);
		i++;
	}
}
