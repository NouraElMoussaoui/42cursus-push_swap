/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 10:27:32 by nel-mous          #+#    #+#             */
/*   Updated: 2023/03/19 08:36:16 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_to_list(char **arr, t_stack **a, t_stack **a_sort)
{
	int	j;

	j = 0;
	while (arr[j])
	{
		ft_lstadd_back(a, ft_lstnew(ft_atoi(arr[j])));
		ft_lstadd_back(a_sort, ft_lstnew(ft_atoi(arr[j])));
		j++;
	}
}

void	select_sort(t_stack **a, t_stack **b, t_stack **a_sort)
{
	if (*a)
	{
		if (if_sorted(*a))
			return ;
		if (ft_lstsize(*a) == 2)
			swap(*a, 0);
		if (ft_lstsize(*a) == 3)
			sort_three(a);
		if (ft_lstsize(*a) == 4 || ft_lstsize(*a) == 5)
			sort_five(a, b);
		if (ft_lstsize(*a) > 5)
			depend_size(a, b, a_sort);
	}
}

void	list_sorted(t_stack **a_sort)
{
	int		swap;
	t_stack	*t_sort;
	t_stack	*t_next;

	t_sort = *a_sort;
	while (t_sort)
	{
		t_next = t_sort->next;
		while (t_next)
		{
			if (t_sort->content > t_next->content)
			{
				swap = (t_sort)->content;
				(t_sort)->content = t_next->content;
				t_next->content = swap;
			}
			t_next = t_next->next;
		}
		t_sort = t_sort->next;
	}
	t_sort = *a_sort;
}

void	to_use(char **arr, t_stack **a, t_stack **b)
{
	t_stack	*a_sort;

	a_sort = NULL;
	check_args(arr);
	check_duplicate(arr);
	add_to_list(arr, a, &a_sort);
	free_arr(arr);
	list_sorted(&a_sort);
	select_sort(a, b, &a_sort);
	free_stack(&a_sort);
}

int	main(int ac, char **av)
{
	int		i;
	char	*s;
	char	**arr;
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	i = 1;
	s = NULL;
	if (ac > 1)
	{
		while (av[i])
		{
			check_space(av[i], s);
			s = ft_strjoin(s, av[i]);
			s = ft_strjoin(s, " ");
			i++;
		}
		arr = ft_split(s, ' ');
		free(s);
		to_use(arr, &a, &b);
		free_stack(&a);
		free_stack(&b);
	}
}
