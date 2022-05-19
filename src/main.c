/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:24:50 by moabid            #+#    #+#             */
/*   Updated: 2022/05/19 00:39:33 by moabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stacks.h"

int main(int argc, char **argv)
{
	t_stacks	*stacks;
	t_data		*data;
	// t_stack *b = NULL;
	
	if (argc < 2)
		ft_error();
	data = (t_data *)ft_malloc(sizeof(t_data));
	stacks = (t_stacks *)ft_malloc(sizeof(t_stacks));
	if (!parsing(data, argv, argc))
		ft_error();
	ft_init_stacks(data, stacks);

	printf("The unsorted array is :\n");
	printtab(data->tab, data->argc);
	
	quickSort(data->tab, 0, data->argc - 1);
	data->mid = data->tab[data->argc / 2];

	printf("The sorted array is :\n");
	printtab(data->tab, data->argc);
	// printf("The average is : %d\n", data->mid);
	// ft_sa(&stacks->a, -42);
	// // printer(stacks->b);
	// // printer(stacks->a);
	// ft_pb(stacks);
	// // printer(stacks->b);
	// // printer(stacks->a);
	// ft_pb(stacks);
	// // printer(stacks->b);
	// // printer(stacks->a);
	// ft_pb(stacks);
	// // printer(stacks->b);
	// // printer(stacks->a);
	// ft_pa(stacks);
	// // printer(stacks->b);
	// // printer(stacks->a);
	// ft_sb(&stacks->b, -42);
	// // printer(stacks->b);
	// // printer(stacks->a);
	// ft_ra(&stacks->a, -42);
	// // printer(stacks->b);
	// // printer(stacks->a);
	// ft_rra(&stacks->a, -42);
	// // printer(stacks->b);
	// // printer(stacks->a);
	// ft_rrb(&stacks->b, -42);
	printf("The stack a contains :\n-|");
	printer(stacks->a);
	printf("The stack b contains :\n-|");
	printer(stacks->b);

	solve(data, stacks);
	
	printf("The stack a contains :\n-|");
	printer(stacks->a);
	printf("The stack b contains :\n-|");
	printer(stacks->b);
}