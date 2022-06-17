/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:42:00 by moabid            #+#    #+#             */
/*   Updated: 2022/06/17 23:32:33 by moabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stacks.h"

void	ft_init_stacks(t_data *data, t_stacks *stacks)
{
	stacks->a = ft_create_stack(data->tab, data->argc);
	stacks->b = NULL;
	ft_free_data(data);
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

char	*parseme(char **argv, int argc)
{
	int		i;
	char	*str;
	char	*tmp;

	i = 1;
	str = ft_strdup(" ");
	while (i < argc)
	{
		if (ft_atoi(argv[i]) == 0 && ft_strlen(argv[i]) != 1)
			ft_error(str);
		tmp = ft_strjoin(str, argv[i]);
		free(str);
		str = ft_strjoin(tmp, " ");
		free(tmp);
		i++;
	}
	return (str);
}

void	check_error(char **argv, int argc)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (ft_atoi(argv[i]) == 0 && ft_strlen(argv[i]) != 1)
			ft_error(NULL);
		i++;
	}
}

int	parsing2(t_data *data, char **argv, int argc)
{
	int		i;
	int		*tab;

	i = 0;
	ft_check_replication(argv);
	tab = (int *)ft_malloc(sizeof(int) * argc);
	while (i < argc)
	{
		if (ft_isnumber(argv[i]) == FALSE)
			return (FALSE);
		tab[i] = ft_atoi(argv[i]);
		if (((tab[i] == 0) && (ft_strlen(argv[i]) != 1))
			|| (ft_strlen(argv[i]) > 11))
			return (FALSE);
		i++;
	}
	data->argc = argc;
	data->tab = tab;
	return (TRUE);
}
