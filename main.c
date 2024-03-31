/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:10:01 by ktoivola          #+#    #+#             */
/*   Updated: 2024/03/30 13:27:39 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    print_stack(t_stk_node **stack)
{
    t_stk_node *temp;
    
    printf("stack:\n");
    temp = *stack;
    while (temp)
    {
        printf("%i\n", temp->value);
        temp = temp->next;
    }
}

void    print_strings(char **argv)
{
    int i = 0;
    while (argv[i])
    {
        printf("num is %s\n", argv[i]);
        i++;
    }
    printf("end of numbers\n");
}

int main(int argc, char **argv)
{
    t_stk_node    *a;
    t_stk_node    *b;

    a = NULL;
    b = NULL;
    if (argc < 2 || !argv)
        exit(1);
    init_stack(&a, argv, argc);
    if (!is_sorted(a))
    {
        if (stack_len(a) == 2)
            sa(&a, 0);
        else if (stack_len(a) == 3)
            sort_ministack_3(&a);
        else if (stack_len(a) == 4)
            sort_ministack_4(&a, &b);
        else if (stack_len(a) == 5)
            sort_ministack_5(&a, &b);
        else
            push_swap(&a, &b);
    }
    print_stack(&a);
    free_stack(&a);
}

