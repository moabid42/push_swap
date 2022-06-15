/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:24:50 by moabid            #+#    #+#             */
/*   Updated: 2022/06/15 13:58:40 by moabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stacks.h"

int main(int argc, char **argv)
{
	t_stacks	*stacks;
	t_data		*data;
	char		**strs;
	
	if (argc < 2)
		ft_error();
	data = (t_data *)ft_malloc(sizeof(t_data));
	stacks = (t_stacks *)ft_malloc(sizeof(t_stacks));
	if (argc == 2)
	{
		strs = ft_split(argv[1], argc - 1);
	}
	if (!parsing(data, argv, argc, 1))
		ft_error();
	indexArray(data->tab, data->indexarr, data->argc);
	ft_init_stacks(data, stacks);
	solve(stacks);
	ft_freeme(stacks->a);
}