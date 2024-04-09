/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:53:36 by ktoivola          #+#    #+#             */
/*   Updated: 2024/04/09 10:32:04 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap(t_stk_node **head)
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

void	sa(t_stk_node **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stk_node **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stk_node **a, t_stk_node **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
