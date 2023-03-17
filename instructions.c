/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 09:11:06 by nel-mous          #+#    #+#             */
/*   Updated: 2023/03/13 11:30:46 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *top, int var)
{
	int		temp;
	t_stack	*node1;
	t_stack	*node2;

	if (ft_lstsize(top) <= 1)
		return ;
	if (var == 0)
		ft_putstr("sa\n");
	else if (var == 1)
		ft_putstr("sb\n");
	else if (var == 2)
		ft_putstr("");
	if (top != NULL && top->next != NULL)
	{
		node1 = top;
		node2 = top->next;
		temp = node1->content;
		node1->content = node2->content;
		node2->content = temp;
	}
}

void	rotate(t_stack *top, int var)
{
	int		temp;
	t_stack	*node1;
	t_stack	*node2;

	if (ft_lstsize(top) <= 1)
		return ;
	if (var == 0)
		ft_putstr("ra\n");
	else if (var == 1)
		ft_putstr("rb\n");
	else if (var == 2)
		ft_putstr("");
	while (top && top->next != NULL)
	{
		node1 = top;
		node2 = top->next;
		temp = node1->content;
		node1->content = node2->content;
		node2->content = temp;
		top = top->next;
	}
}

void	reverse_rotate(t_stack **top, int var)
{
	t_stack	*lastnode;
	t_stack	*prelast;

	lastnode = *top;
	prelast = *top;
	if (ft_lstsize(*top) <= 1)
		return ;
	if (var == 0)
		ft_putstr("rra\n");
	else if (var == 1)
		ft_putstr("rrb\n");
	else if (var == 2)
		ft_putstr("");
	while (lastnode->next != NULL)
		lastnode = lastnode->next;
	while (prelast->next->next != NULL)
		prelast = prelast->next;
	prelast->next = NULL;
	lastnode->next = *top;
	*top = lastnode;
}

void	push(t_stack **a, t_stack **b, int var)
{
	t_stack	*a_top;
	t_stack	*b_top;
	t_stack	*temp;

	a_top = *a;
	b_top = *b;
	if (ft_lstsize(*a) == 0)
		return ;
	if (var == 0)
		ft_putstr("pa\n");
	else if (var == 1)
		ft_putstr("pb\n");
	if (*a)
	{
		temp = b_top;
		b_top = a_top;
		a_top = a_top->next;
		b_top->next = temp;
		*a = a_top;
		*b = b_top;
	}
}
