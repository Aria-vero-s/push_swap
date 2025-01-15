/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariane <ariane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:06:14 by ariane            #+#    #+#             */
/*   Updated: 2025/01/15 13:28:51 by ariane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *stack_a;

    if (argc < 2)
        return (0);
    stack_a = parse_input(argc, argv);
    if (!stack_a)
    {
        printf("Error: no stack_a\n");
        return (1);
    }
    print_stack(stack_a);
    free_stack(stack_a);
    return (0);
}
