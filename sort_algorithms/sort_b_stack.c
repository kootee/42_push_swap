/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:10:45 by ktoivola          #+#    #+#             */
/*   Updated: 2024/04/09 10:32:58 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	count_b_rot(t_stk_node **b, t_stk_node *temp, int a_cmd, int b_cmd)
{
	if (b_cmd == EOR)
		return (count_cmds(b, temp->value, a_cmd));
	else if (b_cmd == R)
	{
		if (a_cmd == R)
			return (count_cmds(b, temp->value, R));
		else
		{
			while (*b != temp)
				rb(b);
		}
	}
	else if (b_cmd == RR)
	{
		if (a_cmd == RR)
			return (count_cmds(b, temp->value, RR));
		else
		{
			while (*b != temp)
				rrb(b);
		}
	}
	return (0);
}

void	final_sort_b_stack(t_stk_node **b)
{
	if (compare_cost(b, find_max(*b)->value, find_max(*b)->value) <= 0)
	{
		while (find_max(*b) != *b)
			rb(b);
	}
	while (find_max(*b) != *b)
		rrb(b);
}

int	sort_b_stack(t_stk_node **b, int to_top, int a_cmd)
{
	t_stk_node	*temp;
	int			rot_b;
	int			b_cmd;

	temp = *b;
	if (stack_len(*b) < 2)
		return (0);
	if (to_top > find_max(*b)->value || to_top < find_min(*b, false)->value)
		temp = find_max(*b);
	else
	{
		while (temp->next)
		{
			if (to_top > temp->value && to_top < (find_last(*b))->value)
				break ;
			temp = temp->next;
			if (to_top > temp->value && to_top < temp->prev->value)
				break ;
		}
	}
	b_cmd = calculate_cmd(b, temp);
	rot_b = count_b_rot(b, temp, a_cmd, b_cmd);
	return (rot_b);
}
