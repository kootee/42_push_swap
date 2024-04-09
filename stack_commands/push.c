/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:14:48 by ktoivola          #+#    #+#             */
/*   Updated: 2024/04/09 10:31:07 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push(t_stk_node **from_stack, t_stk_node **to_stack)
{
	t_stk_node	*node_to_push;

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
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *to_stack;
		node_to_push->next->prev = node_to_push;
		*to_stack = node_to_push;
	}
}

void	pa(t_stk_node **a, t_stk_node **b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_stk_node **b, t_stk_node **a)
{
	push(a, b);
	write(1, "pb\n", 3);
}
