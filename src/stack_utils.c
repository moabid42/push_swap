/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 00:28:38 by moabid            #+#    #+#             */
/*   Updated: 2022/06/16 00:28:57 by moabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stacks.h"

t_stack	*stacklast(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst != NULL)
	{
		if (lst -> next == 0)
			return (lst);
		lst = lst -> next;
	}
	return (NULL);
}

void	ft_insert_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = stacklast(*lst);
	last->next = new;
}

void	ft_insert_front(t_stack **lst, t_stack *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new -> next = *lst;
	*lst = new;
}
