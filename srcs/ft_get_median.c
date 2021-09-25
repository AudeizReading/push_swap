/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_median.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alellouc <alellouc@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 18:02:25 by alellouc          #+#    #+#             */
/*   Updated: 2021/09/25 18:06:36 by alellouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Warn: definitely sort args in croissant order */
t_piv	ft_get_median(int argc, char **argv, char **args)
{
	t_piv	pivot;
	int			begin;
	int			end;

	begin = 0;
	if (argc == 2)
		end  = ft_cntwds(*argv, 32) - 1;
	else
		end = argc - 2;
	ft_qsort_tab((void **)args, begin, end, (int (*) (void *, void *)) ft_lnbrcmp);
	pivot.min = ft_atol(args[begin]);
	pivot.me = ft_atol(args[end / 2]);
	pivot.q1 = ft_atol(args[end / 4]);
	pivot.q3 = ft_atol(args[(3 * end) / 4]);
	pivot.max = ft_atol(args[end]);
	return (pivot);
}
