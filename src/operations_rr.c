/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 22:31:39 by moabid            #+#    #+#             */
/*   Updated: 2022/06/16 01:07:32 by moabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stacks.h"

///////////reverse rotation///////////
void	ft_rra(t_stack **a, int id)
{
	t_stack	*buff;
	t_stack	*last;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	buff = *a;
	last = stacklast(*a);
	while (buff->next->next)
		buff = buff->next;
	buff->next = NULL;
	ft_insert_front(a, last);
	if (id == -42)
		write(1, "rra\n", 4);
}

void	ft_rrb(t_stack **b, int id)
{
	t_stack	*buff;
	t_stack	*last;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	buff = *b;
	last = stacklast(*b);
	while (buff->next->next)
		buff = buff->next;
	buff->next = NULL;
	ft_insert_front(b, last);
	if (id == -42)
		write(1, "rrb\n", 4);
}

void	ft_rrr(t_stacks *stack)
{
	ft_rra(&stack->a, 42);
	ft_rrb(&stack->b, 42);
	write(1, "rrr\n", 3);
}
