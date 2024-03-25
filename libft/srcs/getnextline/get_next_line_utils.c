/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:08:45 by ktoivola          #+#    #+#             */
/*   Updated: 2024/03/25 09:59:48 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h" 

char	*clear_list(t_list **list, t_list *new_node, char *buffer)
{
	t_list	*temp;

	if (*list == NULL)
		return (NULL);
	while (*list)
	{
		temp = (*list)->next;
		free((*list)->string);
		free(*list);
		*list = temp;
	}
	*list = NULL;
	if (!new_node || *new_node->string)
		*list = new_node;
	else if (buffer != NULL && new_node != NULL)
	{
		free(buffer);
		free(new_node);
	}
	return (NULL);
}

void	add_clean_node(t_list *last_node, t_list *clean_node, char *buff)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (last_node->string[i] && last_node->string[i] != '\n')
		++i;
	while (last_node->string[i] && last_node->string[++i])
		buff[j++] = last_node->string[i];
	buff[j] = 0;
	clean_node->string = buff;
	clean_node->next = NULL;
}

int	ft_lstadd_node(t_list **lst, char *buffer)
{
	t_list	*last_node;
	t_list	*new_node;

	if (!lst || !buffer)
		return (0);
	last_node = ft_lstlast(*lst);
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (0);
	new_node->string = buffer;
	new_node->next = NULL;
	if (!*lst)
		*lst = new_node;
	else
		last_node->next = new_node;
	return (1);
}

int	found_newline(t_list *node)
{
	int		i;

	if (node == NULL)
		return (0);
	while (node)
	{
		i = 0;
		while (node->string[i])
		{
			if (node->string[i] == '\n')
				return (1);
			i++;
		}
		node = node->next;
	}
	return (0);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
