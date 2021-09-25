#include "../includes/push_swap.h"

/*   TO-DO LIST 
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
		// --------------------SWAP----------------------------------------
		//int a = 3;
		//int	b = 5;
	/*	char	*a = " World";
		char	*b = "Hello";
		printf("before swap a: %s and b: %s\n", a, b);
		ft_swap(&a, &b);
		printf("after swap a: %s and b: %s\n", a, b);*/
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
