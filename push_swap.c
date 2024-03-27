/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:44:04 by ktoivola          #+#    #+#             */
/*   Updated: 2024/03/27 14:13:31 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void index_nodes(t_stack_node **stack, int segment_size)
{
    int             i;
    int             len;
    t_stack_node    *min_node;
    
    if (*stack == NULL)
        return ;
    i = 0;
    len = stack_len(*stack);
    while (i < segment_size)
    {
        min_node = find_min(*stack, true);
        min_node->index = i;
        i++;
    }   
}

int get_cost(t_stack_node **stack, int hold_1, int hold_2)
{
    int i;
    int j;
    t_stack_node *temp;

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

int calculate_position(t_stack_node **stack, t_stack_node *node_to_find)
{
    int i;
    t_stack_node *temp;

    i = 1;
    temp = *stack;
    while (temp)
    {
        if (temp == node_to_find)
            return (i);
        i++;
        temp = temp->next;
    }
    return (i);
}

int    sort_b_stack(t_stack_node **b, int val_to_push, char *cmd)
{
    t_stack_node    *temp;
    int             rot;
    
    temp = *b;
    while (temp->next)
    {
        if (val_to_push > find_max(*b)->value 
        || val_to_push < find_min(*b, 0)->value)
        {
            temp = find_max(*b); //get biggest on top if node to push is biggest
            break ;
        }
        if (val_to_push > temp->value && val_to_push < (find_last(*b))->value)
            break ;
        temp = temp->next;
        if (val_to_push > temp->value && val_to_push < temp->prev->value)
            break ;
    }
    if (calculate_position(b, temp) < (stack_len(*b) / 2)) //calculate distance of temp from top
    {
        if (cmd == "rr")
            rot = count_cmds(b, val_to_push, cmd);
        else
        {
            while (*b != temp)
               rrb(b, 0); 
        }
        return (rot);
    }
    if (cmd == "r")
        rot = count_cmds(b, val_to_push, cmd);
    while (*b!= temp)
        rb(b, 0); //add option to rotate stack a too
    return (rot);
}

void    push_closest_to_top(t_stack_node **a, t_stack_node **b, int nodes_on_hold[2])
{
    int i;

    i = 0;
    if (!*a)
        return ;
    if (get_cost(a, nodes_on_hold[0], nodes_on_hold[1]) <= 0) //calculate cost returns i - j, hold 1 cost - hold 2 cost
    {
        while ((*a)->value != nodes_on_hold[0])
        {
            *a = (*a)->next;
            i++;
        }
        check_dbl_rot(a, b, i, nodes_on_hold[0]);
        //
        if (stack_len(*b) > 1)
            sort_b_stack(b, *a);
        //
        pb(b, a, 0);
    }
    else 
    {
        while ((*a)->value != nodes_on_hold[1])
            i++;
        check_dbl_rot(a, b, i * -1, nodes_on_hold[0]);  
        //
        if (stack_len(*b) > 1)
            sort_b_stack(b, *a);
        //
        pb(b, a, 0);
    }
}

void    find_nodes_to_hold(t_stack_node **a, int segment_size, int hold_node[2])
{
    t_stack_node *temp;

    temp = *a;
    hold_node[0] = INT_MIN;
    hold_node[1] = INT_MIN;
    while (temp) //loops through the whole stack looking for indexes under segment size
    {   
        if (temp->index < segment_size && temp->index >= 0)
        {
            hold_node[0] = temp->value;
            break ;
        }
        temp = temp->next;
    }
    temp = find_last(*a);
    while (temp && temp != *a)
    {
        if (temp->index < segment_size && temp->index >= 0)
        {
            hold_node[1] = temp->value;
            break ;
        }
        temp = temp->prev;
    }
}

void    push_swap(t_stack_node **a, t_stack_node **b)
{
    int             i;
    int             hold_node[2];
    int             segment_size;
    t_stack_node    *temp;

    temp = *a;
    segment_size = stack_len(*a)/calculate_segment_size(a);
    while (*a) //loops until everything is pushed from stack A
    {
        i = 0;
        index_nodes(a, segment_size);
        while (i++ < segment_size)
        {
            printf("A ");
            print_stack(a);
            printf("B ");
            print_stack(b);
            printf("commands:\n");
            find_nodes_to_hold(a, segment_size, hold_node);
            // printf("nodes to hold: %d & %d\n", hold_node[0], hold_node[1]);
            push_closest_to_top(a, b, hold_node);
            // printf("-------------\n");
        } // check here if rotating b at the same time makes sense save the rrb or rb "debt"
    }
    if (get_cost(b, find_max(*b)->value, find_max(*b)->value) <= 0)
    {
        while (find_max(*b) != *b)
            rb(b, 0);
    }
    while (find_max(*b) != *b)
            rrb(b, 0);
}
