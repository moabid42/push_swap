/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:44:48 by moabid            #+#    #+#             */
/*   Updated: 2022/05/19 13:35:01 by moabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stacks.h"

void	solve(t_data *data, t_stacks *stacks)
{
	int i;

	i = 0;
	while (i < data->argc)
	{
		if (stacks->a->value < data->mid)
			ft_pb(stacks);
		else
			ft_ra(&stacks->a, -42);
		i++;
	}
	printf("* The stack a contains :\n-|");
	printer(stacks->a);
	printf("* The stack b contains :\n-|");
	printer(stacks->b);
	
	sorting_b(data->argc / 2, stacks, data);

	printf("~ The stack a contains :\n-|");
	printer(stacks->a);
	printf("~ The stack b contains :\n-|");
	printer(stacks->b);
	
	// sorting_a(data->argc / 2, stacks, data);
		
	// printf("The stack a contains :\n-|");
	// printer(stacks->a);
	// printf("The stack b contains :\n-|");
	// printer(stacks->b);
	push_b_to_a(data->argc / 2, stacks);
}

void	sorting_b(int elements, t_stacks *stacks, t_data *data)
{
	int mid;
	int i;

	mid = data->tab[elements / 2];
	i = 0;
	while (i < elements / 2)
	{
		if (stacks->a->value >= mid)
			ft_pa(stacks);
		else
			ft_rb(&stacks->a, -42);
		i++;
	}
	if (elements < 1)
		return ;
	// printf(" ->The stack a contains :\n-|");
	// printer(stacks->a);
	// printf(" ->The stack b contains :\n-|");
	// printer(stacks->b);
	push_a_to_b(elements / 2, stacks);
	sorting_b(elements / 2, stacks, data);
}

void	sorting_a(int elements, t_stacks *stacks, t_data *data)
{
	int mid;
	int i;

	mid = data->tab[elements + (elements / 2)];
	// printf("The index of mid is : %d\n", elements + (elements / 2));
	i = 0;
	while (i < elements / 2)
	{
		if (stacks->b->value < mid)
			ft_pb(stacks);
		else
			ft_ra(&stacks->b, -42);
		i++;
	}
	if (elements > 1)
		return ;
	push_b_to_a(elements / 2, stacks);
	sorting_a(elements + (elements / 2), stacks, data);
}

void	push_b_to_a(int num, t_stacks *stacks)
{
	int i;

	i = 0;
	while (i < num)
	{
		ft_pa(stacks);
		printf("[%d]\n", i);
		i++;
	}
}

void	push_a_to_b(int num, t_stacks *stacks)
{
	int i;

	i = 0;
	while (i < num)
	{
		ft_pb(stacks);
		i++;
	}
}



void	quickSort(int *tab, int low, int high)
{
	int pivo;

	if (low < high)
	{
		pivo = partition(tab, low, high);
        quickSort(tab, low, pivo - 1);      // recursive call on the left of pivot
    	quickSort(tab, pivo + 1, high);		// recursive call on the right of pivot
	}
}

// function to find the partition position
int partition(int tab[], int low, int high)
{
	int pivot;
	int i;
	int j;

	pivot = tab[high];
	i = low - 1;
	j = low;
	while(j < high)
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