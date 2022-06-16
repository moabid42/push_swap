/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:24:50 by moabid            #+#    #+#             */
/*   Updated: 2022/06/16 19:02:24 by moabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stacks.h"

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	t_data		*data;
	char		*str;
	char		**strs;

	data = (t_data *)ft_malloc(sizeof(t_data));
	stacks = (t_stacks *)ft_malloc(sizeof(t_stacks));
	if (argc > 1)
	{
		str = parseme(argv, argc);
		if (space_counter(str) == TRUE)
			ft_error();
		strs = ft_split(str, ' ');
		if (!parsing2(data, strs, ft_get_nb_strs(str, ' ')))
			ft_error();
	}
	index_array(data->tab, data->indexarr, data->argc);
	ft_init_stacks(data, stacks);
	solve(stacks);
	ft_freeme(stacks->a);
}
