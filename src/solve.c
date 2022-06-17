/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 22:40:50 by moabid            #+#    #+#             */
/*   Updated: 2022/06/17 19:46:49 by moabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stacks.h"

void	solve(t_stacks *stacks)
{
	if (!stacks->a && ft_is_sorted(stacks->a))
		return ;
	ft_shanking(stacks, 42, 0);
	ft_unshanking(stacks);
	ft_free_stacks(&stacks);
}
