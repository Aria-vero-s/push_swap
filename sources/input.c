/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariane <ariane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:04:44 by ariane            #+#    #+#             */
/*   Updated: 2025/01/19 17:45:18 by ariane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_int(char *str)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		num = num * 10 + (*str - '0');
		if (num * sign > INT_MAX || num * sign < INT_MIN)
			return (0);
		str++;
	}
	return (1);
}

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		error_exit("Error: malloc() failed");
	stack->node = NULL;
	stack->size = 0;
	return (stack);
}

t_stack	*parse_input(int argc, char **argv)
{
	t_stack	*stack;
	int		i;

	i = 1;
	stack = init_stack();
	while (i < argc)
	{
		if (!is_valid_int(argv[i]))
			error_exit("Error: invalid argument(s)");
		push(stack, atoi(argv[i]));
		i++;
	}
	return (stack);
}
