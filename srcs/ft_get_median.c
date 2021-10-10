/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_median.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alellouc <alellouc@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 18:02:25 by alellouc          #+#    #+#             */
/*   Updated: 2021/10/10 21:14:00 by alellouc         ###   ########.fr       */
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
	ft_qsort_tab((void **)p_args, 0, end, (int (*) (void *, void *)) ft_lnbrcmp);
	pivot.min = ft_atol(p_args[0]);
	pivot.q1 = ft_atol(p_args[(1 * end) / 7]);
	pivot.q3 = ft_atol(p_args[(5 * end) / 7]);
	pivot.me = ft_atol(p_args[end / 2]);
	pivot.max = ft_atol(p_args[end]);
	// rendement 1/7 5/7 950 8300
	// rendement 3/14 11/14 855 9600
	// rendement 3/13 5/7 840 9000
	return (pivot);
}
