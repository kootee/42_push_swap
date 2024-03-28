/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:53:36 by ktoivola          #+#    #+#             */
/*   Updated: 2024/03/28 09:59:22 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void swap(t_stk_node **head)
{
    if (*head == NULL || head == NULL || stack_len(*head) == 1)
        return ;
    *head = (*head)->next;
    (*head)->prev->prev = *head;
    (*head)->prev->next = (*head)->next;
    if ((*head)->next)
        (*head)->next->prev = (*head)->prev;
    (*head)->next = (*head)->prev;
    (*head)->prev = NULL;
}

void    sa(t_stk_node **a, int i)
{
    swap(a);
    if (i != 2)
        write(1, "sa\n", 3);
}

void    sb(t_stk_node **b, int i)
{
    swap(b);
    if (i != 2)
        write(1, "sb\n", 3);
}

void    ss(t_stk_node **a, t_stk_node **b, int i)
{
    swap(a);
    swap(b);
    if (!i)
        write(1, "ss\n", 3);
}