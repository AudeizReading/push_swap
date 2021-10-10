/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_median.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alellouc <alellouc@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 18:02:25 by alellouc          #+#    #+#             */
/*   Updated: 2021/10/10 17:50:14 by alellouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Warn: definitely sort args in croissant order */
t_piv	ft_get_median(char **args, int end)
{
	t_piv	pivot;
	char	**p_args;

	p_args = args;
	end--;
	if (end < 0)
		end = 0;
//	else 
//		end--;
	ft_qsort_tab((void **)p_args, 0, end, (int (*) (void *, void *)) ft_lnbrcmp);
	pivot.min = ft_atol(p_args[0]);
//	if (end > 3)
//		pivot.q1 = ft_atol(p_args[0]);
//	else
//		pivot.q1 = ft_atol(p_args[end]);
	pivot.q1 = ft_atol(p_args[end / 100]);
	pivot.me = ft_atol(p_args[end / 2]);
	pivot.q3 = ft_atol(p_args[(92115 * end) / 100000]);
	//pivot.q3 = ft_atol(p_args[end]);
	pivot.max = ft_atol(p_args[end]);
//	pivot.q1 = ft_atol(p_args[2]);
//	pivot.q3 = ft_atol(p_args[end - 1]);
//	printf("end %d\n", end);
/*	if (end > 3)
	{
	//	end /= 3;
	//	pivot.q1 = ft_atol(p_args[end/2]);
		//pivot.q3 = ft_atol(p_args[end]);
	//	pivot.q1 = ft_atol(p_args[end / 30]);
	//	pivot.q3 = ft_atol(p_args[(20 * end) / 30]);
	//	pivot.q1 = ft_atol(p_args[end / 4]);
	//	pivot.q3 = ft_atol(p_args[(3 * end) / 4]);
		pivot.q1 = ft_atol(p_args[2]);
		pivot.q3 = ft_atol(p_args[end - 1]);
	}
	else
	{
		pivot.q1 = ft_atol(p_args[0]);
		pivot.q3 = ft_atol(p_args[end]);
		//pivot.q1 = ft_atol(p_args[end / 30]);
		//pivot.q3 = ft_atol(p_args[(20 * end) / 30]);
//		pivot.q1 = ft_atol(p_args[end / 4]);
//		pivot.q3 = ft_atol(p_args[(3 * end) / 4]);
	}
	//pivot.q1 = ft_atol(p_args[2]);
	//pivot.q3 = ft_atol(p_args[(end - 2)]);*/
//	printf("\033[33mend: [%d], min: [%ld], q1: [%ld], me: [%ld], q3: [%ld], max: [%ld]\033[0m\n", end, pivot.min, pivot.q1, pivot.me, pivot.q3, pivot.max);
	return (pivot);
}
