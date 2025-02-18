/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaulnie <asaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:05:19 by asaulnie          #+#    #+#             */
/*   Updated: 2025/02/18 19:44:05 by asaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	t_node	*first;

	if (a->size < 2)
		return ;
	first = pop(a);
	push_back(a, first);
	ft_printf("ra\n");
}

void	rra(t_stack *a)
{
	t_node	*last;

	if (a->size < 2)
		return ;
	last = pop_back(a);
	push(a, last);
	ft_printf("rra\n");
}

void	rb(t_stack *b)
{
	t_node	*first;

	if (b->size < 2)
		return ;
	first = pop(b);
	push_back(b, first);
	ft_printf("rb\n");
}

void	rrb(t_stack *b)
{
	t_node	*last;

	if (b->size < 2)
		return ;
	last = pop_back(b);
	push(b, last);
	ft_printf("rrb\n");
}
