/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 23:05:05 by moabid            #+#    #+#             */
/*   Updated: 2022/05/25 00:46:51 by moabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	ft_action_processing(char *line, t_stacks *stacks)
{
	if (my_strcmp(line, "sa") == 0)
		ft_sa(&stacks->a, -42);
	else if (my_strcmp(line, "sb") == 0)
		ft_sb(&stacks->b, -42);
	else if (my_strcmp(line, "ss") == 0)
		ft_ss(stacks);
	else if (my_strcmp(line, "pa") == 0)
		ft_pa(stacks);
	else if (my_strcmp(line, "pb") == 0)
		ft_pb(stacks);
	else if (my_strcmp(line, "ra") == 0)
		ft_ra(&stacks->a, -42);
	else if (my_strcmp(line, "rb") == 0)
		ft_rb(&stacks->b, -42);
	else if (my_strcmp(line, "rr") == 0)
		ft_rr(stacks);
	else if (my_strcmp(line, "rra") == 0)
		ft_rra(&stacks->a, -42);
	else if (my_strcmp(line, "rrb") == 0)
		ft_rrb(&stacks->b, -42);
	else if (my_strcmp(line, "rrr") == 0)
		ft_rrr(stacks);
	else
		ft_error();
}

void	ft_read_action(t_stacks *stacks)
{
	char *line;

	while (line = get_next_line(0))
	{
		ft_action_processing(line, stacks);
		free(line);
	}
}

int	main(int argc, char **argv)
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
	ft_init_stacks(data, stacks);
	ft_read_actions(stacks, data);
	if ((ft_is_sorted(stacks->a)) && (ft_len_stack(stacks->b) == 0)
		&& ft_len_stack(stacks->a) == data->argc))
		write(1, "\033[0;32mOK😁\033[0m\n", 3);
	else
		write(1, "\033[0;31mKO😡\033[0m\n", 3);
	ft_freeme(stacks->a);
}