/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaulnie <asaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:06:14 by ariane            #+#    #+#             */
/*   Updated: 2025/02/18 20:53:07 by asaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	init_stack(&stack_a);
	init_stack(&stack_b);
	parse_input(argc, argv, &stack_a);
	if (check_if_duplicates(&stack_a))
	{
		free_stack(&stack_a);
		error_exit("Error\n");
	}
	reindex(&stack_a);
	if (is_sorted(&stack_a))
		return (0);
	if (stack_a.size == 3)
		sort_three(&stack_a);
	else if (stack_a.size == 4 || stack_a.size == 2)
		sort_four_or_two(&stack_a, &stack_b);
	else if (stack_a.size == 5)
		sort_five(&stack_a, &stack_b);
	else if (stack_a.size > 5)
		big_sort_launcher(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
