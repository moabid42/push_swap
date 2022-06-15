/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shunking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 22:41:51 by moabid            #+#    #+#             */
/*   Updated: 2022/06/16 01:33:29 by moabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stacks.h"

int	ft_less_pivot_checker(t_stack *a, int pivot)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp)
	{
		if (tmp->value < pivot)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	ft_pushme_if_less(t_stacks *stacks, int pivot, int shunk)
{
	if (stacks->a->value < pivot)
	{
		ft_pb(stacks, -42);
		stacks->b->shunk = shunk;
		return (TRUE);
	}
	return (FALSE);
}

void	ft_shanking(t_stacks *stacks, int start, int nbr_ra)
{
	int	pivot;
	int	shunk;

	shunk = stacks->a->shunk;
	while (!ft_is_sorted(stacks->a)
		&& ft_nbr_shunk(stacks->a, stacks->a->shunk) > 2)
	{
		shunk++;
		nbr_ra = 0;
		pivot = ft_get_midlle(stacks->a, stacks->a->shunk);
		while (ft_less_pivot_checker(stacks->a, pivot) == TRUE)
		{
			if (ft_pushme_if_less(stacks, pivot, shunk) == FALSE)
			{
				ft_ra(&stacks->a, -42);
				nbr_ra++;
			}
		}
		while (!start && nbr_ra--)
			ft_rra(&stacks->a, -42);
	}
	if (ft_is_sorted(stacks->a) == FALSE)
		ft_sa(&stacks->a, -42);
}
