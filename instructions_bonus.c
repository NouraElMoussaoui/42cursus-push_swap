/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 08:28:26 by nel-mous          #+#    #+#             */
/*   Updated: 2023/03/16 15:56:21 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap(t_stack *top)
{
	int		temp;
	t_stack	*node1;
	t_stack	*node2;

	if (ft_lstsize(top) <= 1)
		return ;
	if (top != NULL && top->next != NULL)
	{
		node1 = top;
		node2 = top->next;
		temp = node1->content;
		node1->content = node2->content;
		node2->content = temp;
	}
}

void	rotate(t_stack *top)
{
	int		temp;
	t_stack	*node1;
	t_stack	*node2;

	if (ft_lstsize(top) <= 1)
		return ;
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

void	reverse_rotate(t_stack **top)
{
	t_stack	*lastnode;
	t_stack	*prelast;

	lastnode = *top;
	prelast = *top;
	if (ft_lstsize(*top) <= 1)
		return ;
	while (lastnode->next != NULL)
		lastnode = lastnode->next;
	while (prelast->next->next != NULL)
		prelast = prelast->next;
	prelast->next = NULL;
	lastnode->next = *top;
	*top = lastnode;
}

void	push(t_stack **a, t_stack **b)
{
	t_stack	*a_top;
	t_stack	*b_top;
	t_stack	*temp;

	a_top = *a;
	b_top = *b;
	if (ft_lstsize(*a) == 0)
		return ;
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
