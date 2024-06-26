/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:50:50 by ktoivola          #+#    #+#             */
/*   Updated: 2024/04/09 10:12:16 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	calculate_segment_size(t_stk_node **a)
{
	int	stack_size;
	int	number_of_segments;

	stack_size = stack_len(*a);
	number_of_segments = 5 + (((stack_size - 100) * 3) / 200);
	return (number_of_segments);
}

static long	ft_atol(const char *str)
{
	long	nbr;
	int		sign;

	nbr = 0;
	sign = 1;
	while (('\t' <= *str && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nbr = (nbr * 10) + (*str - '0');
		str++;
	}
	return (nbr * sign);
}

static int	duplicate_error(t_stk_node *a, int n)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if (a->value == n)
			return (1);
		a = a->next;
	}
	return (0);
}

static int	input_error(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	if (!('0' <= str[i] && str[i] <= '9'))
		return (1);
	while (str[i])
	{
		if (!('0' <= str[i] && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

void	init_stack(t_stk_node **a, char **argv, int argc)
{
	long	n;
	int		i;

	i = 0;
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	if (*argv == NULL)
		handle_error(a, argv, 1);
	if (argc > 2)
		i++;
	while (argv[i])
	{
		if (input_error(argv[i]))
			handle_error(a, argv, argc);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			handle_error(a, argv, argc);
		if (duplicate_error(*a, n))
			handle_error(a, argv, argc);
		if (append_node(a, n))
			handle_error(a, argv, argc);
		i++;
	}
	if (argc == 2)
		free_list(argv);
}
