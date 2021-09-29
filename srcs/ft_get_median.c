/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_median.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alellouc <alellouc@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 18:02:25 by alellouc          #+#    #+#             */
/*   Updated: 2021/09/29 13:09:38 by alellouc         ###   ########.fr       */
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
	ft_qsort_tab((void **)p_args, 0, end, (int (*) (void *, void *)) ft_lnbrcmp);
	pivot.min = ft_atol(p_args[0]);
	pivot.me = ft_atol(p_args[end / 2]);
	pivot.q1 = ft_atol(p_args[end / 4]);
	pivot.q3 = ft_atol(p_args[(3 * end) / 4]);
	pivot.max = ft_atol(p_args[end]);
	return (pivot);
}
