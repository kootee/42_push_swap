/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dbl_rot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:24:16 by ktoivola          #+#    #+#             */
/*   Updated: 2024/04/04 15:06:08 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	count_cmds(t_stk_node **b, int val_to_find, int cmd)
{
	t_stk_node	*temp;
	int			rot_count;

	rot_count = 0;
	if (cmd == R)
	{
		temp = *b;
		while (temp->value != val_to_find)
		{
			temp = temp->next;
			rot_count++;
		}
	}
	else if (cmd == RR)
	{
		rot_count++;
		temp = find_last(*b);
		while (temp->value != val_to_find)
		{
			temp = temp->prev;
			rot_count++;
		}
	}
	return (rot_count);
}

void	check_dbl_rot(t_stk_node **a, t_stk_node **b, int rot_a, int val)
{
	int	rot_b;

	if (rot_a >= 0)
	{
		rot_b = sort_b_stack(b, val, R);
		while ((rot_a > 0 && rot_b > 0) && (rot_a-- && rot_b--))
			rr(a, b, 0);
		while (rot_a--)
			ra(a, 0);
		while (rot_b--)
			rb(b, 0);
	}
	else
	{
		rot_a *= -1;
		rot_b = sort_b_stack(b, val, RR);
		while ((rot_a > 0 && rot_b > 0) && (rot_a-- && rot_b--))
			rrr(a, b, 0);
		while (rot_a--)
			rra(a, 0);
		while (rot_b--)
			rrb(b, 0);
	}
	pb(b, a, 0);
}
