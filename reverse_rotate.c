/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:45:41 by ktoivola          #+#    #+#             */
/*   Updated: 2024/03/22 10:35:20 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    rev_rotate(t_stack_node **stack)
{
    t_stack_node    *last_node;
    int             len;
    
    len = stack_len(*stack);
    if (len == 1 || stack == NULL || *stack == NULL)
        return ;
    last_node = find_last(*stack);
    last_node->prev->next = NULL;
    last_node->next = *stack;
    last_node->prev = NULL;
    *stack = last_node;
    last_node->next->prev = last_node;
    }

void    rra(t_stack_node **a, int i)
{
    rev_rotate(a);
    if (!i)
        write(1, "rra\n", 4);
}

void    rrb(t_stack_node **b, int i)
{
    rev_rotate(b);
    if (!i)
        write(1, "rrb\n", 4);
}

void    rrr(t_stack_node **a, t_stack_node **b, int i)
{
    rev_rotate(a);
    rev_rotate(b);
    if (!i)
        write(1, "rrr\n", 4);
}