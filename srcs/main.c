#include "../includes/push_swap.h"

/*   TO-DO LIST 
**   - algo de tri
**   - norminette
**   - stk_elt->grp
*/

// Ce n'est pas obligé de set la pos - c'est juste pour le moment
// Sinon cette fn permet de recalculer la mediane
// Penser a la renommer si je ne m'en sers pas pour les positions
t_piv	ft_set_pos_elt_stk(t_stk **stack, char **args)
{
	int			i;
	t_stk_elt	*tmp;
	t_piv		pivot;

	pivot = ft_get_median(args, (*stack)->size);
	i = 0;
	while (args[i])
	{
		tmp = (*stack)->top;
		while (tmp)
		{
			if (ft_atol(args[i]) == tmp->value)
			{
				tmp->grp = i;
				break ;
			}
			else
				tmp = tmp->prev;
		}
		i++;
	}
	return (pivot);
}

t_stk	*ft_tab_to_stack(char **args)
{
	t_stk		*a;
	t_stk_elt	*a_elt;
	int			i;

	a = ft_init_stack("a");
	if (!a)
	{
		ft_free_args(args);
		return (NULL);
	}
	i = 0;
	while (args[i])
	{
		a_elt = ft_init_stk_elt(ft_atol(args[i++]), 0, a->stk_name);
		if (!a_elt)
		{
			ft_pop_clear_stk(&a);
			return (NULL);
		}
		ft_stkadd_front(&a, a_elt);
	}
	return (a);
}

/*t_bool	ft_sort_top_prev(t_stk *stack)
{
	long	top;
	long	prev;

	if (!stack || stack->size < 2)
		return (e_false);
	top = stack->top->value;
	prev = stack->top->prev->value;
	if (top > prev)
	{
		if (!ft_strcmp(stack->stk_name, "a"))
		{
			ft_swap_stack(stack);
			return (e_true);
		}
		else if (!ft_strcmp(stack->stk_name, "b"))
			return (e_true);
	}
	return (e_false);
}

t_bool	ft_sort_prev_top(t_stk *stack)
{
	long	top;
	long	prev;

	if (!stack || stack->size < 2)
		return (e_false);
	top = stack->top->value;
	prev = stack->top->prev->value;
	if (prev > top)
	{
		if (!ft_strcmp(stack->stk_name, "b"))
		{
			ft_swap_stack(stack);
			return (e_true);
		}
		else if (!ft_strcmp(stack->stk_name, "a"))
			return (e_true);
	}
	return (e_false);
}

t_bool	ft_sort_two(t_stk *stack, int grp)
{
	if (!stack || stack->size < 2)
		return (e_false);
	if (ft_sort_top_prev(stack) || ft_sort_prev_top(stack))
	{
		stack->top->grp = grp;
		stack->top->prev->grp = grp;
		return (e_true);
	}
	return (e_false);
}*/

void	ft_parse_stack_a(t_stk *a, t_stk *b, int grp)
{
	int		size;
	char	**args;
	t_piv	pivot;

	size = a->size;
	args = ft_stack_to_tab(a);
	pivot = ft_get_median(args, a->size);
	while (size--)
	{
		if (a->top->value >= pivot.me)
			ft_rotate_stack(&a);
		else if (a->top->value < pivot.me)
		{
			ft_push_stack(&a, &b);
			b->top->grp = grp;
		}
		else if (a->base->value < pivot.me)
		{
			ft_rotate_reverse_stack(&a);
			ft_push_stack(&a, &b);
			b->top->grp = grp;
		}
	}
	ft_free_args(args);
}

void	ft_divide_stack_a(t_stk *a, t_stk *b)
{
	static int	grp = 1;

	if (!a)
		return ;
	if (a->size > 3)
	{
		ft_parse_stack_a(a, b, grp);
		grp++;
		ft_divide_stack_a(a, b);
	}
	else if (a->size == 2)
		ft_sort_two(a, -1);
	else
		ft_sort_three(a);
}


// Trie jusqu'a 6 elts
void	ft_sort_five(t_stk *a, t_stk *b)
{
	ft_divide_stack_a(a, b);
	if (b->size == 2)
		ft_sort_two(b, -1);
	else if (b->size == 3)
		ft_sort_three(b);
	while (b->size)
		ft_push_stack(&b, &a);
}/**/
// Si la liste est deja triee en entree -> return 0
int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		char	**args;
		int		i;
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
		// --------------------MEDIAN--------------------------------------
		t_piv	pivot;

		pivot = ft_set_pos_elt_stk(&a, args);
		// --------------------DISPLAY-------------------------------------
		printf("\033[36;1mmin: %ld, q1: %ld, me: %ld, q3: %ld, max: %ld\033[0m\n", pivot.min, pivot.q1, pivot.me, pivot.q3, pivot.max);

		// --------------------ALGORITHM-----------------------------------
	//	ft_sort_two(a, -1);
//		ft_sort_three(a);
		ft_print_top_stack(a);
	//	ft_sort_five(a, b);
		ft_divide_stack_a(a, b);
		if (a->size)
			ft_print_top_stack(a);
		if (b->size)
			ft_print_top_stack(b);
		// --------------------FREE STACK----------------------------------
		if (a)
			ft_pop_clear_stk(&a);
		if (b)
			ft_pop_clear_stk(&b);
		// --------------------FREE ARGS-----------------------------------
		// On free le tableau genere par split
		// Et on free le tableau genere pour la mediane

		ft_free_args(args);
		i = 0;
	}
	else
	{
		// --------------------DISPLAY-------------------------------------
		// only give the prompt back, display nothing if no arg
		ft_puterr();
		return (0);
		// ----------------------------------------------------------------
	}
	ft_putstr("---------------------------------------\n");
	return (0);
}
