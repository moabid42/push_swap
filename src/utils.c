/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:32:53 by moabid            #+#    #+#             */
/*   Updated: 2022/06/16 01:21:26 by moabid           ###   ########.fr       */
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

int	*copy_array(int *arr, int size)
{
	int	i;
	int	*copy;

	i = 0;
	copy = ft_malloc(sizeof(int) * size);
	while (i < size)
	{
		copy[i] = arr[i];
		i++;
	}
	return (copy);
}

void	index_array(int *tab, int *indexarr, int num)
{
	int	i;
	int	j;

	i = 0;
	while (i < num)
	{
		j = 0;
		quick_sort(tab, 0, num - 1);
		while (j < num)
		{
			if (indexarr[i] == tab[j])
				indexarr[i] = j;
			j++;
		}
		i++;
	}
}
