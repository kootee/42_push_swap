/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:44:04 by ktoivola          #+#    #+#             */
/*   Updated: 2024/03/28 14:40:21 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void index_nodes(t_stk_node **stack, int segment_size)
{
    int             i;
    int             len;
    t_stk_node    *min_node;
    
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

int compare_cost(t_stk_node **stack, int hold_1, int hold_2)
{
    int i;
    int j;
    t_stk_node *temp;

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

int    sort_b_stack(t_stk_node **b, int to_top, int a_cmd)
{
    t_stk_node  *temp;
    int         rot_b;
    int         b_cmd;
    
    temp = *b;
    if (stack_len(*b) < 2)
        return (0);
    if (to_top > find_max(*b)->value || to_top < find_min(*b, 0)->value)
            temp = find_max(*b);
    else
    {
        while (temp->next)
        {
            if (to_top > temp->value && to_top < (find_last(*b))->value)
                break ;
            temp = temp->next;
            if (to_top > temp->value && to_top < temp->prev->value)
                break ;
        }
    }
    
    // TESTING
    if (a_cmd == 1)
        printf("is R\n");
    else if (a_cmd == 0)
        printf("is RR\n");    
    printf("stack len / 2 is %d\n", (stack_len(*b) / 2));
    // TESTING
    
    rot_b = 0;
    b_cmd = calculate_cmd(b, temp);
    if (b_cmd == EOR)
        rot_b = count_cmds(b, temp->value, a_cmd);
    else if (b_cmd == R) // checks if I want to 
    {
        if (a_cmd == R)
            rot_b = count_cmds(b, temp->value, R);
        else
        {
            while (*b!= temp)
                rb(b, 0);
        }
        return (rot_b);
    }
    else if (b_cmd == RR)
    {
        if (a_cmd == RR)
            rot_b = count_cmds(b, temp->value, RR);
        else
        {
            while (*b != temp)
                rrb(b, 0); 
        }
    }
    return (rot_b);
}

void    push_closest_to_top(t_stk_node **a, t_stk_node **b, int nodes_on_hold[2])
{
    int rot;
    t_stk_node *temp;

    rot = 0;
    temp = *a;
    if (!*a)
        return ;
    if (compare_cost(a, nodes_on_hold[0], nodes_on_hold[1]) <= 0)
    {
        while (temp->value != nodes_on_hold[0] && rot++)
            temp = temp->next;
        check_dbl_rot(a, b, rot, nodes_on_hold[0]);
    }
    else 
    {
        temp = find_last(*a);
        while (++rot && temp->value != nodes_on_hold[1])
            temp = temp->prev;
        check_dbl_rot(a, b, rot * -1, nodes_on_hold[1]);
    }
}

void    find_nodes_to_hold(t_stk_node **a, int segment_size, int hold_node[2])
{
    t_stk_node *temp;

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

void    push_swap(t_stk_node **a, t_stk_node **b)
{
    int             i;
    int             hold_node[2];
    int             segment_size;
    t_stk_node    *temp;

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
            find_nodes_to_hold(a, segment_size, hold_node);
            printf("nodes to hold: %d & %d\n", hold_node[0], hold_node[1]);
            printf("commands:\n");
            push_closest_to_top(a, b, hold_node);
            // printf("-------------\n");
        } // check here if rotating b at the same time makes sense save the rrb or rb "debt"
    }
    if (compare_cost(b, find_max(*b)->value, find_max(*b)->value) <= 0)
    {
        while (find_max(*b) != *b)
            rb(b, 0);
    }
    while (find_max(*b) != *b)
            rrb(b, 0);
    while (b)
        pa(a, b, 0);
}
