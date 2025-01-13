/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaulnie <asaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:59:16 by asaulnie          #+#    #+#             */
/*   Updated: 2025/01/13 14:55:54 by asaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    error_msg()
{
    printf("Error\n");
    exit(-1);
}

int check_digit(char a)
{
    if ((a >= '0' && a <= '9'))
        return (0);
    return (1);
}

int check_arg(char *str)
{
    int                 i;
    int                 sign;
    unsigned long long  result;

    i = 0;
    sign = 1;
    result = 0;
    
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i])
    {
        if (check_digit(str[i]))
            error_msg();
        result = result * 10 + (str[i] - '0');
        if ((sign == 1 && result > (unsigned long long)INT_MAX) || (sign == -1 && result > (unsigned long long)INT_MAX + 1))
            error_msg();
        i++;
    }
    return (0);
}

int    main(int argc, char **argv)
{
    t_stack_data    a;
    t_stack_data    b;
    int i;
    int j;

    j = 1;
    while (j < argc)
    {
        if (check_arg(argv[j]) != 0)
            return (-1);
        else
            j++;
    }
    i = 0;
    j = 1;
    a.tab = malloc(sizeof(int) * (argc - 1));
    b.tab = malloc(sizeof(int) * (argc - 1));
    while (j < argc)
    {
        a.tab[i] = atoi(argv[j]);
        i++;
        j++;
    }
    i = 0;
    while (i < (argc - 1))
    {
        printf("tab %d\n", a.tab[i]);
        i++;
    }
    a.int_quantity = argc - 1;
    printf("sa: %d\n", sa(&a, &b));
    return (0);
}