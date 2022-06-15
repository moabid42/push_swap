/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:32:53 by moabid            #+#    #+#             */
/*   Updated: 2022/06/15 15:28:56 by moabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stacks.h"

unsigned int	ft_get_nb_strs(char const *s, char c)
{
	unsigned int	i;
	unsigned int	nb_strs;

	if (!s[0])
		return (0);
	i = 0;
	nb_strs = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			nb_strs++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		nb_strs++;
	return (nb_strs);
}


void	new_line_remove(char *line)
{
	int i;
	
	i = 0;
	while(line[i] != '\n')
		i++;
	line[i] = '\0';
}

void	ft_freeme(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}

void	reverseTab(int *tab, int size)
{
	int j;
	int i;
	int Tmp;
	
	j = size - 1;
	i = 0;
	while (i < j) 
	{
		Tmp = tab[i];
		tab[i] = tab[j];
		tab[j] = Tmp;
		i++;             
		j--;         
	}
}

int my_strcmp(char *strg1, char *strg2)
{
    while(( *strg1 != '\0' && *strg2 != '\0') && *strg1 == *strg2)
    {
        strg1++;
        strg2++;
    }
    if(*strg1 == *strg2)
        return 0;
    else
        return *strg1 - *strg2;
}

void	ft_check_replication(char **av)
{
	 int	i;
	 int	j;
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

int	ft_IsNumber(const char *str)
{
	int i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

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
		printf("[%d : %d] -> ", tmp->value, i++);
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
	fflush(stderr);
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

int *copyArray(int *arr, int size)
{
	int i;
	int *copy;
	
	i = 0;
	copy = ft_malloc(sizeof(int) * size);
	while (i < size)
	{
		copy[i] = arr[i];
		i++;
	}
	return (copy);
}

void	indexArray(int *tab, int *indexarr, int num)
{
	int i;
	int j;

	i = 0;
	while (i < num)
	{
		j = 0;
		quickSort(tab, 0, num - 1);
		while (j < num)
		{
			if (indexarr[i] == tab[j])
				indexarr[i] = j; 
			j++;
		}
		i++;
	}
}