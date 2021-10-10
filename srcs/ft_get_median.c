/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_median.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alellouc <alellouc@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 18:02:25 by alellouc          #+#    #+#             */
/*   Updated: 2021/10/10 18:01:47 by alellouc         ###   ########.fr       */
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
	pivot.q1 = ft_atol(p_args[end / 4]);
	pivot.me = ft_atol(p_args[end / 2]);
	pivot.q3 = ft_atol(p_args[(92115 * end) / 100000]);
	pivot.max = ft_atol(p_args[end]);
	return (pivot);
}
