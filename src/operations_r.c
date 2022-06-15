/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_r.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 22:31:12 by moabid            #+#    #+#             */
/*   Updated: 2022/06/16 01:06:57 by moabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stacks.h"

///////////rotation///////////

void	ft_ra(t_stack **a, int id)
{
	t_stack	*buff;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	buff = *a;
	*a = (*a)->next;
	buff->next = NULL;
	ft_insert_back(a, buff);
	if (id == -42)
		write(1, "ra\n", 3);
}

void	ft_rb(t_stack **b, int id)
{
	t_stack	*buff;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	buff = *b;
	*b = (*b)->next;
	buff->next = NULL;
	ft_insert_back(b, buff);
	if (id == -42)
		write(1, "rb\n", 3);
}

void	ft_rr(t_stacks *stack)
{
	ft_ra(&stack->a, 42);
	ft_rb(&stack->b, 42);
	write(1, "rr\n", 3);
}
