/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:44:48 by moabid            #+#    #+#             */
/*   Updated: 2022/05/20 16:05:42 by moabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stacks.h"

void	solve(t_data *data, t_stacks *stacks)
{
	int i;
	int j;

	i = 0;
	j = 42;
	while (i < data->argc)
	{
		if (stacks->a->value < data->mid)
			ft_pb(stacks);
		else
			ft_ra(&stacks->a, -42);
		i++;
	}
	// printf("* The stack a contains :\n-|");
	// printer(stacks->a);
	// printf("* The stack b contains :\n-|");
	// printer(stacks->b);
	
	// printf("Max = [%d] {} Min = [%d]\n", data->max ,data->min);
	sorting_b(data->max, data->min, stacks, data);

	// printf("~ The stack a contains :\n-|");
	// printer(stacks->a);
	// printf("~ The stack b contains :\n-|");
	// printer(stacks->b);
	
	// sorting_a(data->argc / 2, stacks, data);
		
	// printf("The stack a contains :\n-|");
	// printer(stacks->a);
	// printf("The stack b contains :\n-|");
	// printer(stacks->b);
	push_b_to_a(data, stacks);
}

void	sorting_b(int max, int min, t_stacks *stacks, t_data *data)
{
	int mid;
	int i;
	int j;
	
	mid = (min + max) / 2;
	printf("Max = [%d] {} Min = [%d] {} mid = [%d]\n", max ,min, mid);
	printf("\n <->The stack a contains :\n\n-|");
	printer(stacks->a);
	printf("\n <->The stack b contains :\n\n-|");
	printer(stacks->b);
	i = 0;
	j = 0;
	if (min >= max - 2)
	{
		if (stacks->b->value < stacks->b->next->value)
		{
			printf("0\n");
			ft_sb(&stacks->b, -42);
		}			
		return ;
	}
	while (i < max - min)
	{
		if (stacks->b->value >= mid)
			ft_pa(stacks);
		else
		{
			ft_rb(&stacks->b, -42);
			j++;
		}
		i++;
	}
	
	printf("\n <->The stack a contains :\n\n-|");
	printer(stacks->a);
	printf("\n <->The stack b contains :\n\n-|");
	printer(stacks->b);
	
	sortLower(j, stacks, data);

	push_a_to_b(data, stacks);
	
	printf("\n <->The stack a contains :\n\n-|");
	printer(stacks->a);
	printf("\n <->The stack b contains :\n\n-|");
	printer(stacks->b);
	
	sorting_b(max, min + ((max - min) / 2), stacks, data);
}


// void	sorting_b(int max, int min, t_stacks *stacks, t_data *data)
// {
	
// }

void	sortLower(int j, t_stacks *stacks, t_data *data)
{
	if (j == data->argc / 4)
		sort();
	else
		while (j--)
			ft_rrb(&stacks->b, -42);
}

void	push_b_to_a(t_data *data, t_stacks *stacks)
{
	int i;

	i = 0;
	while (i < ((data->argc / 2) - stacks->a_count))
	{
		ft_pa(stacks);
		i++;
	}
}

void	push_a_to_b(t_data *data, t_stacks *stacks)
{
	while (((data->argc / 2) - stacks->b_count))
		ft_pb(stacks);
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