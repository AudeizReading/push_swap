#include "../includes/push_swap.h"

/*   TO-DO LIST 
**   - algo de tri
**   - improve parsing
**   - norminette
**   - stk_elt->grp
*/

/* 1 2 3 */
t_bool	ft_sort_top_mid_base(t_stk *stack)
{
	long	top;
	long	mid;
	long	base;

	if (!stack || stack->size < 3)
		return (e_false);
	top = stack->top->value;
	mid = stack->top->prev->value;
	base = stack->top->prev->prev->value;
	if (top < mid && top < base && mid < base)
	{
		if (ft_strcmp(stack->stk_name, "a"))
			return (e_true);
		else if (ft_strcmp(stack->stk_name, "b"))
		{
			ft_swap_stack(stack);
			ft_rotate_reverse_stack(&stack);
			return (e_true);
		}
	}
	return (e_false);
}

/* 3 2 1 */
t_bool	ft_sort_base_mid_top(t_stk *stack)
{
	long	top;
	long	mid;
	long	base;

	if (!stack || stack->size < 3)
		return (e_false);
	top = stack->top->value;
	mid = stack->top->prev->value;
	base = stack->top->prev->prev->value;
	if (top > mid && top > base && mid > base)
	{
		if (ft_strcmp(stack->stk_name, "b"))
			return (e_true);
		else if (ft_strcmp(stack->stk_name, "a"))
		{
			ft_swap_stack(stack);
			ft_rotate_reverse_stack(&stack);
			return (e_true);
		}
	}
	return (e_false);
}

/* 2 3 1 */
t_bool	ft_sort_mid_base_top(t_stk *stack)
{
	long	top;
	long	mid;
	long	base;

	if (!stack || stack->size < 3)
		return (e_false);
	top = stack->top->value;
	mid = stack->top->prev->value;
	base = stack->top->prev->prev->value;
	if (top < mid && top > base && mid > base)
	{
		if (ft_strcmp(stack->stk_name, "a"))
		{
			ft_rotate_stack(&stack);
			return (e_true);
		}
		else if (ft_strcmp(stack->stk_name, "b"))
		{
			ft_swap_stack(stack);
			return (e_true);
		}
	}
	return (e_false);
}

/* 2 1 3 */
t_bool	ft_sort_mid_top_base(t_stk *stack)
{
	long	top;
	long	mid;
	long	base;

	if (!stack || stack->size < 3)
		return (e_false);
	top = stack->top->value;
	mid = stack->top->prev->value;
	base = stack->top->prev->prev->value;
	if (top > mid && top < base && mid < base)
	{
		if (ft_strcmp(stack->stk_name, "b"))
		{
			ft_rotate_stack(&stack);
			return (e_true);
		}
		else if (ft_strcmp(stack->stk_name, "a"))
		{
			ft_swap_stack(stack);
			return (e_true);
		}
	}
	return (e_false);
}

/* 1 3 2 */
t_bool	ft_sort_top_base_mid(t_stk *stack)
{
	long	top;
	long	mid;
	long	base;

	if (!stack || stack->size < 3)
		return (e_false);
	top = stack->top->value;
	mid = stack->top->prev->value;
	base = stack->top->prev->prev->value;
	if (top < mid && top < base && mid > base)
	{
		if (ft_strcmp(stack->stk_name, "a"))
		{
			ft_rotate_reverse_stack(&stack);
			ft_swap_stack(stack);
			return (e_true);
		}
		else if (ft_strcmp(stack->stk_name, "b"))
		{
			ft_rotate_stack(&stack);
			return (e_true);
		}
	}
	return (e_false);
}

/* 3 1 2 */
t_bool	ft_sort_base_top_mid(t_stk *stack)
{
	long	top;
	long	mid;
	long	base;

	if (!stack || stack->size < 3)
		return (e_false);
	top = stack->top->value;
	mid = stack->top->prev->value;
	base = stack->top->prev->prev->value;
	if (top > mid && top > base && mid < base)
	{
		if (ft_strcmp(stack->stk_name, "b"))
		{
			ft_rotate_reverse_stack(&stack);
			ft_swap_stack(stack);
			return (e_true);
		}
		else if (ft_strcmp(stack->stk_name, "a"))
		{
			ft_rotate_stack(&stack);
			return (e_true);
		}
	}
	return (e_false);
}

void	ft_sort_three(t_stk *stack)
{
/*	long	top;
	long	mid;
	long	base;*/
	t_bool	cond_1;
	t_bool	cond_2;
	t_bool	cond_3;

	if (!stack || stack->size < 3)
		return ;
//	if (ft_sort_top_mid_base || ft_sort_base_mid_top || ft_sort_mid_base_top || ft_sort_mid_top_base || ft_sort_top_base_mid || ft_sort_base_top_mid)
	cond_1 = ft_sort_top_mid_base(stack) || ft_sort_base_mid_top(stack);
	cond_2 = ft_sort_mid_base_top(stack) || ft_sort_mid_top_base(stack);
	cond_3 = ft_sort_top_base_mid(stack) || ft_sort_base_top_mid(stack);
	if (cond_1 || cond_2 || cond_3)
	{
		stack->top->grp = -1;
		stack->top->prev->grp = -1;
		stack->top->prev->prev->grp = -1;
	}
/*	if (stack->size > 2)
	{
		top = stack->top->value;
		mid = stack->top->prev->value;
		base = stack->top->prev->prev->value;
		// 1 2 3
		// top-mid-base
		if (top < mid && top < base && mid < base)
		{
			if (ft_strcmp(stack->stk_name, "a"))
				return ;
			else
			{
				ft_swap_stack(stack);
				ft_rotate_reverse_stack(&stack);
			}
		}
		// 3 2 1
		// base-mid-top
		if (top > mid && top > base && mid > base)
		{
			if (ft_strcmp(stack->stk_name, "b"))
				return ;
			else
			{
				ft_swap_stack(stack);
				ft_rotate_reverse_stack(&stack);
			}
		}
		// 2 3 1
		// mid-base-top
		if (top < mid && top > base && mid > base)
		{
			if (ft_strcmp(stack->stk_name, "a"))
				ft_rotate_stack(&stack);
			else
				ft_swap_stack(stack);
		}
		// 2 1 3
		// mid-top-base
		if (top > mid && top < base && mid < base)
		{
			if (ft_strcmp(stack->stk_name, "b"))
				ft_rotate_stack(&stack);
			else
				ft_swap_stack(stack);
		}
		// 1 3 2
		// top-base-mid
		if (top < mid && top < base && mid > base)
		{
			if (ft_strcmp(stack->stk_name, "a"))
			{
				ft_rotate_reverse_stack(&stack);
				ft_swap_stack(stack);
			}
			else
				ft_rotate_stack(&stack);
		}
		// 3 1 2
		// base-top-mid
		if (top > mid && top > base && mid < base)
		{
			if (ft_strcmp(stack->stk_name, "b"))
			{
				ft_rotate_reverse_stack(&stack);
				ft_swap_stack(stack);
			}
			else
				ft_rotate_stack(&stack);
		}
	}*/
}

// Si la liste est deja triee en entree -> return 0
int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		char	**args;
		int		i;
		argv++;

		// --------------------TEST PARSE ARGV-----------------------------
	/*	char	*test_argv;

		test_argv = NULL;
		i = 0;
		while (i < argc)
		{
			test_argv = ft_strjoin(test_argv, argv[i]);
			test_argv = ft_strjoin(test_argv, " ");
			i++;
		}
		//test_argv = ft_strjoin("*****", argv[0]);
	//	test_argv = ft_strjoin(test_argv, argv[0]);
	//	test_argv = ft_strjoin(test_argv, " ");
		ft_putendl("ft_strjoin argv:");
		ft_putendl(test_argv);
		ft_putendl("**********************************");*/
		// --------------------PARSE ARGV----------------------------------
		args = ft_parse_args(argc, argv);
		if (!args)
			return (-1);
		// --------------------INIT STACKS---------------------------------
		t_stk		*a;
		t_stk		*b;
		t_stk_elt	*a_elt;

		a = ft_init_stack("a");
		b = ft_init_stack("b");
		if (!a || !b)
		{
			if (a)
				ft_pop_clear_stk(&a);
			ft_free_args(args);
			return (-1);
		}
		i = 0;
		while (args[i])
		{
			a_elt = ft_init_stk_elt(ft_atol(args[i]), 0, a->stk_name);
			if (!a_elt)
			{
				ft_pop_clear_stk(&a);
				ft_pop_clear_stk(&b);
				ft_free_args(args);
			}
			ft_stkadd_front(&a, a_elt);
			i++;
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

		pivot = ft_get_median(args, a->size);
		// --------------------DISPLAY-------------------------------------
		printf("\033[36;1mmin: %ld, q1: %ld, me: %ld, q3: %ld, max: %ld\033[0m\n", pivot.min, pivot.q1, pivot.me, pivot.q3, pivot.max);
		i = 0;
	//	ft_putendl("Tableau args trié");
		while (args[i])
		{
		//	ft_putendl(args[i]);
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

		// --------------------ALGORITHM-----------------------------------
/*		int		size;
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
			t_stk_elt	*tmp;

		//	printf("\033[33m%s\033[0m\n", test_stack[i]);
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
		pivot = ft_get_median(test_stack, a->size);
	//	printf("\033[33;1mmin: %ld, q1: %ld, me: %ld, q3: %ld, max: %ld\033[0m\n", pivot.min, pivot.q1, pivot.me, pivot.q3, pivot.max);
		if (a->size)
		//	ft_print_top_stack(a);
			ft_print_top_base_stack(a);
		if (b->size)
			ft_print_top_stack(b);
		// Attention segfault si reste qu 1 elt dans stack a
		while (size--)
		{
			top = a->top->value;
			prev = a->top->prev->value;
			printf("me: %ld, top: %ld\n", pivot.me, top);
			if (top <= pivot.me)
			{
				if (top > prev)
				{
					ft_swap_stack(a);
					ft_push_stack(&a, &b);
				}
				ft_push_stack(&a, &b);
			}
			else
			{
				if (top > prev)
				{
					ft_swap_stack(a);
					size++;
				}
				else
					ft_rotate_stack(&a);
			}
		}
		if (a->size)
			ft_print_top_stack(a);
		if (b->size)
			ft_print_top_stack(b);*/
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
	/*	while (test_stack[i])
		{
			free(test_stack[i]);
			i++;
		}
		free(test_stack);*/
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
