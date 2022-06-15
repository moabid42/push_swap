/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 22:30:13 by moabid            #+#    #+#             */
/*   Updated: 2022/06/13 20:35:31 by moabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stacks.h"

///////////switch the top///////////
void	ft_sa(t_stack **a, int id)
{
	int		buff;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	buff = (*a)->value;
	(*a)->value = (*a)->next->value;
	(*a)->next->value = buff;
	if (id == -42)
		write(1, "sa\n", 3);
}

void	ft_sb(t_stack **b, int id)
{
	int		buff;

	if ((*b) == NULL || (*b)->next == NULL)
		return ;
	buff = (*b)->value;
	(*b)->value = (*b)->next->value;
	(*b)->next->value = buff;
	if (id == -42)
		write(1, "sb\n", 3);
}

void	ft_ss(t_stacks *stack)
{
	ft_sa(&stack->a, 42);
	ft_sb(&stack->b, 42);
	write(1, "ss\n", 3);
}
