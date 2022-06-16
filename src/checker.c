/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 23:05:05 by moabid            #+#    #+#             */
/*   Updated: 2022/06/16 18:02:45 by moabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stacks.h"

void	ft_action_processing(char *line, t_stacks *stacks)
{
	if (my_strcmp(line, "sa") == 0)
		ft_sa(&stacks->a, 42);
	else if (my_strcmp(line, "sb") == 0)
		ft_sb(&stacks->b, 42);
	else if (my_strcmp(line, "ss") == 0)
		ft_ss(stacks);
	else if (my_strcmp(line, "pa") == 0)
		ft_pa(stacks, 42);
	else if (my_strcmp(line, "pb") == 0)
		ft_pb(stacks, 42);
	else if (my_strcmp(line, "ra") == 0)
		ft_ra(&stacks->a, 42);
	else if (my_strcmp(line, "rb") == 0)
		ft_rb(&stacks->b, 42);
	else if (my_strcmp(line, "rr") == 0)
		ft_rr(stacks);
	else if (my_strcmp(line, "rra") == 0)
		ft_rra(&stacks->a, 42);
	else if (my_strcmp(line, "rrb") == 0)
		ft_rrb(&stacks->b, 42);
	else if (my_strcmp(line, "rrr") == 0)
		ft_rrr(stacks);
	else
		ft_error();
}

void	ft_read_action(t_stacks *stacks)
{
	char	*line;

	line = get_next_line(0);
	while (line != NULL)
	{
		new_line_remove(line);
		ft_action_processing(line, stacks);
		free(line);
		line = get_next_line(0);
	}
	if (line)
	{
		free(line);
		line = NULL;
	}
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	t_data		*data;
	char		**strs;
	char		*str;

	data = (t_data *)ft_malloc(sizeof(t_data));
	stacks = (t_stacks *)ft_malloc(sizeof(t_stacks));
	if (argc > 1)
	{
		str = parseme(argv, argc);
		strs = ft_split(str, ' ');
		if (!parsing2(data, strs, ft_get_nb_strs(str, ' ')))
			ft_error();
	}
	ft_init_stacks(data, stacks);
	ft_read_action(stacks);
	if ((ft_is_sorted(stacks->a) == TRUE && (stacks->b == NULL)))
		write(1, "\033[0;32mOK😁\033[0m\n", 19);
	else
		write(1, "\033[0;31mKO😡\033[0m\n", 19);
	ft_freeme(stacks->a);
}
