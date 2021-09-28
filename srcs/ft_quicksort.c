/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alellouc <alellouc@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 18:21:01 by alellouc          #+#    #+#             */
/*   Updated: 2021/09/28 19:38:35 by alellouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// garder les coms, le temps que le tri soit efficace
void	ft_qsort_tab(void *tab[], int l, int r, int (*cmp)(void *, void *))
{
	int	i;
	int	last;

	if (l >= r)
		return ;
	ft_swap_tab(tab, l, (l + r) / 2);
	last = l;
	i = l + 1;
//	printf("Avant le tri elt last: %d %s, swap avec elt i: %d %s (not yet)\n", last, tab[last], i, tab[i]);
	while (i <= r)
	{
		//	printf("Avant le swap elt last: [%d] %s, swap avec elt i: [%d] %s\n", last, tab[last], i, tab[i]);
		if ((*cmp)(tab[i], tab[l]) < 0)
		{
		//	printf("Avant le tri elt last: [%d] %s, swap avec elt i: [%d] %s\n", last, tab[last], i, tab[i]);
			// swap ici
			ft_swap_tab(tab, ++last, i);
			// fin de swap
		//	printf("Après le swap elt last: [%d] %s, swap avec elt i: [%d] %s\n", last, tab[last], i, tab[i]);
		//	int	j = 0;
		//	while (j <= r)
		//	{
		//		ft_putstr((char *)tab[j]);
		//		ft_putchar('\n');
		//		j++;
		//	}
		}
		//printf("Après le swap elt last: [%d] %s, swap avec elt i: [%d] %s\n", last, tab[last], i, tab[i]);
		//int	j = 0;
		//while (j <= r)
		//{
		//	ft_putstr((char *)tab[j]);
		//	ft_putchar('\n');
		//	j++;
		//}
		i++;
	}
	ft_swap_tab(tab, l, last);
	ft_qsort_tab(tab, l, last - 1, cmp);
	ft_qsort_tab(tab, last + 1, r, cmp);
}
