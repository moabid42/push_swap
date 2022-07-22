/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 20:43:53 by moabid            #+#    #+#             */
/*   Updated: 2022/07/22 19:36:50 by moabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stacks.h"

void	ft_free_data(t_data *data)
{
	free(data->tab);
	free(data);
	data = NULL;
}

void	ft_free_stacks(t_stacks *stacks)
{
	ft_freeme(&(stacks)->a);
	ft_freeme(&(stacks)->b);
	stacks = NULL;
}

void	free_str(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	strs = NULL;
}

void	ft_destroy_utils(t_stacks *stacks, char *str, char **strs)
{
	free(str);
	free_str(strs);
	ft_free_stacks(stacks);
	free(stacks);
}

void	ft_freeme(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = *stack;
	while (tmp)
	{
		tmp2 = tmp->next;
		if (tmp != NULL)
		{
			free(tmp);
			tmp = tmp2;
		}
	}
	*stack = NULL;
}
