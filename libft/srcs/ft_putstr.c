/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 09:53:22 by ktoivola          #+#    #+#             */
/*   Updated: 2024/03/01 13:10:32 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_putstr(char *s)
{
	int	len;

	if (!s)
	{
		if (0 > write(1, "(null)", 6))
			return (-1);
		return (6);
	}
	len = ft_strlen(s);
	if (0 > write(1, s, len))
		return (-1);
	return (len);
}