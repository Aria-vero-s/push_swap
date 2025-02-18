/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaulnie <asaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:00:57 by asaulnie          #+#    #+#             */
/*   Updated: 2025/02/18 19:43:32 by asaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	t_node	*first;
	t_node	*second;

	if (a->size < 2)
		return ;
	first = pop(a);
	second = pop(a);
	push(a, first);
	push(a, second);
	ft_printf("sa\n");
}
