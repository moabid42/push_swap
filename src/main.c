/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:24:50 by moabid            #+#    #+#             */
/*   Updated: 2022/06/17 02:22:11 by moabid           ###   ########.fr       */
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
		check_error(argv, argc);
		str = parseme(argv, argc);
		ft_sanitize(str);
		strs = ft_split(str, ' ');
		if (!parsing2(data, strs, ft_get_nb_strs(str, ' ')))
			ft_error();
	}
	ft_init_stacks(data, stacks);
	solve(stacks);
	ft_freeme(stacks->a);
}
