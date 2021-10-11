#include "../includes/push_swap.h"

/*   TO-DO LIST 
**   - norminette
**   - leaks
**   - breaking by mates
*/

// Recupere dans une liste chainee les valeurs des diff grp crees via la stack A
// (membre grp) et le nombre d'elts par grp (membre valeur)
t_stk	*ft_get_grp_stk(t_stk *stack)
{
	t_stk		*grp;
	t_stk_elt	*elt;
	t_stk_elt	*tmp;
	
	grp = ft_init_stack("grp");
	if (!grp || !stack)
		return (NULL);
	tmp = stack->top;
	while (tmp)
	{
		if (tmp->next == NULL || tmp->grp != tmp->next->grp)
		{
			elt = ft_init_stk_elt(0, tmp->grp, grp->stk_name);
			ft_stkadd_front(&grp, elt);
		}
		grp->base->value++;
		tmp = tmp->prev;
	}
	if (!grp->size)
		return (NULL);
	return (grp);
}

// recupere le groupe dans une liste chainee afin de pouvoir en calculer la
//	mediane
t_stk	*ft_get_stk_4_med(t_stk *stack, int grp)
{
	t_stk		*stk_grp;
	t_stk_elt	*elt_grp;
	t_stk_elt	*tmp;

	if (!stack || !stack->size || !grp)
		return (NULL);
	tmp = stack->top;
	stk_grp = ft_init_stack("stk_4_med");
	if (!stk_grp)
		return (NULL);
	while (tmp)
	{
		if (tmp->grp == grp)
		{
			elt_grp = ft_init_stk_elt(tmp->value, tmp->grp, stk_grp->stk_name);
			if (!elt_grp)
			{
				ft_pop_clear_stk(&stk_grp);
				return (NULL);
			}
			ft_stkadd_front(&stk_grp, elt_grp);
		}
		tmp = tmp->prev;
	}
	if (!stk_grp->size)
		return (NULL);
	return (stk_grp);
}

void	ft_divide_stack_b(t_stk *b, t_stk *a)
{
	t_piv		pivot;
	t_stk		*info_grp;
	t_stk		*current_grp;
	char		**current_grp_tab;
	t_stk_elt	*info;
	int			size_current_grp;
	int			size;

	if (!b->size)
		return ;
	info_grp = ft_get_grp_stk(b);
	info = info_grp->top;
	current_grp = ft_get_stk_4_med(b, info->grp);
	size_current_grp = current_grp->size;
	current_grp_tab = ft_stack_to_tab(current_grp);
	pivot = ft_get_median(current_grp_tab, size_current_grp);
	size = size_current_grp;
	if (ft_stack_is_sort(b))
	{
		while (b->size)
			ft_push_stack(&b, &a);
	}
	else if ((ft_stack_is_sort(a) && !b->size))
		return ;
	else if (b->size < 4)
	{
		if (!ft_sort_three(b))
			ft_sort_two(b);
		while (b->size)
			ft_push_stack(&b, &a);
	}
	else if (b->size > 3)
	{
		if (current_grp->size > 3)
		{
			int	i;
			i = 0;
			while (size--)
			{
				if (b->top->value >= pivot.q3)
				{
					ft_push_stack(&b, &a);
					ft_sort_two(a);
				}
				else if (b->top->value < pivot.q3)
				{
					ft_rotate_stack(&b);
					b->base->grp += 1000;
					i++;
				}
				else if (b->base->value >= pivot.q3)
				{
					ft_rotate_reverse_stack(&b);
					ft_push_stack(&b, &a);
					ft_sort_two(a);
					i--;
				}
			}
			while (i-- && info->prev)
			{
				ft_rotate_reverse_stack(&b);
				ft_sort_two(b);
			}
			if (!ft_stack_is_sort(a))
			{
				while (current_grp->size > 3)
				{
					ft_pop_clear_stk(&info_grp);
					info_grp = ft_get_grp_stk(a);
					info = info_grp->top;
					ft_pop_clear_stk(&current_grp);
					current_grp = ft_get_stk_4_med(a, info->grp);
					size_current_grp = current_grp->size;
					ft_free_args(current_grp_tab);
					current_grp_tab = ft_stack_to_tab(current_grp);
					pivot = ft_get_median(current_grp_tab, size_current_grp);
					size = size_current_grp;
					i = 0;
					while (size--)
					{
						if (a->top->value <= pivot.me)
						{
							ft_push_stack(&a, &b);
							ft_sort_two(b);

						}
						else if (a->top->value > pivot.me)
						{
							ft_rotate_stack(&a);
							i++;
						}
						else if (a->base->value >= pivot.q3)
						{
							ft_rotate_reverse_stack(&a);
							ft_push_stack(&a, &b);
							ft_sort_two(b);
							i--;
						}
					}
					while (i-- && info->prev)
					{
						ft_rotate_reverse_stack(&a);
						ft_sort_two(a);
					}
				}
			}
		}
		else
		{
			if (current_grp->size == 1)
				ft_push_stack(&b, &a);
			else if (current_grp->size == 2)
			{
				ft_sort_two(b);
				ft_push_stack_nb(b, a, 2);
			//	ft_push_stack(&b, &a);
			//	ft_push_stack(&b, &a);
			}
			else
			{
				//if (ft_sort_t_p_pp(b, a) || ft_sort_t_pp_p(b, a) || ft_sort_p_pp_t(b, a) || ft_sort_p_t_pp(b, a) || ft_sort_pp_t_p(b, a) || ft_sort_pp_p_t(b, a))
				//{
				//}
				if (!ft_sort_3_elts_side_by_side(b, a))
					return ;
			}
		}
		ft_divide_stack_b(b, a);
	}
	else
		return ;

		// free elts
	if (info_grp)
		ft_pop_clear_stk(&info_grp);
	if (current_grp)
		ft_pop_clear_stk(&current_grp);
	if (current_grp_tab)
		ft_free_args(current_grp_tab);
}

void	ft_push_swap(t_stk *a, t_stk *b)
{
	ft_divide_stack_a(a, b);
	ft_divide_stack_b(b, a);
}
//	ft_putendl("\033[32;1m--------------------------------------------------------------------------------");
//	if (info_grp->size)
//		ft_print_top_stack(info_grp);
//	ft_putendl("\033[0m");
//	ft_putendl("\033[35;1m--------------------------------------------------------------------------------");
//	if (current_grp->size)
//		ft_print_top_stack(current_grp);
//	ft_putendl("\033[0m");
//	printf("\033[34;1mmin: [%ld], q1: [%ld], me [%ld], q3: [%ld], max: [%ld]\033[0m\n", pivot.min, pivot.q1, pivot.me, pivot.q3, pivot.max);
//	ft_putendl("\033[33;1m--------------------------------------------------------------------------------");
//	if (a->size)
//		ft_print_top_stack(a);
//	ft_putendl("\033[0m");
//	ft_putendl("\033[31;1m--------------------------------------------------------------------------------");
//	if (b->size)
//		ft_print_top_stack(b);
//	ft_putendl("\033[0m");
			//	ft_putendl("\033[44;37;1m--------------------------------------------------------------------------------");
			//	ft_putendl("");
			//	if (a->size)
			//		ft_print_top_stack(a);
			//	ft_putendl("");
			//	if (b->size)
			//		ft_print_top_stack(b);
			//	ft_putendl("\033[0m");
			//		ft_putendl("\033[32;1m--------------------------------------------------------------------------------");
			//		if (info_grp->size)
			//			ft_print_top_stack(info_grp);
			//		ft_putendl("\033[0m");
			//		ft_putendl("\033[35;1m--------------------------------------------------------------------------------");
			//		if (current_grp->size)
			//			ft_print_top_stack(current_grp);
			//		ft_putendl("\033[0m");
			//	printf("\033[34;1mmin: [%ld], q1: [%ld], me [%ld], q3: [%ld], max: [%ld]\033[0m\n", pivot.min, pivot.q1, pivot.me, pivot.q3, pivot.max);
			//	ft_putendl("\033[33;1m--------------------------------------------------------------------------------");
			//	if (a->size)
			//		ft_print_top_stack(a);
			//	ft_putendl("\033[0m");
			//	ft_putendl("\033[31;1m--------------------------------------------------------------------------------");
			//	if (b->size)
			//		ft_print_top_stack(b);
			//	ft_putendl("\033[0m");

// Si la liste est deja triee en entree -> return 0
int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		char	**args;

		argv++;
		// --------------------PARSE ARGV----------------------------------
		args = ft_parse_args(argc, argv);
		if (!args)
			return (-1);
		// --------------------INIT STACKS---------------------------------
		t_stk		*a;
		t_stk		*b;

		a = ft_tab_to_stack(args);
		b = ft_init_stack("b");
		if (!a || !b)
		{
			if (a)
				ft_pop_clear_stk(&a);
			ft_free_args(args);
			return (-1);
		}
		// --------------------QUIT IF STACK SIZE < 2----------------------
		// --------------------CHECK A IS SORTED---------------------------
		if (a->size < 2 || ft_stack_a_is_sort(a))
		{
			ft_pop_clear_stk(&a);
			ft_pop_clear_stk(&b);
			ft_free_args(args);
			return (0);
		}
		// --------------------ALGORITHM-----------------------------------
		ft_push_swap(a, b);
		if (a->size && ft_stack_is_sort(a))
			ft_putendl("\033[33;1m--------------------------------------------------------------------------------");
		else if (!ft_stack_is_sort(a))
			ft_putendl("\033[31;1m--------------------------------------------------------------------------------");
		ft_print_top_stack(a);
		ft_putendl("\033[0m");
		// --------------------FREE STACK----------------------------------
		if (a)
			ft_pop_clear_stk(&a);
		if (b)
			ft_pop_clear_stk(&b);
		// --------------------FREE ARGS-----------------------------------
		// On free le tableau genere par split
		ft_free_args(args);
	}
	else
	{
		// --------------------DISPLAY-------------------------------------
		// only give the prompt back, display nothing if no arg
		ft_puterr();
		return (0);
		// ----------------------------------------------------------------
	}
//	ft_putstr("---------------------------------------\n");
	return (0);
}
