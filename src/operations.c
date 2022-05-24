/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:24:33 by moabid            #+#    #+#             */
/*   Updated: 2022/05/25 00:28:07 by moabid           ###   ########.fr       */
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
///////////Push///////////
void	ft_pb(t_stacks *stacks) // push to b
{
	t_stack	*buff;

	buff = stacks->a;
	stacks->a = stacks->a->next;
	buff->next = stacks->b;
	stacks->b = buff;
	write(1, "pb\n", 3);
}

void	ft_pa(t_stacks *stacks) // push to a
{
	t_stack	*buff;

	buff = stacks->b;
	stacks->b = stacks->b->next;
	buff->next = stacks->a;
	stacks->a = buff;
	write(1, "pa\n", 3);
}
///////////rotation///////////

void	ft_ra(t_stack **a, int id)
{
	t_stack *buff;

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
	t_stack *buff;

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

///////////reverse rotation///////////

void	ft_rra(t_stack **a, int id)
{
	t_stack	*buff;
	t_stack	*last;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	buff = *a;
	last = stacklast(*a);
	while(buff->next->next)
	{
		buff = buff->next;
	}
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
	while(buff->next->next)
	{
		buff = buff->next;
	}
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
