/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 08:26:13 by nel-mous          #+#    #+#             */
/*   Updated: 2023/03/16 15:54:59 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "Small_libft/libft.h"

void	ss(t_stack **a, t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	check_result(t_stack **a, t_stack **b);
void	get_line(t_stack **a, t_stack **b);
void	add_to_list(char **arr, t_stack **a);
int		if_sorted(t_stack *a);
void	double_args(char **arr, char *st);
void	check_space(char *s, char *st);
void	check_args(char **arr, char *s);
void	swap(t_stack *top);
void	rotate(t_stack *top);
void	reverse_rotate(t_stack **top);
void	push(t_stack **a, t_stack **b);
void	free_all(char *s, char **arr, t_stack **a, t_stack **b);
void	free_stack(t_stack **a);
void	oops(char *s, char **arr);
#endif
