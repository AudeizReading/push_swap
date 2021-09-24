/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alellouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 13:22:30 by alellouc          #+#    #+#             */
/*   Updated: 2021/09/24 10:38:49 by alellouc         ###   ########.fr       */
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
	tmp = malloc(sizeof(*tmp));
	*tmp = *p_a;
	*p_a = *p_b;
	*p_b = *tmp;
	free(tmp);
}

void	ft_swap_tab(void *tab[], int a, int b)
{
	void	*tmp;

	tmp = tab[a];
	tab[a] = tab[b];
	tab[b] = tmp;
}
