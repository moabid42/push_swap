/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:24:47 by moabid            #+#    #+#             */
/*   Updated: 2022/06/17 22:22:04 by moabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKS_H
# define STACKS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

# define TRUE	1
# define FALSE	0

///////////////////////
//	    Structs		 //
///////////////////////

typedef struct s_stack
{
	int				value;
	int				shunk;
	struct s_stack	*next;	
}				t_stack;

typedef struct s_data
{
	int				*tab;
	int				argc;
}				t_data;

typedef struct s_stacks
{
	t_stack			*a;
	t_stack			*b;
}				t_stacks;

///////////////////////
//	   PARSING		 //
///////////////////////

void			ft_init_stacks(t_data *data, t_stacks *stacks);
int				parsing2(t_data *data, char **argv, int argc);
t_stack			*ft_create_stack(int *indexarr, int count);
char			*parseme(char **argv, int argc);
int				space_counter(char *str);

void			ft_free_stacks(t_stacks *stacks);
void			ft_destroy_utils(t_stacks *stacks, char *str, char **strs);

///////////////////////
//	  Operations	 //
///////////////////////

void			ft_sa(t_stack **a, int id);
void			ft_sb(t_stack **b, int id);
void			ft_ss(t_stacks *stack);

void			ft_pb(t_stacks *stacks, int id);
void			ft_pa(t_stacks *stacks, int id);

void			ft_ra(t_stack **a, int id);
void			ft_rb(t_stack **b, int id);
void			ft_rr(t_stacks *stack);

void			ft_rra(t_stack **a, int id);
void			ft_rrb(t_stack **b, int id);
void			ft_rrr(t_stacks *stack);

///////////////////////
//	  	UTILS		 //
///////////////////////

int				ft_isnumber(const char *str);
void			swap(int *a, int *b);
int				average(int num, int *tab);
void			free_str(char **strs);
void			ft_free_data(t_data *data);

///////////////////////
//	  	UTILS2		 //
///////////////////////

unsigned int	ft_get_nb_strs(char const *s, char c);
void			new_line_remove(char *line);
void			ft_freeme(t_stack **stack);
void			reverse_tab(int *tab, int size);
int				my_strcmp(char *strg1, char *strg2);

///////////////////////
//	  	UTILS3		 //
///////////////////////

void			printer(t_stack *head);
void			printtab(int tab[], int size);
void			*ft_malloc(size_t size);
void			ft_error(char *str);
void			ft_check_replication(char **av);

///////////////////////
//	  STACK_UTILS	 //
///////////////////////

void			ft_insert_back(t_stack **lst, t_stack *new);
t_stack			*stacklast(t_stack *lst);
void			ft_insert_front(t_stack **lst, t_stack *new);

///////////////////////
//	  Algorithm		 //
///////////////////////

void			ft_sort_small(t_stacks *stacks, t_data *data);
void			ft_init_shunk(t_stack *a);
int				ft_is_sorted(t_stack *a);
void			ft_unshanking(t_stacks *stacks);
void			ft_shanking(t_stacks *stacks, int start, int nbr_ra);
int				ft_pushme_if_less(t_stacks *stacks, int pivot, int shunk);
void			ft_b_divide(t_stacks *stacks);
void			solve(t_stacks *stacks);
int				ft_nbr_shunk(t_stack *a, int shunk);
int				ft_less_pivot_checker(t_stack *a, int pivot);
int				ft_get_midlle(t_stack *a, int shunk);
void			sort_small(int top, t_stacks *stacks, t_data *data);
int				ft_chr_grender_pivot(t_stack *a, int pivot);
int				ft_bottum_stack(t_stack *a);
int				ft_nbr_shunk(t_stack *a, int shunk);
int				ft_len_stack(t_stack *a);

///////////////////////
//	  	PRESORT		 //
///////////////////////

void			quick_sort(int *tab, int low, int high);
int				partition(int tab[], int low, int high);
int				ft_getMidlle(t_stack *a, int shunk);
void			ft_sort_integer_table(int *tab, int size);
int				ft_len_stack(t_stack *a);

void			check_error(char **argv, int argc);
void			ft_sanitize(char *str, t_data *data, t_stacks *stacks);

#endif