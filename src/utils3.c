/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 00:21:49 by moabid            #+#    #+#             */
/*   Updated: 2022/06/16 01:30:51 by moabid           ###   ########.fr       */
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
// 		// printf("%d  ", tab[i]);
// 		i++;
// 	}
// 	// printf("\n");
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

void	ft_error(void)
{
	ft_putendl_fd("Error", 2);
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
			else if (my_strcmp(replica, av[j]) == 0)
			{
				free(replica);
				ft_error();
			}
			else
				j++;
		}
		free(replica);
		i++;
	}
}
