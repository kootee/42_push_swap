/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ministack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:32:35 by ktoivola          #+#    #+#             */
/*   Updated: 2024/04/04 15:01:10 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_ministack_3(t_stk_node **stack)
{
	if (is_sorted(*stack))
		return ;
	if ((*stack)->value > (*stack)->next->value
		&& (*stack)->next->next->value > (*stack)->value)
		sa(stack, 0);
	else if ((*stack)->value > (*stack)->next->value
		&& (*stack)->next->value > (*stack)->next->next->value)
	{
		sa(stack, 0);
		rra(stack, 0);
	}
	else if ((*stack)->value > (*stack)->next->next->value
		&& (*stack)->next->next->value > (*stack)->next->value)
		ra(stack, 0);
	else if (((*stack)->next->value > (*stack)->next->next->value)
		&& ((*stack)->next->value > (*stack)->value)
		&& ((*stack)->value > (*stack)->next->next->value))
		rra(stack, 0);
	else
	{
		sa(stack, 0);
		ra(stack, 0);
	}
}

void	sort_ministack_4(t_stk_node **a, t_stk_node **b)
{
	t_stk_node	*min_node;

	while (stack_len(*a) > 2)
	{
		min_node = find_min(*a, false);
		if (min_node == (*a)->next)
			sa(a, 0);
		else if (min_node == find_last(*a))
			rra(a, 0);
		else if (min_node == find_last(*a)->prev)
			do_twice(rra, a, 0);
		pb(b, a, 0);
	}
	if ((*a)->value > (*a)->next->value)
		sa(a, 0);
	pa(a, b, 0);
	pa(a, b, 0);
}

void	sort_ministack_5(t_stk_node **a, t_stk_node **b)
{
	t_stk_node	*min_node;

	while (stack_len(*a) > 3)
	{
		min_node = find_min(*a, false);
		if (min_node == (*a)->next)
			sa(a, 0);
		else if (min_node == find_last(*a)->prev)
			do_twice(rra, a, 0);
		else if (min_node == (*a)->next->next)
			do_twice(ra, a, 0);
		else if (min_node == find_last(*a))
			rra(a, 0);
		pb(b, a, 0);
	}
	sort_ministack_3(a);
	if ((*b)->value < (*b)->next->value)
		sb(b, 0);
	pa(a, b, 0);
	pa(a, b, 0);
}
