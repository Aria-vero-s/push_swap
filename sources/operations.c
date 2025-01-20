/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaulnie <asaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 19:58:52 by asaulnie          #+#    #+#             */
/*   Updated: 2025/01/20 11:38:51 by asaulnie         ###   ########.fr       */
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
	printf("pb\n");
}

void pa(t_stack *a, t_stack *b)
{
	int	value;

	if (b->size == 0)
		return ;
	value = pop(b);
	push(a, value);
	printf("pa\n");
}