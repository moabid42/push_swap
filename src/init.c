/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:38:58 by moabid            #+#    #+#             */
/*   Updated: 2022/05/22 21:10:04 by moabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stacks.h"

// void	ft_sort_3(t_stack **a)
// {
// 	int	c1;
// 	int	c2;
// 	int	c3;

// 	c1 = (*a)->value;
// 	c2 = (*a)->next->value;
// 	c3 = (*a)->next->next->value;
// 	if (c1 > c2 && c2 < c1 && c1 < c3)
// 		ft_fswap(*a, 'a');
// 	else if (c1 > c2 && c2 > c3 && c1 > c3)
// 	{
// 		ft_fswap(*a, 'a');
// 		ft_reverse(a, 'a');
// 	}
// 	else if (c1 > c2 && c2 < c3 && c1 > c3)
// 		ft_rotate(a, 'a');
// 	else if (c1 < c2 && c2 > c3 && c1 < c3)
// 	{
// 		ft_fswap(*a, 'a');
// 		ft_reverse(a, 'a');
// 	}
// 	else
// 		ft_reverse(a, 'a');
// }

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

int	ft_chr_grender_pivot(t_stack *a, int pivot)
{
	int		shunk;
	t_stack	*sp;

	shunk = a->shunk;
	sp = a;
	while (sp && sp->shunk == shunk)
	{
		if (sp->value > pivot)
			return (1);
		sp = sp->next;
	}
	return (0);
}

void	ft_unshanking(t_stack **a, t_stack **b)
{
	while (*b)
	{
		if (ft_nbr_shunk(*b, (*b)->shunk) == 1)
			ft_push(a, b, 'a');
		else if (ft_nbr_shunk(*b, (*b)->shunk) == 2)
		{
			if ((*b)->value <= (*b)->next->value)
				ft_sb(b, -42);
			ft_push(a, b, 'a');
			ft_push(a, b, 'a');
		}
		else
			ft_b_divide(a, b);
	}
}

void	ft_shanking(t_stacks *stacks, int start, int nbr_ra)
{
	int	pivot;
	int	shunk;

	shunk = (*a)->shunk;
	while (!ft_is_sorted(*a) && ft_nbr_shunk(*a, (*a)->shunk) > 2)
	{
		shunk++;
		nbr_ra = 0;
		pivot = ft_get_the_midlle(*a, (*a)->shunk);
		printf("I m the fucking \
					Pivot  %d    \n", pivot);
		while (ft_chr_less_pivot(*a, pivot))
		{
			if (ft_pushmeIFless(a, b, pivot, shunk))
			{
				ft_ra(a, -42);
				// printf("      After ROTATION :\n");
				// printf("The stack a contains : \n");
				// printer(*a);
				// printf("The stack B contains : \n");
				// printer(*b);
				nbr_ra++;
			}
		}
		while (!start && nbr_ra--)
		{
			ft_rra(a, -42);
			// printf("      After Reversing :\n");
			// printf("The stack a contains : \n");
			// printer(*a);
			// printf("The stack B contains : \n");
			// printer(*b);	
		}
	}
	if (!ft_is_sorted(*a))
	{
		ft_sa(a, -42);
		// printf("      After Swaping :\n");
		// printf("The stack a contains : \n");
		// printer(*a);
		// printf("The stack B contains : \n");
		// printer(*b);
	}
}

int	ft_pushmeIFless(t_stack **a, t_stack **b, int pivot, int shunk)
{
	if ((*a)->value < pivot)
	{
		ft_push(b, a, 'b');
			// printf("      After Pushing :\n");
			// printf("The stack a contains : \n");
			// printer(*a);
			// printf("The stack B contains : \n");
			// printer(*b);
		(*b)->shunk = shunk;
		return (0);
	}
	return (1);
}

void	ft_b_divide(t_stack **a, t_stack **b)
{
	int	pivot;
	int	rb_nbr;

	rb_nbr = 0;
	pivot = 0;
	pivot = ft_get_the_midlle(*b, (*b)->shunk);
	while (ft_chr_grender_pivot(*b, pivot))
	{
		if ((*b)->value > pivot)
		{
			ft_push(a, b, 'a');
			(*a)->shunk++;
			(*a)->shunk++;
		}
		else
		{
			ft_rotate(b, 'b');
			rb_nbr++;
		}
	}
	while (rb_nbr--)
		ft_reverse(b, 'b');
	ft_shanking(a, b, 0, 0);
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
		
		ft_shanking(stacks, 1, 0);
		
		printf("      After shanking :\n");
		printf("The stack a contains : \n");
		printer(stacks->a);
		printf("The stack B contains : \n");
		printer(stacks->b);

		ft_unshanking(&stacks->a, &stacks->b);
		
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
int	ft_get_the_midlle(t_stack *a, int shunk)
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

int	ft_chr_less_pivot(t_stack *a, int pivot)
{
	t_stack	*sp;

	sp = a;
	while (sp)
	{
		if (sp->value < pivot)
			return (1);
		sp = sp->next;
	}
	return (0);
}

void	ft_check_duplicate(t_stack *a)
{
	t_stack	*tmp;
	t_stack	*iter;

	tmp = a;
	while (tmp)
	{
		iter = a;
		while (iter)
		{
			if (tmp->value == iter->value && tmp != iter)
				exit(0);
			iter = iter->next;
		}
		tmp = tmp->next;
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


void	ft_fswap(t_stack *a, int c)
{
	int	tmp;

	if (a && a->next)
	{
		tmp = a->value;
		a->value = a->next->value;
		a->next->value = tmp;
	}
	if (c)
	{
		write(1, "s", 1);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
}

void	ft_push(t_stack **dest, t_stack **src, int c)
{
	t_stack	*tmp;

	if (*src)
	{
		tmp = *src;
		*src = (*src)->next;
		tmp->next = *dest;
		*dest = tmp;
	}
	if (c)
	{
		write(1, "p", 1);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
}

void	ft_rotate(t_stack **a, int c)
{
	t_stack	*tmp;
	t_stack	*head;

	if (*a && (*a)->next)
	{
		head = *a;
		*a = (*a)->next;
		tmp = head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = head;
		tmp->next->next = NULL;
	}
	if (c)
	{
		write(1, "r", 1);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
}

void	ft_reverse(t_stack **a, int c)
{
	t_stack	*last;
	t_stack	*tmp;

	if (*a && (*a)->next)
	{
		tmp = *a;
		while (tmp->next->next)
			tmp = tmp->next;
		last = tmp->next;
		tmp->next = NULL;
		last->next = *a;
		*a = last;
	}
	if (c)
	{
		write(1, "rr", 2);
		write(1, &c, 1);
		write(1, "\n", 1);
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
