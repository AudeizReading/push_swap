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

void	ft_parse_stack_a(t_stk *a, t_stk *b, int grp)
{
	int		size;
	char	**args;
	t_piv	pivot;

	size = a->size;
	args = ft_stack_to_tab(a);
	pivot = ft_get_median(args, size);
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

//void	ft_divide_stack_a(t_stk *a, t_stk *b)
int	ft_divide_stack_a(t_stk *a, t_stk *b)
{
	static int	grp = 1;

	if (!a)
		return (grp);
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
	return (grp);
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
}
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
	//	ft_sort_two(a, -1);
//		ft_sort_three(a);
		ft_print_top_stack(a);
	//	ft_sort_five(a, b);
		printf("retour divide stack a, grp: %d\n", ft_divide_stack_a(a, b));
		ft_push_stack(&b, &a);
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
	ft_putstr("---------------------------------------\n");
	return (0);
}
