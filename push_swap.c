/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 09:49:44 by nel-mous          #+#    #+#             */
/*   Updated: 2023/03/16 16:02:34 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_pos(t_stack **a)
{
	t_stack	*a_top;
	int		max;
	int		idx;
	int		position;

	a_top = *a;
	position = 0;
	idx = 0;
	if (a_top)
		max = a_top->content;
	while (a_top && a_top->next != NULL )
	{
		if (max < a_top->next->content)
		{
			max = a_top->next->content;
			position = idx + 1;
		}
		a_top = a_top->next;
		idx++;
	}
	return (position);
}

void	change_position(t_stack **b)
{
	int	i;

	i = max_pos(b);
	if (i <= ft_lstsize(*b) / 2)
	{
		while (i)
		{
			rotate(*b, 1);
			i--;
		}
	}
	else
	{
		while (i != ft_lstsize(*b))
		{
			reverse_rotate(b, 1);
			i++;
		}
	}
}

int	find_index(int top, t_stack *a_sort)
{
	int		idx;
	t_stack	*t_sort;

	idx = 0;
	t_sort = a_sort;
	while (t_sort)
	{
		if (top == t_sort->content)
			return (idx);
		idx++;
		t_sort = (t_sort)->next;
	}
	return (-1);
}

void	final_step(t_stack **a, t_stack **b)
{
	while (*b)
	{
		change_position(b);
		push(b, a, 0);
	}
}

void	depend_size(t_stack **a, t_stack **b, t_stack **a_sort)
{
	t_range	range;

	range.x = ft_lstsize(*a);
	range.y = 0.04 * (range.x) + 12;
	range.i = 0;
	while (*a)
	{
		range.idx_a = find_index((*a)->content, *a_sort);
		if (range.idx_a > range.i && range.idx_a <= range.i + range.y)
		{
			push(a, b, 1);
			range.i++;
		}
		else if (range.idx_a > range.i + range.y)
			rotate(*a, 0);
		else if (range.idx_a <= range.i)
		{
			push(a, b, 1);
			rotate(*b, 1);
			range.i++;
		}
	}
	final_step(a, b);
}
