/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:42:00 by moabid            #+#    #+#             */
/*   Updated: 2022/06/15 19:10:30 by moabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stacks.h"

void	ft_init_stacks(t_data *data, t_stacks *stacks)
{
	stacks->a = ft_create_stack(data->indexarr , data->argc);
	stacks->b = NULL;
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

int parsing1(t_data *data, char **argv, int argc)
{
	int		i;
	int 	*tab;
	
	i = 1;
	ft_check_replication(argv);
	tab = (int *)ft_malloc(sizeof(int) * (argc - 1));
	while(i < argc)
	{
		if (ft_IsNumber(argv[i]) == FALSE)
			return (FALSE);
		tab[i - 1] = ft_atoi(argv[i]);
		if (tab[i - 1] == 0 && ft_strlen(argv[i]) != 1)
			return (FALSE);
		i++;
	}
	data->argc = argc - 1;
	data->tab = tab;
	data->indexarr = copyArray(tab, data->argc);
	return (TRUE);
}

int parsing2(t_data *data, char **argv, int argc)
{
	int		i;
	int 	*tab;
	
	i = 0;
	ft_check_replication(argv);
	tab = (int *)ft_malloc(sizeof(int) * argc);
	while(i < argc)
	{
		if (ft_IsNumber(argv[i]) == FALSE)
			return (FALSE);
		tab[i] = ft_atoi(argv[i]);
		if (tab[i] == 0 && ft_strlen(argv[i]) != 1)
			return (FALSE);
		i++;
	}
	data->argc = argc;
	data->tab = tab;
	data->indexarr = copyArray(tab, data->argc);
	return (TRUE);
}