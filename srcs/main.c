#include "../includes/push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_swap_tab(void *tab[], int a, int b)
//void	ft_swap_tab(char **tab, int a, int b)
{
	void	*tmp;

	tmp = tab[a];
	tab[a] = tab[b];
	tab[b] = tmp;
}

int		ft_lnbrcmp(char *s1, char *s2)
{
	long	n1;
	long	n2;

	n1 = ft_atol(s1);
	n2 = ft_atol(s2);
	printf("n1 %ld, n2 %ld\n", n1, n2);
	if (n1 < n2)
		return (-1);
	else if (n1 > n2)
		return (1);
	return (0);
}

int		ft_strcmp(char *s1, char *s2)
{
	while (s1 && s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char) *s1 - (unsigned char) *s2);
}

//void	ft_qsort_tab(char **tab, int l, int r)
void	ft_qsort_tab(void *tab[], int l, int r, int (*cmp)(void *, void *))
{
	int	i;
	int	last;

	if (l >= r)
		return ;
	ft_swap_tab(tab, l, (l + r) / 2);
	last = l;
	i = l + 1;
	ft_putstr("Avant le tri ");
	ft_putstr("elt last: ");
	ft_putnbr(last);
	ft_putstr(" ");
	ft_putstr(tab[last]);
	ft_putstr(" swap avec elt i ");
	ft_putnbr(i);
	ft_putstr(" ");
	ft_putstr(tab[i]);
	ft_putstr("(not yet)\n");
	while (i <= r)
	{
		if ((*cmp)(tab[i], tab[l]) < 0)
		//if (ft_strcmp(tab[i], tab[l]) < 0)
		{
			ft_putstr("Avant le tri ");
			ft_putstr("elt last: ");
			ft_putnbr(last);
			ft_putstr(" ");
			ft_putstr(tab[last]);
			ft_putstr(" swap avec elt i ");
			ft_putnbr(i);
			ft_putstr(" ");
			ft_putstr(tab[i]);
			ft_putstr("\n");
			// swap ici
			ft_swap_tab(tab, ++last, i);
			// fin de swap
			ft_putstr("Apres le tri ");
			ft_putstr("elt last: ");
			ft_putnbr(last);
			ft_putstr(" ");
			ft_putstr(tab[last]);
			ft_putstr(" swap avec elt i ");
			ft_putnbr(i);
			ft_putstr(" ");
			ft_putstr(tab[i]);
			ft_putstr("\n");
		}
		i++;
	}
	ft_swap_tab(tab, l, last);
	ft_qsort_tab(tab, l, last - 1, cmp);
	ft_qsort_tab(tab, last + 1, r, cmp);
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
			// voir du cote de strtotab pour recup argv dans un tab de structures
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
		// Trouver la mediane, donc trier args une fois mis en liste chainee (pr pas casser l'ordre initial
		// Pb avec les args non chaine (argv[argc])
		int end;
		int begin;
		if (argc == 2)
		{
			end  = ft_cntwds(*argv, 32) - 1;
			begin = 0;
		}
		else
		{
			begin = 1;
			end = argc - 1;
		}
		ft_qsort_tab((void **)args, begin, end, (int (*) (void *, void *)) ft_lnbrcmp);
	//	ft_qsort_tab((void **)args, 0, ft_cntwds(*argv, 32) - 1, (int (*) (void *, void *)) ft_strcmp);
		i = 0;
	//	ft_putstr("ft_cntwds");
		ft_putendl("Tableau args trié");
		while (args[i])
		{
			ft_putendl(args[i++]);
		}
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
