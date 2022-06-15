/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 22:30:46 by moabid            #+#    #+#             */
/*   Updated: 2022/06/15 20:11:59 by moabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stacks.h"

///////////Push///////////
void	ft_pb(t_stacks *stacks, int id)
{
	t_stack	*buff;

	buff = stacks->a;
	stacks->a = stacks->a->next;
	buff->next = stacks->b; 
	stacks->b = buff;
	if (id == -42)
		write(1, "pb\n", 3);
}

void	ft_pa(t_stacks *stacks, int id)
{
	t_stack	*buff;

	buff = stacks->b;
	stacks->b = stacks->b->next;
	buff->next = stacks->a;
	stacks->a = buff;
	if (id == -42)
		write(1, "pa\n", 3);
}