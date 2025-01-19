/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariane <ariane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 19:58:52 by asaulnie          #+#    #+#             */
/*   Updated: 2025/01/19 19:18:01 by ariane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pb(t_stack *a, t_stack *b)
{
	int value;

	if (a->size == 0)
		return ;
	value = pop(a);
	push(b, value);
}

void pa(t_stack *a, t_stack *b)
{
	int	value;

	if (b->size == 0)
		return ;
	value = pop(b);
	push(a, value);
}