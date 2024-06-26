/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:10:01 by ktoivola          #+#    #+#             */
/*   Updated: 2024/04/09 10:32:36 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stk_node	*a;
	t_stk_node	*b;
	int			segment_size;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	init_stack(&a, argv, argc);
	if (!is_sorted(a))
	{
		segment_size = stack_len(a) / calculate_segment_size(&a);
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			sort_ministack_3(&a);
		else if (stack_len(a) == 4)
			sort_ministack_4(&a, &b);
		else if (stack_len(a) == 5)
			sort_ministack_5(&a, &b);
		else
			push_swap(&a, &b, segment_size);
	}
	free_stack(&a);
}
