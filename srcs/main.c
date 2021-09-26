#include "../includes/push_swap.h"

/*   TO-DO LIST 
**   - coder les fn gestion stack
**   - creer fn qui recup le tab d'argv en liste chainee
**   - recoder sa en fonction nv structure et adapter pr sb
**   - coder les fonction pop et push de la stack
**   -*/

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
t_stk	*ft_init_stack(char *stack_name)
{
	t_stk	*stack;

	stack = (t_stk *)malloc(sizeof(*stack));
	if (!stack)
		return (NULL);
	stack->stk_name = ft_strdup(stack_name);
	if (!stack->stk_name)
	{
		free(stack);
		return (NULL);
	}
	stack->size = 0;
	stack->top = NULL;
	stack->base = NULL;
	return (stack);
}

t_stk_elt	*ft_init_stk_elt(long value, int grp, char *stk_name)
{
	t_stk_elt	*elt;

	if (!stk_name)
		return (NULL);
	elt = (t_stk_elt *)malloc(sizeof(*elt));
	if (!elt)
		return (NULL);
	elt->stack_name = ft_strdup(stk_name);
/*	if (!elt->stack_name)
		return (NULL);*/
	elt->grp = grp;
	elt->value = value;
	elt->prev = NULL;
	elt->next = NULL;
	return (elt);
}

void	ft_print_top_stack(t_stk *stack)
{
	t_stk_elt	*tmp;

	tmp = stack->top;
	ft_putstr("size ");
	ft_putnbr(stack->size);
	ft_putstr(" name ");
	ft_putendl(stack->stk_name);
	ft_putstr("top ");
	ft_putlnbr(stack->top->value);
	ft_putstr(" base ");
	ft_putlnbr(stack->base->value);
	ft_putchar('\n');
	while (tmp)
	{
		ft_putlnbr(tmp->value);
		ft_putchar(' ');
		ft_putnbr(tmp->grp);
		ft_putchar(' ');
		ft_putendl(tmp->stack_name);
		tmp = tmp->prev;
	}
}

void	ft_print_base_stack(t_stk *stack)
{
	t_stk_elt	*tmp;

	tmp = stack->base;
	ft_putstr("size ");
	ft_putnbr(stack->size);
	ft_putstr(" name ");
	ft_putendl(stack->stk_name);
	ft_putstr("top ");
	ft_putlnbr(stack->top->value);
	ft_putstr(" base ");
	ft_putlnbr(stack->base->value);
	ft_putchar('\n');
	while (tmp)
	{
		ft_putlnbr(tmp->value);
		ft_putchar(' ');
		ft_putnbr(tmp->grp);
		ft_putchar(' ');
		ft_putendl(tmp->stack_name);
		tmp = tmp->next;
	}
}

void	ft_stkadd_back(t_stk **stack, t_stk_elt *elt)
{
	t_stk_elt	*tmp;
	if (!*stack)
		return ;
	if (!(*stack)->size)
	{
		(*stack)->base = elt;
		(*stack)->top = elt;
		(*stack)->size++;
		return ;
	}
	tmp = (*stack)->top;
	elt->prev = tmp;
	tmp->next = elt;
	(*stack)->top = elt;
	(*stack)->size++;
}

void	ft_del_stk_elt(t_stk_elt *elt)
{
	if (!elt)
		return ;
	if (elt->stack_name)
		free(elt->stack_name);
	free(elt);
	elt = NULL;
}

/* Clean in top order the stack (top to base) */
void	ft_pop_clear_stk(t_stk **stack)
{
	t_stk_elt	*tmp;

	if (!*stack)
		return;
	while ((*stack)->size)
	{
		tmp = (*stack)->top->prev;
		ft_del_stk_elt((*stack)->top);
		(*stack)->top = tmp;
		(*stack)->size--;
	}
	free((*stack)->stk_name);
	free(*stack);
}

t_stk_elt	*ft_pop_stack(t_stk **stack)
{
	t_stk_elt	*elt_pop;

	if (!(*stack)->top)
		return (NULL);
	elt_pop = (*stack)->top;
	if (elt_pop->prev)
	{
		elt_pop->prev->next = NULL;
		(*stack)->top = elt_pop->prev;
		elt_pop->prev = NULL;
		free(elt_pop->stack_name);
		elt_pop->stack_name = NULL;
		elt_pop->grp = 0;
	}
	else
		(*stack)->top = NULL;
	(*stack)->size--;
	return (elt_pop);
}

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
		t_stk_elt	*pop;

		a = ft_init_stack("a");
		i = 0;
		// Recup des args sur la stack a, base: 1er elt empilé; top: dernier elt empilé
		while (args[i])
		{
			a_elt = ft_init_stk_elt(ft_atol(args[i]), 1, a->stk_name);
			ft_stkadd_back(&a, a_elt);
			i++;
		}
		ft_print_top_stack(a);
		ft_putendl("-----------------------------------------------------");
		if (a->size)
			ft_print_base_stack(a);
		// --------------------POP STACK-----------------------------------
		pop = ft_pop_stack(&a);
		if (a->top)
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
		if (a->size)
			ft_print_base_stack(a);
		// --------------------FREE STACK----------------------------------
		if (pop)
			ft_del_stk_elt(pop);
		if (a)
			ft_pop_clear_stk(&a);
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
