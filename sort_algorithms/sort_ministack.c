/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ministack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:32:35 by ktoivola          #+#    #+#             */
/*   Updated: 2024/04/09 10:30:01 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_stk_node	*find_closest_min(t_stk_node *stack)
{
	int			min_val;
	t_stk_node	*temp;
	t_stk_node	*min_node;
	t_stk_node	*next_min_node;

	if (stack == NULL)
		return (NULL);
	temp = stack;
	min_val = INT_MAX;
	min_node = find_min(stack, false);
	while (temp)
	{
		if (temp->value < min_val && temp->value > min_node->value)
		{
			min_val = temp->value;
			next_min_node = temp;
		}
		temp = temp->next;
	}
	if (calculate_cost_to_top(stack, min_node)
		<= calculate_cost_to_top(stack, next_min_node))
		return (min_node);
	else
		return (next_min_node);
}

void	sort_ministack_3(t_stk_node **stack)
{
	if (is_sorted(*stack))
		return ;
	if ((*stack)->value > (*stack)->next->value
		&& (*stack)->next->next->value > (*stack)->value)
		sa(stack);
	else if ((*stack)->value > (*stack)->next->value
		&& (*stack)->next->value > (*stack)->next->next->value)
	{
		sa(stack);
		rra(stack);
	}
	else if ((*stack)->value > (*stack)->next->next->value
		&& (*stack)->next->next->value > (*stack)->next->value)
		ra(stack);
	else if (((*stack)->next->value > (*stack)->next->next->value)
		&& ((*stack)->next->value > (*stack)->value)
		&& ((*stack)->value > (*stack)->next->next->value))
		rra(stack);
	else
	{
		sa(stack);
		ra(stack);
	}
}

void	sort_ministack_4(t_stk_node **a, t_stk_node **b)
{
	t_stk_node	*min_node;

	while (stack_len(*a) > 2)
	{
		min_node = find_min(*a, false);
		if (min_node == (*a)->next)
			sa(a);
		else if (min_node == find_last(*a))
			rra(a);
		else if (min_node == find_last(*a)->prev)
			do_twice(rra, a);
		pb(b, a);
	}
	if ((*a)->value > (*a)->next->value)
		sa(a);
	while (*b)
		pa(a, b);
}

void	sort_ministack_5(t_stk_node **a, t_stk_node **b)
{
	t_stk_node	*node_to_push;

	while (stack_len(*a) > 3)
	{
		if (stack_len(*a) == 5)
			node_to_push = find_closest_min(*a);
		else
			node_to_push = find_min(*a, false);
		if (node_to_push == (*a)->next)
			sa(a);
		else if (node_to_push == find_last(*a)->prev)
			do_twice(rra, a);
		else if (node_to_push == (*a)->next->next)
			do_twice(ra, a);
		else if (node_to_push == find_last(*a))
			rra(a);
		pb(b, a);
	}
	sort_ministack_3(a);
	if ((*b)->value < (*b)->next->value)
		sb(b);
	while (*b)
		pa(a, b);
}
