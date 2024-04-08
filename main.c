/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:10:01 by ktoivola          #+#    #+#             */
/*   Updated: 2024/04/08 10:09:44 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/../includes/push_swap.h"

void    print_stack(t_stk_node **stack)
{
	t_stk_node *temp;
	
	ft_printf("stack:\n");
	temp = *stack;
	while (temp)
	{
		ft_printf("%i\n", temp->value);
		temp = temp->next;
	}
}

int	main(int argc, char **argv)
{
	t_stk_node	*a;
	t_stk_node	*b;
	int			segment_size;

	a = NULL;
	b = NULL;
	if (argc < 2)
		exit(1);
	init_stack(&a, argv, argc);
	ft_printf("stack len is %i\n", stack_len(a));
	if (!is_sorted(a))
	{
		segment_size = stack_len(a) / calculate_segment_size(&a);
		if (stack_len(a) == 2)
			sa(&a, 0);
		else if (stack_len(a) == 3)
			sort_ministack_3(&a);
		else if (stack_len(a) == 4)
			sort_ministack_4(&a, &b);
		else if (stack_len(a) == 5)
			sort_ministack_5(&a, &b);
		else
			push_swap(&a, &b, segment_size);
	}
	print_stack(&a);
	free_stack(&a);
}
