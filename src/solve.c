/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 22:40:50 by moabid            #+#    #+#             */
/*   Updated: 2022/07/23 01:15:02 by moabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stacks.h"

void	ft_sa_ra(t_stacks *head)
{
	ft_sa(&head->a, -42);
	ft_ra(&head->a, -42);
}

void	sorting_3value(t_stacks *head)
{
	t_stack	*tmp;

	tmp = head->a;
	if (ft_is_sorted(head->a) == TRUE)
		return ;
	if (tmp->value > tmp->next->value
		&& tmp->value < tmp->next->next->value)
		ft_sa(&head->a, -42);
	else if (tmp->value > tmp->next->value
		&& tmp->next->value > tmp->next->next->value)
	{
		ft_sa(&head->a, -42);
		ft_rra(&head->a, -42);
	}
	else if (tmp->value > tmp->next->value
		&& tmp->value > tmp->next->next->value)
		ft_ra(&head->a, -42);
	else if (tmp->value < tmp->next->value
		&& tmp->value < tmp->next->next->value)
		ft_sa_ra(head);
	else if (tmp->value < tmp->next->value
		&& tmp->value > tmp->next->next->value)
		ft_rra(&head->a, -42);
}

void	sorting_5value(t_stacks *head)
{
	int	len_b;
	int	i;

	len_b = 0;
	i = 0;
	if (ft_is_sorted(head->a) == TRUE)
		return ;
	while (len_b < 2)
	{
		if (i < 2)
		{
			ft_pb(head, -42);
			i++;
			len_b++;
		}
		else
			ft_ra(&head->a, -42);
	}
	if (ft_is_sorted(head->a) == FALSE)
		sorting_3value(head);
	if (head->b->value < head->b->next->value)
		ft_sb(&head->b, -42);
	ft_pa(head, -42);
	ft_pa(head, -42);
}

void	solve(t_stacks *stacks, t_data *data)
{
	if (!stacks->a && ft_is_sorted(stacks->a))
		return ;
	if (data->argc == 3)
		sorting_3value(stacks);
	else if (data->argc == 5)
		sorting_5value(stacks);
	else
	{
		ft_shanking(stacks, 42, 0);
		ft_unshanking(stacks);
	}
	ft_free_stacks(stacks);
}
