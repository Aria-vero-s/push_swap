/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaulnie <asaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:06:14 by ariane            #+#    #+#             */
/*   Updated: 2025/01/18 20:00:13 by asaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = parse_input(argc, argv);
	stack_b = init_stack();
	if (!stack_a)
	{
		printf("Error: no stack_a\n");
		return (1);
	}
	print_before(stack_a);
	if (stack_a->size == 3)
		sort_three(stack_a);
	else if (stack_a->size == 5)
		sort_five(stack_a, stack_b);
	print_stack(stack_a);
	free_stack(stack_a);
	return (0);
}
