/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_stack_position.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 10:49:00 by ktoivola          #+#    #+#             */
/*   Updated: 2024/04/08 16:07:14 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_node_idx(t_stk_node *stack, t_stk_node *node_to_find)
{
	int			i;

	i = 1;
	while (stack != node_to_find)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

int	calculate_cmd(t_stk_node **stack, t_stk_node *node_to_find)
{
	t_stk_node	*temp;
	int			s_len;
	int			node_index;

	temp = *stack;
	node_index = get_node_idx(*stack, node_to_find);
	s_len = stack_len(*stack);
	if (s_len % 2 == 0)
	{
		if (node_index > s_len / 2)
			return (RR);
		else
			return (R);
	}
	else
	{
		if (node_index == (s_len / 2 + 1))
			return (EOR);
		if (node_index < (s_len / 2 + 1))
			return (R);
		else
			return (RR);
	}
}

int	calculate_cost_to_top(t_stk_node *stack, t_stk_node *node)
{
	int	cost_to_top;
	int	node_idx;
	int	len;

	node_idx = get_node_idx(stack, node);
	len = stack_len(stack);
	if (node_idx > len / 2 + 1)
		cost_to_top = len - node_idx + 1;
	else
		cost_to_top = node_idx - 1;
	return (cost_to_top);
}
