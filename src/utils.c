/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:32:53 by moabid            #+#    #+#             */
/*   Updated: 2022/06/17 19:31:11 by moabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stacks.h"

int	ft_isnumber(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	swap(int *a, int *b)
{
	int	t;

	t = *a;
	*a = *b;
	*b = t;
}

int	average(int num, int *tab)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	while (i < num)
	{
		sum += tab[i];
		i++;
	}
	return (sum / num);
}

void	free_str(char **strs)
{
	int	i;

	i = 0;
	while(strs[i] != '\0')
	{
		free(strs[i]);
		i++;
	}
	strs = NULL;
}

void	ft_free_data(t_data **data)
{
	free(&(*data)->tab);
	*data = NULL;
}

void	ft_free_stacks(t_stacks **stacks)
{
	ft_freeme(&(*stacks)->a);
	ft_freeme(&(*stacks)->b);
	*stacks = NULL;
}