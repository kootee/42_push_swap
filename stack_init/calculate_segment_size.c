/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_segment_size.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:02:46 by ktoivola          #+#    #+#             */
/*   Updated: 2024/04/08 10:15:04 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	calculate_segment_size(int i)
{
	int	number_of_segments;

	number_of_segments = 7 + (((i - 100) * 3) / 200);
	return (number_of_segments);
}
