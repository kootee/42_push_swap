/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:59:44 by ktoivola          #+#    #+#             */
/*   Updated: 2024/03/28 09:59:22 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stk_node    *new_stack_node(int n)
{
    t_stk_node    *new_node;
    
    new_node = malloc(sizeof(t_stk_node));
    if (!new_node)
        return (NULL); // what to do down the line
    new_node->value = n;
    new_node->next = NULL;
    return (new_node);
}

static void add_to_stack(t_stk_node **stack, t_stk_node *new_node)
{
    t_stk_node    *top_of_stack;
    
    if (!stack || !new_node)
        return ;
    if (!*stack)
    {
        *stack = new_node;
        new_node->prev = NULL;
        return ;
    }
    top_of_stack = find_last(*stack);
    top_of_stack->next = new_node;
    new_node->prev = top_of_stack;
}

void    append_node(t_stk_node **a, int n)
{
    t_stk_node    *new_node;

    new_node = new_stack_node(n);
    new_node->index = -1;
    add_to_stack(a, new_node);
}