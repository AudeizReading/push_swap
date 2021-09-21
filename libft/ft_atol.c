/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alellouc <alellouc@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:08:02 by alellouc          #+#    #+#             */
/*   Updated: 2021/09/20 22:33:15 by alellouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(char *s)
{
	long	atol;
	int		polarity;

	polarity = 1;
	atol = 0;
	while (ft_isspace(*s))
		s++;
	if (!ft_has_valid_sign_ato(&s, &polarity))
		return (0);
	while (ft_isdigit(*s))
	{
		atol = atol * 10 + (*s - 48);
		s++;
	}
	atol *= polarity;
	return ((long)atol);
}
