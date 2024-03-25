/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:09:09 by ktoivola          #+#    #+#             */
/*   Updated: 2024/01/03 14:27:01 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*string;
	struct s_list	*next;
}				t_list;

char	*get_next_line(int fd);
char	*clear_list(t_list **list, t_list *new_node, char *buffer);
void	add_clean_node(t_list *last_node, t_list *clean_node, char *buff);
int		ft_lstadd_node(t_list **lst, char *buf);
int		found_newline(t_list *node);
t_list	*ft_lstlast(t_list *lst);

#endif