/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 10:17:52 by ktoivola          #+#    #+#             */
/*   Updated: 2024/04/09 14:21:39 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include "../libft/includes/libft.h"

# define R		1
# define RR		0
# define EOR	2

typedef struct s_stack_node
{
	int					value;
	int					index;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}				t_stk_node;

/* Init functions */
void		init_stack(t_stk_node **a, char **argv, int argc);
int			append_node(t_stk_node **a, int n);
int			calculate_segment_size(t_stk_node **a);

/* Free memory and error handling */
void		free_list(char **ptr);
void		free_stack(t_stk_node **stack);
void		handle_error(t_stk_node **a, char **argv, int argc);

/* Sort algorithms */
void		final_sort_b_stack(t_stk_node **b);
void		sort_ministack_3(t_stk_node **stack);
void		sort_ministack_4(t_stk_node **a, t_stk_node **b);
void		sort_ministack_5(t_stk_node **a, t_stk_node **b);
int			sort_b_stack(t_stk_node **b, int val_to_push, int cmd);
void		push_swap(t_stk_node **a, t_stk_node **b, int segment_size);
void		check_dbl_rot(t_stk_node **a, t_stk_node **b, int rot_a, int val);

/* Stack utilities */
t_stk_node	*find_min(t_stk_node *stack, bool for_index);
t_stk_node	*find_last(t_stk_node *node);
t_stk_node	*find_max(t_stk_node *stack);
int			stack_len(t_stk_node *stack);

/* Push_swap utilities */
bool		is_sorted(t_stk_node *stack);
int			count_cmds(t_stk_node **b, int val_to_push, int cmd);
int			compare_cost(t_stk_node **stack, int hold_1, int hold_2);
int			calculate_cost_to_top(t_stk_node *stack, t_stk_node *node);
int			calculate_cmd(t_stk_node **stack, t_stk_node *node_to_find);
void		do_twice(void (*f)(t_stk_node **a), t_stk_node **s);

/* stack commands */
void		sa(t_stk_node **a);
void		sb(t_stk_node **b);
void		ra(t_stk_node **a);
void		rb(t_stk_node **b);
void		rra(t_stk_node **a);
void		rrb(t_stk_node **b);
void		pa(t_stk_node **a, t_stk_node **b);
void		pb(t_stk_node **b, t_stk_node **a);
void		ss(t_stk_node **a, t_stk_node **b);
void		rr(t_stk_node **a, t_stk_node **b);
void		rrr(t_stk_node **a, t_stk_node **b);

#endif