/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:38:58 by moabid            #+#    #+#             */
/*   Updated: 2022/05/24 15:55:08 by moabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stacks.h"

void	ft_sortSmall(t_stacks *stacks, t_data *data)
{
	int top;

	top = 0;
	while (top != data->argc - 1)
	{
		if (stacks->a->value == top)
		{
			ft_pb(stacks);
			top++;
		}
		else
			ft_ra(&stacks->a, -42);
	}
	while(top)
	{
		ft_pa(stacks);
		top--;
	}
}

int	ft_bottum_stack(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp->value);
}

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

int	ft_greaterPivotChecker(t_stack *a, int pivot)
{
	int		shunk;
	t_stack	*tmp;

	shunk = a->shunk;
	tmp = a;
	while (tmp && tmp->shunk == shunk)
	{
		if (tmp->value > pivot)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	ft_unshanking(t_stacks *stacks)
{
	while (stacks->b)
	{
		if (ft_nbr_shunk(stacks->b, stacks->b->shunk) == 1)
			ft_pa(stacks);
		else if (ft_nbr_shunk(stacks->b, stacks->b->shunk) == 2)
		{
			if (stacks->b->value <= stacks->b->next->value)
				ft_sb(&stacks->b, -42);
			ft_pa(stacks);
			ft_pa(stacks);
		}
		else
			ft_b_divide(stacks);
	}
}

void	ft_shanking(t_stacks *stacks, int start, int nbr_ra)
{
	int	pivot;
	int	shunk;

	shunk = stacks->a->shunk;
	while (!ft_is_sorted(stacks->a) && ft_nbr_shunk(stacks->a, stacks->a->shunk) > 2)
	{
		shunk++;
		nbr_ra = 0;
		pivot = ft_getMidlle(stacks->a, stacks->a->shunk);
		while (ft_lessPivotChecker(stacks->a, pivot) == TRUE) // we are gonna stop if there is no more pivot left
		{
			if (ft_pushmeIFless(stacks, pivot, shunk) == FALSE)
			{
				ft_ra(&stacks->a, -42);
				nbr_ra++;
			}
		}
		while (!start && nbr_ra--)
			ft_rra(&stacks->a, -42);
	}
	if (ft_is_sorted(stacks->a) == FALSE)
		ft_sa(&stacks->a, -42);
}



int	ft_pushmeIFless(t_stacks *stacks, int pivot, int shunk)
{
	if (stacks->a->value < pivot)
	{
		ft_pb(stacks);
		stacks->b->shunk = shunk;
		return (TRUE);
	}
	return (FALSE);
}

void	ft_b_divide(t_stacks *stacks)
{
	int	pivot;
	int	rb_nbr;

	rb_nbr = 0;
	pivot = 0;
	pivot = ft_getMidlle(stacks->b, stacks->b->shunk);
	while (ft_greaterPivotChecker(stacks->b, pivot))
	{
		if (stacks->b->value > pivot)
		{
			ft_pa(stacks);
			stacks->a->shunk++;
			stacks->a->shunk++;
		}
		else
		{
			ft_rb(&stacks->b, -42);
			rb_nbr++;
		}
	}
	while (rb_nbr--)
		ft_rrb(&stacks->b, -42);
	ft_shanking(stacks, 0, 0);
}

//work on the edge cases
void	solve(t_stacks *stacks, t_data *data)
{
	if (!stacks->a && ft_is_sorted(stacks->a))
		return ;
	if (data->argc == 3)
		ft_sortSmall(stacks, data);
	else
	{
		printf("<-The stack a contains : \n");
		printer(stacks->a);
		printf("<-The stack B contains : \n");
		printer(stacks->b);
		
		ft_shanking(stacks, 42, 0);
		
		printf("      After shanking :\n");
		printf("The stack a contains : \n");
		printer(stacks->a);
		printf("The stack B contains : \n");
		printer(stacks->b);

		ft_unshanking(stacks);
		
		printf("      After UNshanking :\n");
		printf("The stack a contains : \n");
		printer(stacks->a);
		printf("The stack B contains : \n");
		printer(stacks->b);
		
		
	}
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
// To Do: get rid of this function and use t_data
int	ft_getMidlle(t_stack *a, int shunk)
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

int	ft_lessPivotChecker(t_stack *a, int pivot)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp)
	{
		if (tmp->value < pivot)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

// int	ft_check_duplicate(int *tab, int number)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	while (i < number - 1)
// 	{
// 		j = i + 1;
// 		while (j < number - i)
// 		{
// 			if (tab[i] == tab[j])
// 				return (TRUE);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (FALSE);
// }

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

void	ft_init_shunk(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp)
	{
		tmp->shunk = 0;
		tmp = tmp->next;
	}
}

int	ft_is_sorted(t_stack *a)
{
	int	shunk;

	shunk = a->shunk;
	while (a && a->shunk == shunk)
	{
		if (a->next && a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
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
