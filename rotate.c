/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:32:47 by ktoivola          #+#    #+#             */
/*   Updated: 2024/03/22 10:35:20 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rotate(t_stack_node **stack)
{
    t_stack_node    *last_node;
    int             len;
    
    len = stack_len(*stack);
    if (len == 1 || stack == NULL || *stack == NULL)
        return ;
    last_node = find_last(*stack);
    last_node->next = *stack;
    *stack = (*stack)->next;
    (*stack)->prev = NULL;
    last_node->next->prev = last_node;
    last_node->next->next = NULL;
}

void    ra(t_stack_node **a, int i)
{
    rotate(a);
    if (!i)
        write(1, "ra\n", 3);
}

void    rb(t_stack_node **b, int i)
{
    rotate(b);
    if (!i)
        write(1, "rb\n", 3);
}

void    rr(t_stack_node **a, t_stack_node **b, int i)
{
    rotate(a);
    rotate(b);
    if (!i)
        write(1, "rr\n", 3);
}