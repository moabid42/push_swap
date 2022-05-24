/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:42:00 by moabid            #+#    #+#             */
/*   Updated: 2022/05/23 22:18:05 by moabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stacks.h"

void	ft_init_stacks(t_data *data, t_stacks *stacks)
{
	stacks->a = ft_create_stack(data->indexarr, data->argc);
	stacks->b = NULL;
	stacks->a_count = data->argc;
	stacks->b_count = 0;
}

t_stack	*ft_create_stack(int *indexarr, int count)
{
	int		i;
	t_stack	*new_node;
	t_stack	*curr;

	i = 0;
	new_node = (t_stack *)ft_malloc(sizeof(t_stack));
	curr = new_node;
	while (i < count)
	{
		if (i < count - 1)
			new_node->next = (t_stack *)ft_malloc(sizeof(t_stack)); 
		new_node->value = indexarr[i];
		if (i == (count - 1))
			new_node->next = NULL;
		else
			new_node = new_node->next;
		i++;
	}
	return (curr);
}

int parsing(t_data *data, char **argv, int argc)
{
	int		i;
	int 	*tab;
	
	i = 1;
	tab = (int *)ft_malloc(sizeof(int) * (argc - 1));
	while(i < argc)
	{
		tab[i - 1] = ft_atoi(argv[i]);
		// printf("The number[%d] = %d\n", i,tab[i - 1]);
		if (tab[i - 1] <= 0 && tab[i - 1] <= 9)
			return (FALSE);
		i++;
	}
	data->argc = argc - 1;
	data->tab = tab;
	data->min = 0;
	data->max = data->argc / 2;
	data->indexarr = copyArray(tab, data->argc);
	return (TRUE);
}