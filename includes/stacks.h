/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:24:47 by moabid            #+#    #+#             */
/*   Updated: 2022/05/14 13:25:49 by moabid           ###   ########.fr       */
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

typedef struct 		s_stack
{
	int				value;
	struct s_stack	*next;	
}					t_stack;

typedef struct		s_data
{
	int				*tab;
	int				argc;
	int				aveg;
}					t_data;

typedef struct 		s_stacks
{
	t_stack			*a;
	t_stack			*b;
}					t_stacks;

void	ft_error();
int 	*parsing(t_data *data, char **argv, int argc);
void	printer(t_stack *head);
t_stack	*new_node(char *argv);
void	*ft_malloc(size_t size);
void	ft_insert_back(t_stack **lst, t_stack *new);
t_stack	*stacklast(t_stack *lst);
void	ft_init_stacks(t_data *data, t_stacks *stacks);
t_stack	*ft_create_stack(int *tab, int count);
void	ft_insert_front(t_stack **lst, t_stack *new);
int		average(int num, int *tab);


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

int	solve(t_data *data, t_stacks *stack);


#endif