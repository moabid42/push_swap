/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:24:47 by moabid            #+#    #+#             */
/*   Updated: 2022/05/22 21:09:13 by moabid           ###   ########.fr       */
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
	int				shunk;
	struct s_stack	*next;	
}					t_stack;

typedef struct		s_data
{
	int				*tab;
	int				*indexarr;
	int				max;
	int				min;
	int				argc;
	int				partitions;
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
void	ft_sort_3(t_stack **a);

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
// void	push_b_to_a(t_data *data, t_stacks *stacks);
// void	push_a_to_b(t_data *data, t_stacks *stacks);
// void	sorting_b(int max, int min, t_stacks *stacks, t_data *data);
// void	sorting_a(int elements, t_stacks *stacks, t_data *data);
// void	sortLower(int j, t_stacks *stacks, t_data *data);

///////////////////////
//	  Algorithm		 //
///////////////////////

void	ft_init_shunk(t_stack *a);
int		ft_is_sorted(t_stack *a);
void	ft_unshanking(t_stack **a, t_stack **b);
void	ft_shanking(t_stack **a, t_stack **b, int start, int nbr_ra);
int		ft_pushmeIFless(t_stack **a, t_stack **b, int pivot, int shunk);
void	ft_b_divide(t_stack **a, t_stack **b);
void	solve(t_data *data, t_stacks *stacks);
void	solve(t_stacks *stacks, t_data *data);
int		ft_nbr_shunk(t_stack *a, int shunk);
int		ft_chr_less_pivot(t_stack *a, int pivot);
int		ft_get_the_midlle(t_stack *a, int shunk);
void	sortSmall(int top, t_stacks *stacks, t_data *data);


void	ft_push(t_stack **dest, t_stack **src, int c);
void	ft_rotate(t_stack **a, int c);
void	ft_reverse(t_stack **a, int c);
void	ft_fswap(t_stack *a, int c);
int		ft_chr_grender_pivot(t_stack *a, int pivot);
int		ft_bottum_stack(t_stack *a);
int		ft_nbr_shunk(t_stack *a, int shunk);
int		ft_len_stack(t_stack *a);
void	ft_check_duplicate(t_stack *a);

#endif