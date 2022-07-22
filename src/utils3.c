/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 00:21:49 by moabid            #+#    #+#             */
/*   Updated: 2022/07/22 19:36:24 by moabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stacks.h"

void	printer(t_stack *head)
{
	t_stack	*tmp;
	int		i;

	tmp = head;
	i = 0;
	while (tmp)
	{
		printf("[%d : %d] -> ", tmp->value, i++);
		tmp = tmp->next;
	}
	printf("\n");
}

// void	printtab(int tab[], int size)
// {
// 	int	i;

// 	i = 0;
// 	while (i < size)
// 	{
// 		printf("%d  ", tab[i]);
// 		i++;
// 	}
// 	printf("\n");
// }

void	*ft_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr)
		ft_bzero(ptr, size);
	else
	{
		free(ptr);
		exit(1);
	}
	return (ptr);
}

void	ft_error(char *str)
{
	ft_putendl_fd("Error", 2);
	if (str != NULL)
		free(str);
	fflush(stderr);
	exit(1);
}

void	ft_check_replication(char **av)
{
	int		i;
	int		j;
	char	*replica;

	i = 0;
	while (av[i])
	{
		replica = ft_strdup(av[i]);
		j = 0;
		while (av[j])
		{
			if (j == i)
				j++;
			else if ((my_strcmp(replica, av[j]) == 0)
				|| (ft_atoi(replica) == ft_atoi(av[j])))
				ft_error(replica);
			else
				j++;
		}
		free(replica);
		i++;
	}
}

void	ft_sanitize(char *str, t_data *data, t_stacks *stacks)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] == '-' || str[i] == '+') && !ft_isdigit(str[i + 1]))
		{
			ft_free_stacks(stacks);
			ft_free_data(data);
			ft_error(str);
		}
		i++;
	}
}
