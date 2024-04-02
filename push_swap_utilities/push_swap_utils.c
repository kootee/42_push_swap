/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:47:56 by ktoivola          #+#    #+#             */
/*   Updated: 2024/03/31 14:52:47 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    do_twice(void (*f)(t_stk_node **a, int i), t_stk_node **s, int x)
{
    f(s, x);
    f(s, x);
}

t_stk_node *find_max(t_stk_node *stack)
{
    int             max_val;
    t_stk_node    *max_node;

    if (stack == NULL)
        return (NULL);
    max_val = INT_MIN;
    while (stack)
    {
        if (stack->value > max_val)
        {
            max_val = stack->value;
            max_node = stack;
        }
        stack = stack->next;
    }
    return (max_node);
}

t_stk_node    *find_min(t_stk_node *stack, bool for_index)
{
    int             min_val;
    t_stk_node    *min_node;

    if (stack == NULL)
        return (NULL);
    min_val = INT_MAX;
    while (stack)
    {
        if (stack->value < min_val && !for_index)
        {
            min_val = stack->value;
            min_node = stack;
        }
        else if (stack->value < min_val && stack->index < 0)
        {
            min_val = stack->value;
            min_node = stack;
        }
        stack = stack->next;
    }
    return (min_node);
}

t_stk_node *find_last(t_stk_node *node)
{
    if (node == NULL)
        return (NULL);
    while (node->next)
        node = node->next;
    return (node);
}

int stack_len(t_stk_node *stack)
{
    int i;

    i = 0;
    while (stack)
    {
        i++;
        stack = stack->next;
    }
    return (i);
}