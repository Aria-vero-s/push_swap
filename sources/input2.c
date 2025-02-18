/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaulnie <asaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:36:36 by asaulnie          #+#    #+#             */
/*   Updated: 2025/02/18 20:53:30 by asaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_double_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	count_tokens(char **tokens)
{
	int	count;

	count = 0;
	while (tokens[count])
		count++;
	return (count);
}

void	handle_single_token(char **tokens)
{
	if (!is_valid_int(tokens[0]))
	{
		free_double_array(tokens);
		error_exit("Error\n");
	}
	free_double_array(tokens);
	exit(0);
}

void	push_tokens(char **tokens, int count, t_stack *stack)
{
	int	i;
	int	value;

	i = 0;
	while (i < count)
	{
		if (!is_valid_int(tokens[i]))
		{
			free_double_array(tokens);
			free_stack(stack);
			error_exit("Error\n");
		}
		value = ft_atoi(tokens[i]);
		create_and_push_back(stack, value);
		i++;
	}
}

void	parse_single_arg(char *arg, t_stack *stack)
{
	char	**tokens;

	if (ft_strlen(arg) == 0)
		error_exit("Error\n");
	if (arg[0] == '\0')
		exit(0);
	if (!ft_strchr(arg, ' '))
	{
		if (!is_valid_int(arg))
			error_exit("Error\n");
		exit(0);
	}
	tokens = ft_split(arg, ' ');
	if (!tokens)
		error_exit("Error\n");
	if (count_tokens(tokens) == 0)
	{
		free_double_array(tokens);
		exit(0);
	}
	if (count_tokens(tokens) == 1)
		handle_single_token(tokens);
	push_tokens(tokens, count_tokens(tokens), stack);
	free_double_array(tokens);
}
