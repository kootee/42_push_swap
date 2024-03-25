/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:10:01 by ktoivola          #+#    #+#             */
/*   Updated: 2024/03/22 11:39:50 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    print_stack(t_stack_node **stack)
{
    t_stack_node *temp;
    
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
    t_stack_node    *stack_a;
    t_stack_node    *stack_b;

    if (argc < 2 || !argv)
        exit(1);
    init_stack(&stack_a, &stack_b, argv, argc);
    printf("stack len is %d \n", stack_len(stack_a));
    if (!is_sorted(stack_a))
    {
        if (stack_len(stack_a) == 2)
            sa(&stack_a, 0);
        else if (stack_len(stack_a) == 3)
            sort_ministack_3(&stack_a);
        else if (stack_len(stack_a) == 4)
            sort_ministack_4(&stack_a, &stack_b);
        else if (stack_len(stack_a) == 5)
            sort_ministack_5(&stack_a, &stack_b);
        else
        {
            push_swap(&stack_a, &stack_b);
            while (stack_b)
                pa(&stack_a, &stack_b, 0);
        }
    }
    free_stack(&stack_a);
}

