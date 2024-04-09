/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:32:47 by ktoivola          #+#    #+#             */
/*   Updated: 2024/04/09 10:31:39 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_stk_node **stack)
{
	t_stk_node	*last_node;
	int			len;

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

void	ra(t_stk_node **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stk_node **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stk_node **a, t_stk_node **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
