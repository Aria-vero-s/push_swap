/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaulnie <asaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:45:41 by asaulnie          #+#    #+#             */
/*   Updated: 2025/01/13 14:55:49 by asaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int sa(t_stack_data *a, t_stack_data *b)
{
    int i;

    i = 0;
    while (i < a->int_quantity)
    {
        printf("tab de sa %d\n", a->tab[i]);
        i++;
    }
    printf("2e sa%d\n", a->tab[0]);
    printf("3e sa%d\n", b->tab[0]);
    return (i);
}