/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaulnie <asaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:04:44 by ariane            #+#    #+#             */
/*   Updated: 2025/02/15 22:39:27 by asaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	handle_sign(char *str, int *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

int	is_valid_int(char *str)
{
	long	num;
	int		sign;
	int		i;

	i = 0;
	num = 0;
	if (!str || str[i] == '\0')
		return (0);
	sign = handle_sign(str, &i);
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		num = num * 10 + (str[i] - '0');
		if ((num * sign) > INT_MAX || (num * sign) < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		error_exit("Error\n");
	stack->node = NULL;
	stack->size = 0;
	return (stack);
}

t_stack	*parse_input(int argc, char **argv)
{
	t_stack	*stack;
	int		i;

	i = argc - 1;
	stack = init_stack();
	while (i > 0)
	{
		if (!is_valid_int(argv[i]))
		{
			free(stack);
			error_exit("Error\n");
		}
		push(stack, ft_atoi(argv[i]));
		i--;
	}
	return (stack);
}
