#include "../includes/push_swap.h"

/*   TO-DO LIST 
**   - coder les mouvememts sa sb ss...etc.
**   - algo de tri
*/

// A adapter a la nouvelle structure stack
//void	sa(t_stack *stack, int *top_stack, int *penultimate)
//{
//	if (!stack || ft_lstsize(stack) == 1)
//		return ;
//	ft_swap(top_stack, penultimate);
//	// Trouver un moyen pour afficher sa ou sb car same function
//	// Changer le nom de la fonction aussi
//	ft_putendl("sa");
//}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		char	**args;
		int		i;
		argv++;

		args = ft_parse_args(argc, argv);
		if (!args)
			return (-1);
		// --------------------INIT STACK----------------------------------
		t_stk		*a;
		t_stk_elt	*a_elt;
		t_stk_elt	*pop = NULL;
		t_stk_elt	*deq = NULL;

		a = ft_init_stack("a");
		i = 0;
		// Recup des args sur la stack a, base: 1er elt empilé; top: dernier elt empilé
		while (args[i])
		{
			a_elt = ft_init_stk_elt(ft_atol(args[i]), 1, a->stk_name);
			ft_stkadd_back(&a, a_elt);
	//		ft_stkadd_front(&a, a_elt);
			i++;
		}
		if (a->size > 0)
			ft_print_top_stack(a);
		ft_putendl("-----------------------------------------------------");
		if (a->size)
			ft_print_base_stack(a);
		// --------------------POP STACK-----------------------------------
		if (a->size > 0)
			pop = ft_pop_stack(&a);
		if (a->size > 0)
			ft_print_top_stack(a);
		// --------------------SWAP STACK----------------------------------
		if (a->size > 1)
		{
			printf("swap: %ld, %p\n", a->top->value, &a->top->value);
			printf("swap prev: %ld, %p\n", a->top->prev->value, &a->top->prev->value);
			ft_swap((&(a)->top->value), (&(a)->top->prev->value));
			printf("swap: %ld, %p\n", a->top->value, &a->top->value);
			printf("swap prev: %ld, %p\n", a->top->prev->value, &a->top->prev->value);
			if (a->base->next)
			{
				printf("base: %ld, %p\n", a->base->value, &a->base->value);
				printf("base next: %ld, %p\n", a->base->next->value, &a->base->next->value);
			}
			ft_print_top_stack(a);
		}
		ft_putendl("-----------------------------------------------------");
		if (a->size > 0)
			ft_print_base_stack(a);
		// --------------------DEQ STACK-----------------------------------
		if (a->size > 0)
		{
			deq = ft_deq_stack(&a);
			ft_putendl("--------------DEQ TEST-------------------------------");
			ft_print_top_stack(a);
			ft_putendl("-----------------------------------------------------");
			ft_print_base_stack(a);
			ft_putendl("-----------------------------------------------------");
		}
		// --------------------FREE STACK----------------------------------
		if (pop)
			ft_del_stk_elt(pop);
		if (deq)
			ft_del_stk_elt(deq);
		if (a)
			ft_pop_clear_stk(&a);
			//ft_deq_clear_stk(&a);
		// --------------------MEDIAN--------------------------------------
		t_piv	pivot;

		pivot = ft_get_median(argc, argv, args);
		// --------------------DISPLAY-------------------------------------
		printf("\033[36;1mmin: %ld, q1: %ld, me: %ld, q3: %ld, max: %ld\033[0m\n", pivot.min, pivot.q1, pivot.me, pivot.q3, pivot.max);
		i = 0;
		ft_putendl("Tableau args trié");
		while (args[i])
		{
			ft_putendl(args[i++]);
		}
		// --------------------FREE ARGS-----------------------------------
		// On free le tableau genere par split
		ft_free_args(argc, argv, args);
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
