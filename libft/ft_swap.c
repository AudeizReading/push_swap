/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alellouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 13:22:30 by alellouc          #+#    #+#             */
/*   Updated: 2021/09/23 13:23:19 by alellouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap(void *a, void *b)
{
	unsigned char	*tmp;
	unsigned char	*p_a;
	unsigned char	*p_b;

	p_a = (unsigned char *)a;
	p_b = (unsigned char *)b;
	tmp = malloc(sizeof(*tmp) * ft_strlen((char *)p_a));
	*tmp = *p_a;
	*p_a = *p_b;
	*p_b = *tmp;
	free(tmp);
}
