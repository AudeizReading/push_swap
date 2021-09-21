#include "../includes/push_swap.h"

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

		if (argc == 2)
		{
			i = ft_cntwds(*argv, 32);
			while (i--)
			{
				free(args[i]);
			}
			free(args);
		}
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
