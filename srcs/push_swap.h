/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:32:20 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/09/10 18:45:01 by migmanu          ###   ########.fr       */
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

t_bool	check_str(char *str, int toggle);
t_bool	check_args(int argc, char *argv[]);
void	check_numbers(t_stk *stk);

void	tst_add_node_end(t_stk **stack, t_stk *new);
void	tst_print_stk(t_stk *root);
t_stk	*tst_make_stack(int n_nodes, int max, int rand);
t_stk	*tst_make_arr_stk(int *arr, int n);

int		vec_size(const char *s, char c);

t_bool	stk_add_end(t_stk **stk, t_stk *new_node);
t_stk	*stk_get_last(t_stk *stk);
t_stk	*stk_get_min(t_stk *stk);
t_stk	*stk_get_max(t_stk *stk);
int		stk_cnt_nds(t_stk *stk);

t_stk	*create_stack(int argc, char **vec);

t_stk	*rotate(t_stk *stk);
t_stk	*rev_rotate(t_stk *stk);
t_stk	*get_previous(t_stk *stk, t_stk *node);
int		rot_to_top(t_stk *(*f) (t_stk *), t_stk *stk, t_stk *node);

t_stk	*find_cheapest(t_stk *stk_a, t_stk *stk_b);
int		get_sync_cst(t_stk *stk_a, t_stk *stk_b, t_stk *node);
int		get_rev_rot_cost(t_stk *stk, t_stk *node);
int		get_rot_cost(t_stk *stk, t_stk *node);

void	push(t_stk **src, t_stk **dest);

t_stk	*find_cheapest(t_stk *stk_a, t_stk *stk_b);
int		get_unsync_cst(t_stk *stk_a, t_stk *stk_b, t_stk *node);
int		get_sync_cst(t_stk *stk_a, t_stk *stk_b, t_stk *node);
int		get_rev_rot_cost(t_stk *stk, t_stk *node);
int		get_rot_cost(t_stk *stk, t_stk *node);

#endif
