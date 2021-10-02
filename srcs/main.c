#include "../includes/push_swap.h"

/*   TO-DO LIST 
**   - algo de tri
**   - improve parsing
**   - norminette
**   - stk_elt->grp
*/

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
					// Mets la valeur de grp à la pos triée
					tmp->grp = i;
					break ;
				}
				else
					tmp = tmp->prev;
			}
			i++;
		}

		// --------------------ALGORITHM-----------------------------------
		ft_sort_three(a);
		ft_print_top_stack(a);
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
