/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:37:10 by ktoivola          #+#    #+#             */
/*   Updated: 2024/04/08 15:36:55 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_list(char **ptr)
{
	int	i;

	i = 0;
	if (ptr == NULL || *ptr == NULL)
		return ;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

void	free_stack(t_stk_node **stack)
{
	t_stk_node	*temp;
	t_stk_node	*current;

	if (stack == NULL || *stack == NULL)
		return ;
	current = *stack;
	while (current)
	{
		temp = (current)->next;
		free(current);
		current = temp;
	}
	*stack = NULL;
}
