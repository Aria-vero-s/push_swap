/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaulnie <asaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 19:58:52 by asaulnie          #+#    #+#             */
/*   Updated: 2025/02/18 19:22:04 by asaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack *a, t_stack *b)
{
	t_node	*popped_node;

	if (a->size == 0)
		return ;
	popped_node = pop(a);
	push(b, popped_node);
	ft_printf("pb\n");
}

void	pa(t_stack *a, t_stack *b)
{
	t_node	*popped_node;

	if (b->size == 0)
		return ;
	popped_node = pop(b);
	push(a, popped_node);
	ft_printf("pa\n");
}
