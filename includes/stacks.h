/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:24:47 by moabid            #+#    #+#             */
/*   Updated: 2022/05/24 17:02:12 by moabid           ###   ########.fr       */
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
	int				argc;
}					t_data;

typedef struct 		s_stacks
{
	t_stack			*a;
	int				a_count;
	t_stack			*b;
	int				b_count;
}					t_stacks;

///////////////////////
//	   PARSING		 //
///////////////////////

void		ft_error();
void		ft_init_stacks(t_data *data, t_stacks *stacks);
int 		parsing(t_data *data, char **argv, int argc);
void		*ft_malloc(size_t size);
t_stack		*ft_create_stack(int *indexarr, int count);
int			*copyArray(int *arr, int size);
void		indexArray(int *tab, int indexarr[], int num);

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
//	  	TESTING		 //
///////////////////////


void	swap(int *a, int *b);


///////////////////////
//	  Algorithm		 //
///////////////////////

void		ft_sortSmall(t_stacks *stacks, t_data *data);
void	ft_init_shunk(t_stack *a);
int		ft_is_sorted(t_stack *a);
void	ft_unshanking(t_stacks *stacks);
void	ft_shanking(t_stacks *stacks, int start, int nbr_ra);
int		ft_pushmeIFless(t_stacks *stacks, int pivot, int shunk);
void	ft_b_divide(t_stacks *stacks);
void	solve(t_stacks *stacks, t_data *data);
int		ft_nbr_shunk(t_stack *a, int shunk);
int		ft_lessPivotChecker(t_stack *a, int pivot);
int		ft_getMidlle(t_stack *a, int shunk);
void	sortSmall(int top, t_stacks *stacks, t_data *data);


int		ft_chr_grender_pivot(t_stack *a, int pivot);
int		ft_bottum_stack(t_stack *a);
int		ft_nbr_shunk(t_stack *a, int shunk);
int		ft_len_stack(t_stack *a);

///////////////////////
//	  	UTILS		 //
///////////////////////

void		ft_free_stack(t_stack *stack);
void		ft_insert_back(t_stack **lst, t_stack *new);
t_stack		*stacklast(t_stack *lst);
void		ft_insert_front(t_stack **lst, t_stack *new);
void		ft_freeme(t_stack *stack);
void		quickSort(int *tab, int low, int high);
int			partition(int tab[], int low, int high);
void		printtab(int tab[], int size);
void		printer(t_stack *head);
int			ft_check_duplication(int *tab, int size);
int			ft_IsNumber(const char *str);

#endif