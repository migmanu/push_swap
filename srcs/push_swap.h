/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:32:20 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/09/05 19:26:35 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <time.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	long			nbr;
	struct s_stack	*next;
}	t_stack;

typedef enum e_bool
{
	false,
	true
}	t_bool;

# define FALSE false
# define TRUE true

void	do_sa(t_stack **stk_a);
void	do_sb(t_stack **stk_b);
void	do_ss(t_stack **stk_a, t_stack **stk_b);
void	do_pa(t_stack **stk_a, t_stack **stk_b);
void	do_pb(t_stack **stk_a, t_stack **stk_b);
void	do_ra(t_stack **stk_a, int toggle);
void	do_rb(t_stack **stk_b, int toggle);
void	do_rr(t_stack **stk_a, t_stack **stk_b, int toggle);
void	do_rra(t_stack **stk_a, int toggle);
void	do_rrb(t_stack **stk_a, int toggle);
void	do_rrr(t_stack **stk_a, t_stack **stk_b, int toggle);

t_bool	check_str(char *str, int toggle);
t_bool	check_args(int argc, char *argv[]);
void	check_numbers(t_stack *stk);

void	tst_add_node_end(t_stack **stack, t_stack *new);
void	tst_print_stack(t_stack *root);
t_stack	*tst_make_stack(int n_nodes, int max, int rand);
t_stack	*tst_make_arr_stk(int *arr, int n);

int		vec_size(const char *s, char c);

t_bool	stk_add_end(t_stack **stk, t_stack *new_node);
t_stack	*stk_get_last(t_stack *stk);
t_stack	*stk_get_min(t_stack *stk);
t_stack	*stk_get_max(t_stack *stk);
int		stk_cnt_nds(t_stack *stk);

t_stack	*create_stack(int argc, char **vec);

t_stack	*rotate(t_stack *stk);
t_stack	*rev_rotate(t_stack *stk);
t_stack	*get_previous(t_stack *stk, t_stack *node);
int		rot_to_top(t_stack *(*f) (t_stack *), t_stack *stk, t_stack *node);

t_stack	*find_cheapest(t_stack *stk_a, t_stack *stk_b);
int		get_unsync_cst(t_stack *stk_a, t_stack *stk_b, t_stack *node);
int		get_sync_cst(t_stack *stk_a, t_stack *stk_b, t_stack *node);
int		get_rev_rot_cost(t_stack *stk, t_stack *node);
int		get_rot_cost(t_stack *stk, t_stack *node);

#endif
