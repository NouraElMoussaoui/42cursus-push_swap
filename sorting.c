/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 09:01:02 by nel-mous          #+#    #+#             */
/*   Updated: 2023/03/16 16:01:20 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	if (*a)
	{
		if ((*a)->content > (*a)->next->content)
		{
			if ((*a)->content > (*a)->next->next->content)
			{
				rotate((*a), 0);
				if ((*a)->content > (*a)->next->content)
					swap((*a), 0);
			}
			else
				swap((*a), 0);
		}
		else if ((*a)->content < (*a)->next->content)
		{
			if ((*a)->content > (*a)->next->next->content)
				reverse_rotate(a, 0);
			else
			{
				reverse_rotate(a, 0);
				swap((*a), 0);
			}
		}
	}
}

int	min_pos(t_stack **a)
{
	t_stack	*a_top;
	int		min;
	int		idx;
	int		position;

	a_top = *a;
	position = 0;
	idx = 0;
	if (a_top)
		min = a_top->content;
	while (a_top && a_top->next != NULL )
	{
		if (min > a_top->next->content)
		{
			min = a_top->next->content;
			position = idx + 1;
		}
		a_top = a_top->next;
		idx++;
	}
	return (position);
}

void	change_pos(t_stack **a)
{
	int	i;

	i = min_pos(a);
	if (i <= ft_lstsize(*a) / 2)
	{
		while (i)
		{
			rotate(*a, 0);
			i--;
		}
	}
	else
	{
		while (i != ft_lstsize(*a))
		{
			reverse_rotate(a, 0);
			i++;
		}
	}
}

void	sort_five(t_stack **a, t_stack **b)
{
	change_pos(a);
	push(a, b, 1);
	change_pos(a);
	push(a, b, 1);
	if (!if_sorted(*a))
	{
		if (ft_lstsize(*a) == 2)
			swap(*a, 0);
		else if (ft_lstsize(*a) == 3)
			sort_three(a);
		else
			sort_five(a, b);
	}
	push(b, a, 0);
	push(b, a, 0);
}
