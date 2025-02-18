/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaulnie <asaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:42:59 by asaulnie          #+#    #+#             */
/*   Updated: 2025/02/18 19:44:41 by asaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_all_to_a(t_stack *a, t_stack *b)
{
	t_node	*biggest;
	int		big_position;
	int		mid;

	while (b->size > 0)
	{
		biggest = get_biggest(b);
		big_position = find_position(b, biggest->index);
		mid = b->size / 2 - 1;
		while (big_position > -1 && biggest != b->head)
		{
			if (big_position < mid)
				rb(b);
			else
				rrb(b);
		}
		pa(a, b);
	}	
}

static void	sort_big(int delta, t_stack *a, t_stack *b)
{
	int		threshold;
	t_node	*current;

	threshold = 0;
	while (a->size > 0)
	{
		current = a->head;
		if (current->index <= threshold + delta)
		{
			pb(a, b);
			if (current->index <= threshold)
				rb(b);
			threshold++;
		}
		else
			ra(a);
	}
	sort_all_to_a(a, b);
}

void	big_sort_launcher(t_stack *a, t_stack *b)
{
	int	size;
	int	delta;

	size = a->size;
	if (size < 10)
		delta = 2;
	else if (size <= 25)
		delta = 3;
	else if (size <= 50)
		delta = 8;
	else if (size <= 100)
		delta = 13;
	else if (size <= 250)
		delta = 20;
	else if (size <= 500)
		delta = 32;
	else
		delta = 40;
	sort_big(delta, a, b);
}
