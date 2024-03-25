/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:37:10 by ktoivola          #+#    #+#             */
/*   Updated: 2024/03/15 12:12:27 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* MAKE PRINTF YOUR OWN PRINTF */

void    handle_error(t_stack_node **stack,char **argv, int i)
{
    free_stack(stack);
    // free_list(argv);
    argv = NULL;
    if (i == 1)
        printf("incorrect input, only positive or negative numbers allowed\n");
    else if (i == 2)
        printf("memory overflow, enter numbers between MAX_INT and MIN_INT\n");
    else if (i == 3)
        printf("no duplicate numbers allowed\n");
    exit(i);
}


void    free_list(char **ptr)
{
    int i;

    i = 0;
    if (ptr == NULL || *ptr == NULL)
        return ;
    while (ptr[i])
    {
        free(ptr[i]);
        i++;
    }
    free(ptr);
}

void    free_stack(t_stack_node **stack)
{
    t_stack_node    *temp;
    t_stack_node    *current;

    if (stack == NULL)
        return ;
    current = *stack;
    while (current)
    {
        temp = (current)->next;
        free(current);
        current = temp;
    }
    *stack = NULL;
}