/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alellouc <alellouc@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:08:02 by alellouc          #+#    #+#             */
/*   Updated: 2021/09/20 22:08:18 by alellouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(char *s)
{
	long	atol;
	int		polarity;
	int		sign;

	polarity = 1;
	sign = 0;
	atol = 0;
	while (ft_isspace(*s))
		s++;
	while (*s == 43 || *s == 45)
	{
		if (*s == 45)
			polarity *= -1;
		sign++;
		s++;
	}
	if (sign > 1)
		return 0;
	while (ft_isdigit(*s))
	{
		atol = atol * 10 + (*s - 48);
		s++;
	}
	atol *= polarity;
	return ((long)atol);
}
