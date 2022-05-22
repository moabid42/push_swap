/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 19:22:53 by moabid            #+#    #+#             */
/*   Updated: 2022/05/22 20:56:25 by moabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stacks.h"


void	solve(t_data *data, t_stacks *stacks)
{
	if (data->argc > 10)
	{
		partitioning(10, data, stacks);
		sortSmall(stacks, data);
		sortPartitings(data->argc - 10, stacks, data);
	}
	else
		sortSmall(data->argc - 1, stacks, data);
}


void	partitioning(int max_partition, t_data *data, t_stacks *stacks)
{
	t_stack	*tmp;

	tmp = stacks->b;
	if (max_partition >= data->argc - 10)
		return ;
	while (tmp->next)
	{
		if (tmp->value < max_partition)
			ft_pb(stacks);
		else
			ft_ra(&stacks->a, -42);
		tmp = tmp->next;
	}
	partitioning(max + 10, data, stacks)
}

void	fsortSmall(int top, t_stacks *stacks, t_data *data)
{
	while (top)
	{
		if (stacks->a->value == top)
		{
			ft_pb(stacks);
			top--;
		}
		else
			ft_ra(&stacks->a, -42);
	}
}

void	sortOne(int top, t_stacks *stacks, t_data *data)
{
	while (top)
	{
		if (stacks->a->value == top)
		{
			ft_pb(stacks);
			while(top)
			top--;
		}
		else
			ft_ra(&stacks->a, -42);
	}
}

void	sortPartitings(int max_partition, t_stacks *stacks, t_data *data)
{
	if (max_partition <= 10)
		return ;
	while ()
		sortOne(max_partition, stacks, data);
	sortPartitings(max_partition - 10, stacks, data);
}