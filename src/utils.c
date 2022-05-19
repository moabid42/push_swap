/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:32:53 by moabid            #+#    #+#             */
/*   Updated: 2022/05/19 00:44:19 by moabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stacks.h"

void	*ft_malloc(size_t size)
{
	void *ptr;

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

void	printer(t_stack *head)
{
	t_stack *tmp;
	int i;

	tmp = head;
	i = 0;
	while (tmp)
	{
		printf("%d : [%d] -> ", tmp->value, i++);
		tmp = tmp->next;	
	}
	printf("\n");
}

t_stack	*stacklast(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst != NULL)
	{
		if (lst -> next == 0)
			return (lst);
		lst = lst -> next;
	}
	return (NULL);
}

void	ft_insert_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = stacklast(*lst);
	last->next = new;
}

void	ft_insert_front(t_stack **lst, t_stack *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new -> next = *lst;
	*lst = new;
}

void	ft_error()
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

void	swap(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}

int	average(int num, int *tab)
{
	int i;
	int sum;

	i = 0;
	sum = 0;
	while (i < num)
	{
		sum += tab[i];
		i++;
	}
	return (sum / num);
}

// function to print tab elements
void	printtab(int tab[], int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
    	printf("%d  ", tab[i]);
		i++;
	}
	printf("\n");
}
