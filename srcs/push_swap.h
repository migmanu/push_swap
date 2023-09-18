/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:32:20 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/09/15 19:53:35 by migmanu          ###   ########.fr       */
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
}	t_stk;

typedef enum e_bool
{
	false,
	true
}	t_bool;

# define FALSE false
# define TRUE true

// control_args.c
t_bool	check_str(char *str);
void	check_args(int argc, char *argv[]);
void	check_if_ordered(t_stk *stk);
void	check_numbers(t_stk *stk);

// test_functions.c
void	tst_add_node_end(t_stk **stack, t_stk *new);
void	tst_print_stk(t_stk *root);
t_stk	*tst_make_stack(int n_nodes, int max, int rand);
t_stk	*tst_make_arr_stk(int *arr, int n);

//utils.c
int		vec_size(const char *s, char c);

// stk_utils.c
t_bool	stk_add_end(t_stk **stk, t_stk *new_node);
t_stk	*stk_get_last(t_stk *stk);
t_stk	*stk_get_min(t_stk *stk);
t_stk	*stk_get_max(t_stk *stk);
int		stk_cnt_nds(t_stk *stk);

// create_stack.c
t_stk	*create_stack(int argc, char **vec);

// rotation_operations.c
t_bool	rotate(t_stk **stk);
t_bool	rev_rotate(t_stk **stk);
t_bool	sync_rotate(t_stk **stk_a, t_stk **stk_b);
t_bool	sync_rev_rotate(t_stk **stk_a, t_stk **stk_b);

// push_operations.c
void	push(t_stk **src, t_stk **dest);

// simulate.c
t_stk	*find_cheapest(t_stk *stk_a, t_stk *stk_b);
int		get_unsync_cst(t_stk *stk_a, t_stk *stk_b, t_stk *node, t_stk *prev);
int		get_sync_cst(t_stk *stk_a, t_stk *stk_b, t_stk *node, t_stk *prev);
int		get_rev_rot_cost(t_stk *stk, t_stk *node);
int		get_rot_cost(t_stk *stk, t_stk *node);

// simulate_utils.c
t_stk	*get_previous(t_stk *stk, t_stk *node);

// sync_rotations.c
void	do_sync_rotate(t_stk **stk_a, t_stk **stk_b, t_stk *nd_a, t_stk *nd_b);
void	do_sync_r_rot(t_stk **stk_a, t_stk **stk_b, t_stk *nd_a, t_stk *nd_b);
t_bool	sync_r_or_rr(t_stk *stk_a, t_stk *stk_b, t_stk *nd_a, t_stk *nd_b);
void	sync_to_top(t_stk **stk_a, t_stk **stk_b, t_stk *nd_a, t_stk *nd_b);

// unsync_rotations.c
void	write_n_rotate(t_stk **stk, t_stk *node, int toggle);
void	write_n_rev_rotate(t_stk **stk, t_stk *node, int toggle);
void	unsync_to_top(t_stk **stk_a, t_stk **stk_b, t_stk *nd_a, t_stk *nd_b);

// run_push_swap.c
t_stk	*push_two(t_stk **stk_a);
t_bool	run_push_swap(t_stk **stk_a);

// swap_operations.c
void	swap(t_stk **stk);

// solve_three.c
void	solve_three(t_stk **stk);

// push_to_stk_a.c
t_stk	*get_previous_in_a(t_stk *stk, t_stk *node);
void	push_to_stk_a(t_stk **stk_a, t_stk **stk_b);

// cleaning.c
t_bool	free_stk(t_stk *stk);
void	free_vector(int argc, char *argv[]);

#endif
