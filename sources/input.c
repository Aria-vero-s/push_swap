/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaulnie <asaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:04:44 by ariane            #+#    #+#             */
/*   Updated: 2025/02/18 19:45:16 by asaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_int(char *str)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		num = num * 10 + (*str - '0');
		if ((num * sign) > INT_MAX || (num * sign) < INT_MIN)
			return (0);
		str++;
	}
	return (1);
}

void	init_stack(t_stack *stack)
{
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
}

void	create_and_push_back(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof (t_node));
	if (!new_node)
	{
		free_stack(stack);
		error_exit("Error\n");
	}
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->value = value;
	new_node->index = -1;
	if (stack->tail)
	{
		stack->tail->next = new_node;
		new_node->prev = stack->tail;
		stack->tail = new_node;
	}
	else
	{
		stack->head = new_node;
		stack->tail = new_node;
	}
	stack->size++;
}

void	parse_multiple_args(int argc, char **argv, t_stack *stack)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_valid_int(argv[i]))
		{
			free_stack(stack);
			error_exit("Error\n");
		}
		create_and_push_back(stack, ft_atoi(argv[i]));
		i++;
	}
}

void	parse_input(int argc, char **argv, t_stack *stack)
{
	if (argc < 2)
		exit(0);
	if (argc == 2)
		parse_single_arg(argv[1], stack);
	parse_multiple_args(argc, argv, stack);
}
