/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:04:59 by ktoivola          #+#    #+#             */
/*   Updated: 2024/03/27 16:37:50 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include "libft/includes/libft.h"

typedef struct s_stack_node
{
    int                 value;
    int                 index;
    struct s_stack_node *next;
    struct s_stack_node *prev;
}           t_stack_node;

int main(int argc, char **argv);

/* Initialise functions */
void    init_stack(t_stack_node **a, t_stack_node **b, char **argv, int argc);
void    append_node(t_stack_node **a, int n);
int     calculate_segment_size(t_stack_node **a);

/* Free memory and error handling */
void    free_list(char **ptr);
void    free_stack(t_stack_node **stack);
void    handle_error(t_stack_node **a,char **argv, int argc);

/* Push_swap sort algorithms */
int     sort_b_stack(t_stack_node **b, int val_to_push, int cmd);
void    sort_ministack_3(t_stack_node **stack);
void    sort_ministack_4(t_stack_node **a, t_stack_node **b);
void    sort_ministack_5(t_stack_node **a, t_stack_node **b);
void    push_swap(t_stack_node **a, t_stack_node **b);
void	check_dbl_rot(t_stack_node **a, t_stack_node **b, int rot_a, int val);

/* Push_swap utilities */
t_stack_node    *find_min(t_stack_node *stack, bool for_index);
t_stack_node    *find_last(t_stack_node *node);
t_stack_node    *find_max(t_stack_node *stack);
bool            is_sorted(t_stack_node *stack);
int             stack_len(t_stack_node *stack);
int	            count_cmds(t_stack_node **b, int val_to_push, int cmd);
void            do_twice(void (*f)(t_stack_node **a, int i), t_stack_node **s, int x);

/* stack commands */
void    sa(t_stack_node **a, int i);
void    sb(t_stack_node **b, int i);
void    ra(t_stack_node **a, int i);
void    rb(t_stack_node **b, int i);
void    rra(t_stack_node **a, int i);
void    rrb(t_stack_node **b, int i);
void    pa(t_stack_node **a, t_stack_node **b, int i);
void    pb(t_stack_node **b, t_stack_node **a, int i);
void    ss(t_stack_node **a, t_stack_node **b, int i);
void    rr(t_stack_node **a, t_stack_node **b, int i);
void    rrr(t_stack_node **a, t_stack_node **b, int i);

/* REMOVE before evaluation!!! just for testing */
void    print_stack(t_stack_node **stack);

#endif