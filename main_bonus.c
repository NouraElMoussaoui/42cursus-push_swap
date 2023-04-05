/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:02:11 by nel-mous          #+#    #+#             */
/*   Updated: 2023/03/18 12:01:21 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	to_use(char **arr, t_stack **a, t_stack **b)
{
	check_args(arr);
	check_duplicate(arr);
	add_to_list(arr, a);
	free_arr(arr);
	get_line(a, b);
	check_result(a, b);
}

int	main(int ac, char **av)
{
	int		i;
	char	*s;
	char	**arr;
	t_stack	*a;
	t_stack	*b;

	i = 1;
	a = NULL;
	b = NULL;
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
