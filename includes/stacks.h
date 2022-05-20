/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:24:47 by moabid            #+#    #+#             */
/*   Updated: 2022/05/20 16:06:00 by moabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKS_H
# define STACKS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
# include "../libft/libft.h"

#define TRUE	1
#define FALSE	0

///////////////////////
//	    Structs		 //
///////////////////////

typedef struct 		s_stack
{
	int				value;
	struct s_stack	*next;	
}					t_stack;

typedef struct		s_data
{
	int				*tab;
	int				*indexarr;
	int				max;
	int				min;
	int				argc;
	int				mid;
}					t_data;

typedef struct 		s_stacks
{
	t_stack			*a;
	int				a_count;
	t_stack			*b;
	int				b_count;
}					t_stacks;

///////////////////////
//	   FUNCTIONS	 //
///////////////////////

void	ft_error();
int 	parsing(t_data *data, char **argv, int argc);
void	printer(t_stack *head);
t_stack	*new_node(char *argv);
void	*ft_malloc(size_t size);
void	ft_insert_back(t_stack **lst, t_stack *new);
t_stack	*stacklast(t_stack *lst);
void	ft_init_stacks(t_data *data, t_stacks *stacks);
t_stack	*ft_create_stack(int *indexarr, int count);
void	ft_insert_front(t_stack **lst, t_stack *new);
int		average(int num, int *tab);
int		*copyArray(int *arr, int size);
void	indexArray(int *tab, int indexarr[], int num);


///////////////////////
//	  Operations	 //
///////////////////////

void	ft_sa(t_stack **a, int id);
void	ft_sb(t_stack **b, int id);
void	ft_ss(t_stacks *stack);

void	ft_pb(t_stacks *stacks);
void	ft_pa(t_stacks *stacks);

void	ft_ra(t_stack **a, int id);
void	ft_rb(t_stack **b, int id);
void	ft_rr(t_stacks *stack);

void	ft_rra(t_stack **a, int id);
void	ft_rrb(t_stack **b, int id);
void	ft_rrr(t_stacks *stack);

///////////////////////
//	  Algorithm		 //
///////////////////////

void	quickSort(int *tab, int low, int high);
int		partition(int tab[], int low, int high);
void	printtab(int tab[], int size);
void	swap(int *a, int *b);
void	solve(t_data *data, t_stacks *stacks);
void	push_b_to_a(t_data *data, t_stacks *stacks);
void	push_a_to_b(t_data *data, t_stacks *stacks);
void	sorting_b(int max, int min, t_stacks *stacks, t_data *data);
void	sorting_a(int elements, t_stacks *stacks, t_data *data);
void	sortLower(int j, t_stacks *stacks, t_data *data);



#endif