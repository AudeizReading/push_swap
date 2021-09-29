#include "../includes/push_swap.h"

/*   TO-DO LIST 
**   - coder les mouvememts sa sb ss...etc.
**   - algo de tri
*/

void	ft_swap_stack(t_stk *stack)
{
	if (!stack || stack->size < 2)
		return ;
	ft_swap(&stack->top->value, &stack->top->prev->value);
	ft_swap(&stack->top->grp, &stack->top->prev->grp);
	if (!ft_strcmp(stack->stk_name, "a"))
		ft_putendl("sa");
	else if (!ft_strcmp(stack->stk_name, "b"))
		ft_putendl("sb");
}

void	ss(t_stk *a, t_stk *b)
{
	ft_swap_stack(a);
	ft_swap_stack(b);
}

void	ft_push_stack(t_stk **stack_1, t_stk **stack_2)
{
	t_stk_elt	*p_stack;

	if ((*stack_1)->size > 0)
	{
		p_stack = ft_pop_stack(stack_1);
		p_stack->stack_name = ft_strdup((*stack_2)->stk_name);
		// Groupe ?
		ft_stkadd_back(stack_2, p_stack);
		if (!ft_strcmp((*stack_2)->stk_name, "a"))
			ft_putendl("pa");
		else if (!ft_strcmp((*stack_2)->stk_name, "b"))
			ft_putendl("pb");
	}
}

void	ft_rotate_stack(t_stk **stack)
{
	t_stk_elt	*p_stack;

	if ((*stack)->size > 1)
	{
		p_stack = ft_pop_stack(stack);
		// Groupe ?
		p_stack->stack_name = ft_strdup((*stack)->stk_name);
		ft_stkadd_front(stack, p_stack);
		if (!ft_strcmp((*stack)->stk_name, "a"))
			ft_putendl("ra");
		else if (!ft_strcmp((*stack)->stk_name, "b"))
			ft_putendl("rb");
	}
}

void	rr(t_stk **a, t_stk **b)
{
	ft_rotate_stack(a);
	ft_rotate_stack(b);
}

void	ft_rotate_reverse_stack(t_stk **stack)
{
	t_stk_elt	*p_stack;

	if ((*stack)->size > 1)
	{
		p_stack = ft_deq_stack(stack);
		// Groupe ?
		p_stack->stack_name = ft_strdup((*stack)->stk_name);
		ft_stkadd_back(stack, p_stack);
		if (!ft_strcmp((*stack)->stk_name, "a"))
			ft_putendl("rra");
		else if (!ft_strcmp((*stack)->stk_name, "b"))
			ft_putendl("rrb");
	}
}

void	rrr(t_stk **a, t_stk **b)
{
	ft_rotate_reverse_stack(a);
	ft_rotate_reverse_stack(b);
}

void	ft_print_top_base_stack(t_stk *a)
{
	if (a->size > 0)
	{
		ft_putendl("---------TOP STACK-----------------------------------");
		ft_print_top_stack(a);
		ft_putendl("---------BASE STACK-----------------------------------");
		ft_print_base_stack(a);
		ft_putendl("-----------------------------------------------------");
	}
}

char	**ft_stack_to_tab(t_stk *stack)
{
	char		**dst;
	t_stk_elt	*tmp;
	int			i;

	if (!stack)
		return (NULL);
	i = 0;
	dst = (char **)malloc(sizeof(*dst) * (stack->size + 1));
	if(!dst)
		return (NULL);
	tmp = stack->top;
	while (tmp)
	{
		dst[i] = ft_ltoa(tmp->value);
		if (!dst[i])
		{
			while (dst[i--])
				free(dst[i]);
			free(dst);
		}
		i++;
		tmp = tmp->prev;
	}
	dst[i] = NULL;
	return (dst);
}

t_bool	ft_stack_a_is_sort(t_stk *stack)
{
	t_stk_elt	*tmp;

	if (!stack)
		return (e_false);
	tmp = stack->top;
	while (tmp->prev)
	{
		if (tmp->value > tmp->prev->value)
			return (e_false);
		tmp = tmp->prev;
	}
	return (e_true);
}

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
		// --------------------INIT STACK----------------------------------
		t_stk		*a;
		t_stk		*b;
		t_stk_elt	*a_elt;

		a = ft_init_stack("a");
		b = ft_init_stack("b");
		i = 0;
		while (args[i])
		{
			a_elt = ft_init_stk_elt(ft_atol(args[i]), 1, a->stk_name);
			ft_stkadd_front(&a, a_elt);
			i++;
		}
		// --------------------QUIT IF STACK SIZE < 2----------------------
		// --------------------CHECK A IS SORTED---------------------------
		if (a->size < 2 || ft_stack_a_is_sort(a))
		{
			ft_pop_clear_stk(&a);
			ft_pop_clear_stk(&b);
			ft_free_args(argc, argv, args);
			return (0);
		}
		// --------------------TEST STACK----------------------------------
	//	ft_print_top_base_stack(a);
	//	ft_swap_stack(a);
	//	ft_print_top_base_stack(a);

	//	ft_push_stack(&a, &b);
	//	ft_print_top_base_stack(a);
	//	ft_print_top_base_stack(b);

	//	ft_push_stack(&a, &b);
	//	ft_push_stack(&a, &b);
	//	ft_print_top_base_stack(a);
	//	ft_print_top_base_stack(b);

	//	ft_rotate_stack(&b);
	//	ft_rotate_reverse_stack(&a);
	//	ft_rotate_reverse_stack(&a);
	//	ft_print_top_base_stack(a);
	//	ft_print_top_base_stack(b);

	//	rrr(&a, &b);
	//	rrr(&a, &b);
	//	ss(a, b);
	//	rr(&a, &b);
	//	ft_print_top_base_stack(a);
	//	ft_print_top_base_stack(b);
		// --------------------MEDIAN--------------------------------------
		t_piv	pivot;

		pivot = ft_get_median(args, a->size);
		// --------------------DISPLAY-------------------------------------
		printf("\033[36;1mmin: %ld, q1: %ld, me: %ld, q3: %ld, max: %ld\033[0m\n", pivot.min, pivot.q1, pivot.me, pivot.q3, pivot.max);
		i = 0;
		ft_putendl("Tableau args trié");
		while (args[i])
		{
			ft_putendl(args[i]);
			t_stk_elt	*tmp;
			tmp = a->top;
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

		ft_push_stack(&a, &b);
		ft_push_stack(&a, &b);
		ft_push_stack(&a, &b);
		// --------------------ALGORITHM-----------------------------------
		int		size;
		long	top;
		long	prev;

		size = a->size;
	//	ft_print_top_base_stack(a);
	//	ft_print_top_base_stack(b);
		char	**test_stack = ft_stack_to_tab(a);
		i = 0;
		// recup stack et conversion en tab de tab de char pour trouver la mediane de la stack
		while (test_stack[i])
		{
			printf("\033[33m%s\033[0m\n", test_stack[i]);
			i++;
		}
		//pivot = ft_get_median(argc, argv, test_stack);
		pivot = ft_get_median(test_stack, a->size);
		printf("\033[33;1mmin: %ld, q1: %ld, me: %ld, q3: %ld, max: %ld\033[0m\n", pivot.min, pivot.q1, pivot.me, pivot.q3, pivot.max);
		if (a->size)
			ft_print_top_stack(a);
		if (b->size)
			ft_print_top_stack(b);
		while (size--)
		//while (size)
		{
			top = a->top->value;
			prev = a->top->prev->value;
			if (top > prev)
				ft_swap_stack(a);
			else if (top < pivot.me)
			{
				ft_push_stack(&a, &b);
				//size--;
			}
			else if (top > pivot.me)
				ft_rotate_reverse_stack(&a);
			else
				ft_rotate_stack(&a);
			printf("me: %ld, top: %ld\n", pivot.me, top);
		}
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

		ft_free_args(argc, argv, args);
		i = 0;
		while (test_stack[i])
		{
			free(test_stack[i]);
			i++;
		}
		free(test_stack);
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
