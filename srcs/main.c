#include "../includes/push_swap.h"

// garder ca ici le temps que le tri soit efficace
void	ft_qsort_tab(void *tab[], int l, int r, int (*cmp)(void *, void *))
{
	int	i;
	int	last;

	if (l >= r)
		return ;
	ft_swap_tab(tab, l, (l + r) / 2);
	last = l;
	i = l + 1;
	printf("Avant le tri elt last: %d %s, swap avec elt i: %d %s (not yet)\n", last, tab[last], i, tab[i]);
	while (i <= r)
	{
		if ((*cmp)(tab[i], tab[l]) < 0)
		{
			printf("Avant le tri elt last: %d %s, swap avec elt i: %d %s\n", last, tab[last], i, tab[i]);
			// swap ici
			ft_swap_tab(tab, ++last, i);
			// fin de swap
			printf("Après le tri elt last: %d %s, swap avec elt i: %d %s\n", last, tab[last], i, tab[i]);
		}
		i++;
	}
	ft_swap_tab(tab, l, last);
	ft_qsort_tab(tab, l, last - 1, cmp);
	ft_qsort_tab(tab, last + 1, r, cmp);
}

void	sa(t_stack *a, int *last, int *penultimate)
{
	if (!a || ft_lstsize(a) == 1)
		return ;
	ft_swap(last, penultimate);
	ft_putendl("sa");
}
// Quel comportement si argv = "liste de nombres valides" nb nb nb "re liste de nombres valides"
int	main(int argc, char **argv)
{
	// --------------------DISPLAY-------------------------------------
	ft_putnbr(argc);
	ft_putstr(" arguments.\n");
	// ----------------------------------------------------------------
	if (argc > 1)
	{
		char	**args;
		int		i;
		argv++;
		// --------------------DISPLAY-------------------------------------
		if (!ft_is_valid_ps_args(argv))
			ft_putendl("Arg invalide");
			//	return (-1);
		// ----------------------------------------------------------------
		if (argc == 2)
		{
			// --------------------DISPLAY-------------------------------------
			ft_putnbr(ft_cntwds(*argv, 32));
			ft_putendl(" args.");
			// ----------------------------------------------------------------
			args = ft_split(*argv, 32);
			if (!args)
				return (-1);
		}
		else
			args = argv;
		if (ft_has_duplicate_chars(args))
			// --------------------DISPLAY-------------------------------------
			ft_putendl("Arg duplicate");
			// ----------------------------------------------------------------
		//	return (-1);
		if (!ft_check_arg_is_int(args))
			// --------------------DISPLAY-------------------------------------
			ft_putendl("Arg sup or inf to the limits of type int");
			// ----------------------------------------------------------------
			// return (-1);
		// Passer args en liste chainee
		// voir du cote de strtotab pour recup argv dans un tab de structures
		t_stack	*a;
		t_stack	*elt_a;
		int		*p_i;

		a = NULL;
		i = 0;
		p_i = &i;
		while (i < 4)
		{
			elt_a = ft_lstnew(p_i);
			printf("elt_a->content: %ld, i %d %p %x\n", (long)elt_a->content, *p_i, p_i, *p_i);
			ft_putlnbr((long)elt_a->(*content));
			ft_putchar(' ');
			ft_luint_putnbr_base((long)elt_a->content, "0123456789abcdef", 1);
			ft_putchar('\n');
			ft_lstadd_back(&a, elt_a);
			p_i++;
			*p_i = i++;;
		}
		ft_print_list(a);
		// --------------------MEDIAN--------------------------------------
		// Trouver la mediane, donc trier args une fois mis en liste chainee (pr pas casser l'ordre initial
		int end;
		int begin;
		long	me;
		long	q1;
		long	q3;

		begin = 0;
		if (argc == 2)
			end  = ft_cntwds(*argv, 32) - 1;
		else
			end = argc - 2;
		// Apartir d'ici args est trié
		ft_qsort_tab((void **)args, begin, end, (int (*) (void *, void *)) ft_lnbrcmp);
		// Reste a savoir si on prend la mediane des valeurs ou des indices (comme qs)
		me = ft_atol(args[end / 2]);
		q1 = ft_atol(args[end / 4]);
		q3 = ft_atol(args[(3 * end) / 4]);
		printf("\033[35mq1 (end / 4: %d): %ld, me (end / 2: %d): %ld, q3 ((3 * end) / 4: %d): %ld\033[0m\n", end / 4, q1, end / 2, me, (3 * end) / 4, q3);
		// ----------------------------------------------------------------

		//int a = 3;
		//int	b = 5;
	/*	char	*a = " World";
		char	*b = "Hello";
		printf("before swap a: %s and b: %s\n", a, b);
		ft_swap(&a, &b);
		printf("after swap a: %s and b: %s\n", a, b);*/
		// --------------------DISPLAY-------------------------------------
		i = 0;
		ft_putendl("Tableau args trié");
		while (args[i])
		{
			ft_putendl(args[i++]);
		}
		// ----------------------------------------------------------------

		// On free le tableau genere par split
		if (argc == 2)
		{
			i = ft_cntwds(*argv, 32);
			while (i--)
			{
				free(args[i]);
			}
			free(args);
		}
		// --------------------CHECK ARGV----------------------------------
		// Cette boucle est la pr verif que je modifie pas le pointeur argv avec mes tests de fonction dessus
		while (*argv)
		{
			while (**argv)
			{
				
				if (!ft_isdigit(**argv) && **argv != 32 && **argv != 45)
				{
					// --------------------DISPLAY-------------------------------------
					ft_puterr();
					ft_putendl("Arg invalide");
					//return (-1);
					// ----------------------------------------------------------------
				}
				else
				{
					ft_putchar(**argv);
				}
				(*argv)++;
			}
			ft_putchar('\n');
			argv++;
		}
		// ----------------------------------------------------------------
	}
	else
	{
		// --------------------DISPLAY-------------------------------------
		// only give the prompt back, display nothing if no arg
		ft_puterr();
		ft_putendl("No arg");
		return (0);
		// ----------------------------------------------------------------
	}
	ft_putstr("---------------------------------------\n");
	return (0);
}
