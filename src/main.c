/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:24:50 by moabid            #+#    #+#             */
/*   Updated: 2022/07/23 01:10:22 by moabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stacks.h"

static void	free_all(t_stacks *stacks, t_data *data)
{
	free(data);
	free(stacks);
}

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
		ft_sanitize(str, data, stacks);
		strs = ft_split(str, ' ');
		if (!parsing2(data, strs, ft_get_nb_strs(str, ' ')))
		{
			free_str(strs);
			ft_error(str);
		}
		ft_init_stacks(data, stacks);
		solve(stacks, data);
		ft_destroy_utils(stacks, str, strs);
	}
	else
		free_all(stacks, data);
}
