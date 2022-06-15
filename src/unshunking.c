/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unshunking.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 22:43:32 by moabid            #+#    #+#             */
/*   Updated: 2022/06/16 01:32:27 by moabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stacks.h"

int	ft_greater_pivot_checker(t_stack *a, int pivot)
{
	int		shunk;
	t_stack	*tmp;

	shunk = a->shunk;
	tmp = a;
	while (tmp && tmp->shunk == shunk)
	{
		if (tmp->value > pivot)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	ft_b_divide(t_stacks *stacks)
{
	int	pivot;
	int	rb_nbr;

	rb_nbr = 0;
	pivot = 0;
	pivot = ft_get_midlle(stacks->b, stacks->b->shunk);
	while (ft_greater_pivot_checker(stacks->b, pivot))
	{
		if (stacks->b->value > pivot)
		{
			ft_pa(stacks, -42);
			stacks->a->shunk++;
			stacks->a->shunk++;
		}
		else
		{
			ft_rb(&stacks->b, -42);
			rb_nbr++;
		}
	}
	while (rb_nbr--)
		ft_rrb(&stacks->b, -42);
	ft_shanking(stacks, 0, 0);
}

void	ft_unshanking(t_stacks *stacks)
{
	while (stacks->b)
	{
		if (ft_nbr_shunk(stacks->b, stacks->b->shunk) == 1)
			ft_pa(stacks, -42);
		else if (ft_nbr_shunk(stacks->b, stacks->b->shunk) == 2)
		{
			if (stacks->b->value <= stacks->b->next->value)
				ft_sb(&stacks->b, -42);
			ft_pa(stacks, -42);
			ft_pa(stacks, -42);
		}
		else
			ft_b_divide(stacks);
	}
}
