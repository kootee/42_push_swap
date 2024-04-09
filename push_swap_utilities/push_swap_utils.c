/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:47:56 by ktoivola          #+#    #+#             */
/*   Updated: 2024/04/09 10:32:20 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	do_twice(void (*f)(t_stk_node **a), t_stk_node **s)
{
	f(s);
	f(s);
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
