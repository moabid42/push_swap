/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 00:15:46 by moabid            #+#    #+#             */
/*   Updated: 2022/06/16 01:12:32 by moabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stacks.h"

void	quick_sort(int *tab, int low, int high)
{
	int	pivo;

	if (low < high)
	{
		pivo = partition(tab, low, high);
		quick_sort(tab, low, pivo - 1);
		quick_sort(tab, pivo + 1, high);
	}
}

// function to find the partition position
int	partition(int tab[], int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = tab[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (tab[j] <= pivot)
		{
			i++;
			swap(&tab[i], &tab[j]);
		}
		j++;
	}
	swap(&tab[i + 1], &tab[high]);
	return (i + 1);
}
