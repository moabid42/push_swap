/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 22:46:05 by moabid            #+#    #+#             */
/*   Updated: 2022/06/16 01:16:32 by moabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stacks.h"

int	ft_nbr_shunk(t_stack *a, int shunk)
{
	int	n;

	n = 0;
	while (a && a->shunk == shunk)
	{
		n++;
		a = a->next;
	}
	return (n);
}

int	ft_is_sorted(t_stack *a)
{
	int	shunk;

	shunk = a->shunk;
	while (a && a->shunk == shunk)
	{
		if (a->next && a->value > a->next->value)
			return (FALSE);
		a = a->next;
	}
	return (TRUE);
}

int	ft_get_midlle(t_stack *a, int shunk)
{
	int	len;
	int	*array;
	int	i;
	int	pivot;

	i = 0;
	shunk = a->shunk;
	len = ft_len_stack(a);
	array = (int *)malloc(sizeof(int) * len);
	while (a && a->shunk == shunk)
	{
		array[i++] = a->value;
		a = a->next;
	}
	ft_sort_integer_table(array, len);
	pivot = array[len / 2];
	free(array);
	return (pivot);
}

void	ft_sort_integer_table(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = size;
	while (--i >= 0)
	{
		j = -1;
		while (++j <= i - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j + 1];
				tab[j + 1] = tab[j];
				tab[j] = tmp;
			}
		}
	}
}

int	ft_len_stack(t_stack *a)
{
	int	len;
	int	shunk;

	shunk = a->shunk;
	len = 0;
	while (a && shunk == a->shunk)
	{
		len++;
		a = a->next;
	}
	return (len);
}
