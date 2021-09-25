#include "../includes/push_swap.h"

/*   TO-DO LIST 
**   - creer fn qui recup le tab d'argv en liste chainee
**   - trouver moyen de reutils la fn sa pour sb
**   - coder les fonction pop et push de la stack
**   - faut-il des membres sup comme le grp ou la pile a Stack
**   -*/

typedef struct s_pivots
{
	long	min;
	long	max;
	long	me;
	long	q1;
	long	q3;
}				t_pivots;

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
//	printf("Avant le tri elt last: %d %s, swap avec elt i: %d %s (not yet)\n", last, tab[last], i, tab[i]);
	while (i <= r)
	{
		if ((*cmp)(tab[i], tab[l]) < 0)
		{
		//	printf("Avant le tri elt last: %d %s, swap avec elt i: %d %s\n", last, tab[last], i, tab[i]);
			// swap ici
			ft_swap_tab(tab, ++last, i);
			// fin de swap
	//		printf("Après le tri elt last: %d %s, swap avec elt i: %d %s\n", last, tab[last], i, tab[i]);
		}
		i++;
	}
	ft_swap_tab(tab, l, last);
	ft_qsort_tab(tab, l, last - 1, cmp);
	ft_qsort_tab(tab, last + 1, r, cmp);
}

// Attention trie args definitement, recup dans une stack avant tri
t_pivots	ft_get_median(int argc, char **argv, char **args)
{
	t_pivots	pivot;
	int			begin;
	int			end;

	begin = 0;
	if (argc == 2)
		end  = ft_cntwds(*argv, 32) - 1;
	else
		end = argc - 2;
	ft_qsort_tab((void **)args, begin, end, (int (*) (void *, void *)) ft_lnbrcmp);
	pivot.min = ft_atol(args[begin]);
	pivot.me = ft_atol(args[end / 2]);
	pivot.q1 = ft_atol(args[end / 4]);
	pivot.q3 = ft_atol(args[(3 * end) / 4]);
	pivot.max = ft_atol(args[end]);
	return (pivot);
}

/*char	**ft_parse_args(int argc, char **argv)
{
	char	**args;

	if (argc < 2)
		return (NULL);
	if (!ft_is_valid_ps_args(argv))
		return (NULL);
	if (argc == 2)
	{
		args = ft_split(*argv, 32);
		if (!args)
			return (NULL);
	}
	else
		args = argv;
	if (ft_has_duplicate_chars(args))
		return (NULL);
	if (!ft_check_arg_is_int(args))
		return (NULL);
	return (args);
}

void	ft_free_args(int argc, char **argv, char **args)
{
	int	i;

	if (argc == 2)
	{
		i = ft_cntwds(*argv, 32);
		while (i--)
			free(args[i]);
		free(args);
	}
}*/

// A adapter a la nouvelle structure stack
void	sa(t_stack *stack, int *top_stack, int *penultimate)
{
	if (!stack || ft_lstsize(stack) == 1)
		return ;
	ft_swap(top_stack, penultimate);
	// Trouver un moyen pour afficher sa ou sb car same function
	// Changer le nom de la fonction aussi
	ft_putendl("sa");
}
// Quel comportement si argv = "liste de nombres valides" nb nb nb "re liste de nombres valides"
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
		// --------------------MEDIAN--------------------------------------
		t_pivots	pivot;

		pivot = ft_get_median(argc, argv, args);
		// --------------------DISPLAY-------------------------------------
		printf("\033[36;1mmin: %ld, q1: %ld, me: %ld, q3: %ld, max: %ld\033[0m\n", pivot.min, pivot.q1, pivot.me, pivot.q3, pivot.max);
		i = 0;
		ft_putendl("Tableau args trié");
		while (args[i])
		{
			ft_putendl(args[i++]);
		}
		// ----------------------------------------------------------------

		// --------------------SWAP----------------------------------------
		//int a = 3;
		//int	b = 5;
	/*	char	*a = " World";
		char	*b = "Hello";
		printf("before swap a: %s and b: %s\n", a, b);
		ft_swap(&a, &b);
		printf("after swap a: %s and b: %s\n", a, b);*/
		// ----------------------------------------------------------------

		// --------------------FREE ARGS-----------------------------------
		// On free le tableau genere par split
		ft_free_args(argc, argv, args);
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
		return (0);
		// ----------------------------------------------------------------
	}
	ft_putstr("---------------------------------------\n");
	return (0);
}
