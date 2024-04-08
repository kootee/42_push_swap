/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:44:04 by ktoivola          #+#    #+#             */
/*   Updated: 2024/04/05 15:35:15 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	index_nodes(t_stk_node **stack, int segment_size)
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

int	compare_cost(t_stk_node **stack, int hold_1, int hold_2)
{
	int			i;
	int			j;
	t_stk_node	*temp;

	temp = *stack;
	i = 0;
	j = 1;
	while (temp && temp->value != hold_1)
	{
		temp = temp->next;
		i++;
	}
	temp = find_last(*stack);
	while (temp && temp->value != hold_2)
	{
		temp = temp->prev;
		j++;
	}
	return (i - j);
}

void	push_closest_to_top(t_stk_node **a, t_stk_node **b, int on_hold[2])
{
	int			rot;
	t_stk_node	*temp;

	if (stack_len(*a) == 4)
	{
		on_hold[0] = find_min(*a, 0)->value;
		on_hold[1] = find_min(*a, 0)->value;
	}
	rot = 0;
	temp = *a;
	if (!*a)
		return ;
	if (compare_cost(a, on_hold[0], on_hold[1]) <= 0)
	{
		while (temp->value != on_hold[0] && ++rot)
			temp = temp->next;
		check_dbl_rot(a, b, rot, on_hold[0]);
	}
	else
	{
		temp = find_last(*a);
		while (++rot && temp->value != on_hold[1])
			temp = temp->prev;
		check_dbl_rot(a, b, rot * -1, on_hold[1]);
	}
}

void	find_nodes_to_hold(t_stk_node **a, int segment_size, int hold_node[2])
{
	t_stk_node	*temp;

	temp = *a;
	hold_node[0] = INT_MIN;
	hold_node[1] = INT_MIN;
	while (temp)
	{
		if (temp->index < segment_size && temp->index >= 0)
		{
			hold_node[0] = temp->value;
			break ;
		}
		temp = temp->next;
	}
	temp = find_last(*a);
	while (temp && temp != *a)
	{
		if (temp->index < segment_size && temp->index >= 0)
		{
			hold_node[1] = temp->value;
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
	while (stack_len(*a) > 3)
	{
		i = 0;
		index_nodes(a, segment_size);
		while (i++ < segment_size && *a != NULL)
		{
			ft_printf("---A---\n");
			print_stack(a);
			ft_printf("---B---\n");
			print_stack(b);
			find_nodes_to_hold(a, segment_size, hold_node);
			push_closest_to_top(a, b, hold_node);
		}
	}
	if (compare_cost(b, find_max(*b)->value, find_max(*b)->value) <= 0)
	{
		while (find_max(*b) != *b)
			rb(b, 0);
	}
	while (find_max(*b) != *b)
		rrb(b, 0);
	while (*b)
		pa(a, b, 0);
}
