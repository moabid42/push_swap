/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:24:50 by moabid            #+#    #+#             */
/*   Updated: 2022/05/22 21:09:19 by moabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stacks.h"

int main(int argc, char **argv)
{
	t_stacks	*stacks;
	t_data		*data;
	
	if (argc < 2)
		ft_error();
	data = (t_data *)ft_malloc(sizeof(t_data));
	stacks = (t_stacks *)ft_malloc(sizeof(t_stacks));
	if (!parsing(data, argv, argc))
		ft_error();
	quickSort(data->tab, 0, data->argc - 1);
	indexArray(data->tab, data->indexarr, data->argc);
	
	// printf("--> The indexed array is :\n");
	// printtab(data->indexarr, data->argc);
	
	ft_init_stacks(data, stacks);	
	// printf("The sorted array is :\n");
	// printtab(data->tab, data->argc);
	
	data->partitions = (data->argc / 10) + 1;

	// printf("The average is : %d\n", data->mid);
	// printf("The stack a contains :\n-|");
	// printer(stacks->a);
	// printf("The stack b contains :\n-|");
	// printer(stacks->b);

	solve(stacks, data);
	
	// printf("The stack a contains :\n-|");
	// printer(stacks->a);
	// printf("The stack b contains :\n-|");
	// printer(stacks->b);
}


// void	ft_quick_sort(t_stack **a, t_stack **b)
// {
// 	if (!a && ft_is_sorted(*a) && !(*b))
// 		return ;
// 	if (ft_len_stack(*a) == 3)
// 		ft_sort_3(a);
// 	else
// 	{
// 		printf("<-The stack a contains : \n");
// 		printer(*a);
// 		printf("<-The stack B contains : \n");
// 		printer(*b);
// 		ft_shanking(a, b, 1, 0);
// 		printf("      After shanking :\n");
// 		printf("The stack a contains : \n");
// 		printer(*a);
// 		printf("The stack B contains : \n");
// 		printer(*b);
// 		ft_unshanking(a, b);
// 		printf("      After UNshanking :\n");
// 		printf("The stack a contains : \n");
// 		printer(*a);
// 		printf("The stack B contains : \n");
// 		printer(*b);
// 	}
// }