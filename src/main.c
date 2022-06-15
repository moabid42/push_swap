/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:24:50 by moabid            #+#    #+#             */
/*   Updated: 2022/06/15 19:19:26 by moabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stacks.h"

int main(int argc, char **argv)
{
	t_stacks	*stacks;
	t_data		*data;
	char		**strs;

	data = (t_data *)ft_malloc(sizeof(t_data));
	stacks = (t_stacks *)ft_malloc(sizeof(t_stacks));
	if (argc == 2)
	{
		strs = ft_split(argv[1], ' ');
		if(ft_IsNumber(argv[1]) == TRUE);
		else if (!parsing2(data, strs, ft_get_nb_strs(argv[1], ' ')))
			ft_error();
	}
	else if (!parsing1(data, argv, argc))
		ft_error();
	indexArray(data->tab, data->indexarr, data->argc);
	ft_init_stacks(data, stacks);
	solve(stacks);
	ft_freeme(stacks->a);
}