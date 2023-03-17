/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 08:35:50 by nel-mous          #+#    #+#             */
/*   Updated: 2023/03/17 09:55:39 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "Small_libft/libft.h"

typedef struct s_range
{
	int	y;
	int	x;
	int	idx_a;
	int	i;
}	t_range;

void	free_all(char *s, char **arr, t_stack **a, t_stack **b);
void	swap(t_stack *top, int var);
void	rotate(t_stack *top, int var);
void	push(t_stack **a, t_stack **b, int var);
void	reverse_rotate(t_stack **top, int var);
int		if_sorted(t_stack *a);
void	sort_three(t_stack **a);
void	sort_five(t_stack **a, t_stack **b);
void	double_args(char **arr, char *s);
void	check_space(char *av, char *s);
void	check_args(char **arr, char *s);
void	oops(char *s, char **arr);
void	list_sorted(t_stack **a_sort);
void	depend_size(t_stack **a, t_stack **b, t_stack **a_sort);
void	free_all(char *s, char **arr, t_stack **a, t_stack **b);
void	free_stack(t_stack **a);


#endif