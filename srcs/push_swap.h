/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:32:20 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/08/25 15:54:43 by migmanu          ###   ########.fr       */
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

t_bool	check_str(char *str, int toggle);
t_bool	check_args(int argc, char *argv[]);
void	check_numbers(t_stack *stk);

void	tst_add_node_end(t_stack **stack, t_stack *new);
t_stack	*tst_make_stack(int n_nodes, int max, int rand);

int		vec_size(const char *s, char c);

t_stack	*stk_get_last(t_stack *stk);
t_bool	stk_add_end(t_stack **stk, t_stack *new_node);
t_stack	*stk_get_min(t_stack *stk);
t_stack	*stk_get_max(t_stack *stk);

t_stack	*create_stack(int argc, char **vec);
void	tst_print_stack(t_stack *root);

#endif
