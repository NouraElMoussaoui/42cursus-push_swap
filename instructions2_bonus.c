/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:44:20 by nel-mous          #+#    #+#             */
/*   Updated: 2023/03/14 17:50:48 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ss(t_stack **a, t_stack **b)
{
	swap(*a);
	swap(*b);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(*a);
	rotate(*b);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
