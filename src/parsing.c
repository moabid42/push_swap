/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:42:00 by moabid            #+#    #+#             */
/*   Updated: 2022/05/14 13:28:41 by moabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stacks.h"

// t_stack	*new_node(char *argv)
// {
// 	t_stack *curr_a;
	
// 	curr_a = (t_stack *)ft_malloc(sizeof(t_stack));
// 	curr_a->value = ft_atoi(argv);
// 	curr_a->next = NULL;
// 	return (curr_a);
// }

void	ft_init_stacks(t_data *data, t_stacks *stacks)
{
	stacks->a = ft_create_stack(data->tab, data->argc);
	stacks->b = NULL;
}

t_stack	*ft_create_stack(int *tab, int count)
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
		new_node->value = tab[i];
		if (i == (count - 1))
			new_node->next = NULL;
		else
			new_node = new_node->next;
		i++;
	}
	return (curr);
}

int *parsing(t_data *data, char **argv, int argc)
{
	int		i;
	int 	*tab;
	
	i = 1;
	tab = (int *)ft_malloc(sizeof(int) * (argc - 1));
	while(i < argc)
	{
		tab[i - 1] = ft_atoi(argv[i]);
		// if (!(tab[i - 1] >= 0 && tab[i - 1] <= 9))
		// 	return (FALSE);
		i++;
	}
	// data->aveg = average(argc - 1, tab);
	return (tab);
}