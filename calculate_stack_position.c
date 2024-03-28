/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_stack_position.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 10:49:00 by ktoivola          #+#    #+#             */
/*   Updated: 2024/03/28 11:39:26 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_position(t_stk_node *node, int pos)
{
	int	i;
	t_stk_node *temp;

	i = 1;
	temp = node;
	while (temp && i != pos)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

int calculate_cmd(t_stk_node **stack, int node_index)
{
	int	s_len;
    t_stk_node *temp;
	
    temp = *stack;
	s_len = stack_len(*stack);
	if (s_len % 2 == 0) // if stack len is even
	{
		if (node_index > s_len / 2)
			return (RR);
		else
			return (R);
	}
	else
	{
		if (node_index == calculate_position(*stack, (s_len / 2 + 1)))
			return (EOR);
		if (node_index < calculate_position(*stack, (s_len / 2 + 1)))
			return (R);
		else
			return (RR);
	}
}
