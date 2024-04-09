/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:44:04 by ktoivola          #+#    #+#             */
/*   Updated: 2024/04/09 10:32:44 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	index_nodes(t_stk_node **stack, int segment_size)
{
	int			i;
	int			len;
	t_stk_node	*min_node;

	if (*stack == NULL)
		return ;
	i = 0;
	len = stack_len(*stack);
	while (i < segment_size)
	{
		min_node = find_min(*stack, true);
		min_node->index = i;
		i++;
	}
}

static void	push_closest_to_top(t_stk_node **a, t_stk_node **b, int nodes[2])
{
	int			rot;
	t_stk_node	*temp;

	if (stack_len(*a) == 4)
	{
		nodes[0] = find_min(*a, false)->value;
		nodes[1] = find_min(*a, false)->value;
	}
	rot = 0;
	temp = *a;
	if (!*a)
		return ;
	if (compare_cost(a, nodes[0], nodes[1]) <= 0)
	{
		while (temp->value != nodes[0] && ++rot)
			temp = temp->next;
		check_dbl_rot(a, b, rot, nodes[0]);
	}
	else
	{
		temp = find_last(*a);
		while (++rot && temp->value != nodes[1])
			temp = temp->prev;
		check_dbl_rot(a, b, rot * -1, nodes[1]);
	}
}

static void	find_nodes_to_hold(t_stk_node **a, int segment_size, int nodes[2])
{
	t_stk_node	*temp;

	temp = *a;
	nodes[0] = INT_MIN;
	nodes[1] = INT_MIN;
	while (temp)
	{
		if (temp->index < segment_size && temp->index >= 0)
		{
			nodes[0] = temp->value;
			break ;
		}
		temp = temp->next;
	}
	temp = find_last(*a);
	while (temp && temp != *a)
	{
		if (temp->index < segment_size && temp->index >= 0)
		{
			nodes[1] = temp->value;
			break ;
		}
		temp = temp->prev;
	}
}

void	push_swap(t_stk_node **a, t_stk_node **b, int segment_size)
{
	int			i;
	int			hold_node[2];
	t_stk_node	*temp;

	temp = *a;
	while (*a)
	{
		i = 0;
		index_nodes(a, segment_size);
		while (i++ < segment_size && *a != NULL)
		{
			find_nodes_to_hold(a, segment_size, hold_node);
			push_closest_to_top(a, b, hold_node);
		}
	}
	final_sort_b_stack(b);
	while (*b)
		pa(a, b);
}
