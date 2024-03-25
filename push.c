/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:14:48 by ktoivola          #+#    #+#             */
/*   Updated: 2024/03/15 10:40:45 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void push(t_stack_node **from_stack, t_stack_node **to_stack)
{
    t_stack_node *node_to_push;
    
    if (*from_stack == NULL)
        return ;
    node_to_push = *from_stack;
    *from_stack = (*from_stack)->next;
    if (*from_stack)
        (*from_stack)->prev = NULL;
    node_to_push->next = NULL;
    if (*to_stack == NULL)
    {
        *to_stack = node_to_push;
        // node_to_push->next = NULL;
    }
    else
    {
        node_to_push->next = *to_stack;
        node_to_push->next->prev = node_to_push;
        *to_stack = node_to_push;
    }
}
void    pa(t_stack_node **a, t_stack_node **b, int i)
{
    push(b, a);
    if (!i)
        write(1, "pa\n", 3);
}

void    pb(t_stack_node **b, t_stack_node **a, int i)
{
    push(a, b);
    if (!i)
        write(1, "pb\n", 3);
}