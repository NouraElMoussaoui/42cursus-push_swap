/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:20:41 by nel-mous          #+#    #+#             */
/*   Updated: 2023/03/18 12:01:15 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	if_error(t_stack **a, t_stack **b, char *line)
{
	free_stack(a);
	free_stack(b);
	oops(line, NULL);
}

void	add_to_list(char **arr, t_stack **a)
{
	int	j;

	j = 0;
	while (arr[j])
	{
		ft_lstadd_back(a, ft_lstnew(ft_atoi(arr[j])));
		j++;
	}
}

void	check_result(t_stack **a, t_stack **b)
{
	if (if_sorted(*a) && !(*b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void	make_action(t_stack **a, t_stack **b, char *line)
{
	if (ft_strcmp(line, "sa\n") == 0)
		swap(*a);
	else if (ft_strcmp(line, "sb\n") == 0)
		swap(*b);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss(a, b);
	else if (ft_strcmp(line, "ra\n") == 0)
		rotate(*a);
	else if (ft_strcmp(line, "rb\n") == 0)
		rotate(*b);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr(a, b);
	else if (ft_strcmp(line, "rra\n") == 0)
		reverse_rotate(a);
	else if (ft_strcmp(line, "rrb\n") == 0)
		reverse_rotate(b);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr(a, b);
	else if (ft_strcmp(line, "pa\n") == 0)
		push(b, a);
	else if (ft_strcmp(line, "pb\n") == 0)
		push(a, b);
	else
		if_error(a, b, line);
}

void	get_line(t_stack **a, t_stack **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		make_action(a, b, line);
		free(line);
		line = get_next_line(0);
	}
}
