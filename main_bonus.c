/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:02:11 by nel-mous          #+#    #+#             */
/*   Updated: 2023/03/17 09:52:36 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	to_use(char **arr, t_stack **a, t_stack **b, char *s)
{
	check_args(arr, s);
	double_args(arr, s);
	add_to_list(arr, a);
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

	a = NULL;
	b = NULL;
	i = 1;
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
		to_use(arr, &a, &b, s);
		free_all(s, arr, &a, &b);
	}
}
