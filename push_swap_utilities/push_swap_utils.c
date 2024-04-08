/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:47:56 by ktoivola          #+#    #+#             */
/*   Updated: 2024/04/08 15:57:09 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	do_twice(void (*f)(t_stk_node **a, int i), t_stk_node **s, int x)
{
	f(s, x);
	f(s, x);
}

bool	is_sorted(t_stk_node *stack)
{
	if (stack == NULL)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	handle_error(t_stk_node **stack, char **argv, int argc)
{
	char	*error_message;
	int		i;

	i = 0;
	error_message = "Error\n";
	while (error_message[i])
		ft_putchar_fd(error_message[i++], STDERR_FILENO);
	if (argc == 2)
		free_list(argv);
	argv = NULL;
	free_stack(stack);
	exit (0);
}
