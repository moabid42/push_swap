/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:24:50 by moabid            #+#    #+#             */
/*   Updated: 2022/05/14 13:33:03 by moabid           ###   ########.fr       */
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
	// if (parsing(data, argv, argc))
	// 	ft_error();
	data->argc = argc;
	data->tab = parsing(data, argv, argc);
	ft_init_stacks(data, stacks);
	// printer(stacks->b);
	// printer(stacks->a);
	ft_sa(&stacks->a, -42);
	printer(stacks->b);
	printer(stacks->a);
	ft_pb(stacks);
	printer(stacks->b);
	printer(stacks->a);
	ft_pb(stacks);
	printer(stacks->b);
	printer(stacks->a);
	ft_pb(stacks);
	printer(stacks->b);
	printer(stacks->a);
	ft_pa(stacks);
	printer(stacks->b);
	printer(stacks->a);
	ft_sb(&stacks->b, -42);
	printer(stacks->b);
	printer(stacks->a);
	ft_ra(&stacks->a, -42);
	printer(stacks->b);
	printer(stacks->a);
	ft_rra(&stacks->a, -42);
	printer(stacks->b);
	printer(stacks->a);
	ft_rrb(&stacks->b, -42);
	printer(stacks->b);
	printer(stacks->a);
	// if (solve(data, stacks))
	// 	error();
}