/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:41:02 by migmanu           #+#    #+#             */
/*   Updated: 2023/09/12 20:19:40 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve_three(t_stk **stk)
{
	t_stk	*max;
	t_stk	*min;

	max = stk_get_max(*stk);
	min = stk_get_min(*stk);
	if (min->next == max)
	{
		write(1, "sa\n", 3);
		swap(stk);
	}
	if (*stk == max && max->next != min)
	{
		write(1, "sa\n", 3);
		swap(stk);
	}
}
/*
int	main(void)
{
	int	arr1[] = {1, 2, 3};
	t_stk	*stk1 = tst_make_arr_stk(arr1, 3);
	printf("arr1\n");
	solve_three(&stk1);
	tst_print_stk(stk1);

	int	arr2[] = {1, 3, 2};
	t_stk	*stk2 = tst_make_arr_stk(arr2, 3);
	printf("arr2\n");
	solve_three(&stk2);
	tst_print_stk(stk2);

	int	arr3[] = {2, 1, 3};
	t_stk	*stk3 = tst_make_arr_stk(arr3, 3);
	printf("arr3\n");
	solve_three(&stk3);
	tst_print_stk(stk3);

	int	arr4[] = {2, 3, 1};
	t_stk	*stk4 = tst_make_arr_stk(arr4, 3);
	printf("arr4\n");
	solve_three(&stk4);
	tst_print_stk(stk4);

	int	arr5[] = {3, 1, 2};
	t_stk	*stk5 = tst_make_arr_stk(arr5, 3);
	printf("arr5\n");
	solve_three(&stk5);
	tst_print_stk(stk5);

	int	arr6[] = {3, 2, 1};
	t_stk	*stk6 = tst_make_arr_stk(arr6, 3);
	printf("arr6\n");
	solve_three(&stk6);
	tst_print_stk(stk6);
}*/
