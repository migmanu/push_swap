/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:32:20 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/08/07 19:39:36 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	long			nbr;
	struct s_stack	*next;
}	t_stack;

void	do_sa(t_stack **stk_a);
void	do_sb(t_stack **stk_b);
void	do_ss(t_stack **stk_a, t_stack **stk_b);
void	do_pa(t_stack **stk_a, t_stack **stk_b);
void	do_pb(t_stack **stk_a, t_stack **stk_b);

t_stack	*ft_lstlast(t_stack *lst);

void	tst_add_node_end(t_stack **stack, t_stack *new);
t_stack	*tst_make_stack(int n_nodes);
void	tst_print_stack(t_stack **root);

#endif
