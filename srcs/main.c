#include "../includes/push_swap.h"
void	ft_puterr(void)
{
	ft_putendl_fd("\033[31mError\033[0m", 2);
}

/* If **argv is a digit or space - In case there is only 1 string of numbers*/
t_bool	ft_is_valid_ps_args(char **argv)
{
	char	**p_argv;
	char	*pp_argv;

	p_argv = argv;
	while (*p_argv)
	{
		pp_argv = *p_argv;
		while (*pp_argv)
		{
			// Que faire si 2 espaces a la suite ?
			if (!ft_isdigit(*pp_argv) && *pp_argv != 32 && *pp_argv != '-')
			{
				ft_puterr();
				return (e_false);
			}
			pp_argv++;
		}
		p_argv++;
	}
	return (e_true);
}

t_bool ft_has_duplicate_chars(char **argv)
{
	int		i;
	int		j;
	char	*duplicate;

	i = 0;
	j = 0;
	duplicate = NULL;
	while (argv[i] && argv[i + 1] && !duplicate)
	{
		j = i;
		while (argv[j + 1] && !duplicate)
		{
			duplicate = ft_strnstr(argv[i], argv[j + 1], ft_strlen(argv[j + 1]));
			j++;
		}
		if (duplicate)
		{
			ft_puterr();
			return (e_true);
		}
		i++;
	}
	return (e_false);
}

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
		//	return (-1);
			// ----------------------------------------------------------------
		// Ici, il faudrait checker les valeurs de args si +petit que INT_MIN ou plus grand que INT_MAX
		i = 0;
		while (args[i])
		{
			int	value;

			value = ft_atoi(args[i]);
			ft_putnbr(ft_atoi(args[i]));
			ft_putchar('\n');
			if (value < INT_MIN || value > INT_MAX)
			{
				ft_putendl("Arg sup or inf to the limits of type int");
				ft_puterr();
				// return (-1);
			}
			i++;
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
		ft_puterr();
		ft_putendl("No args");
	//	return (-1);
		// ----------------------------------------------------------------
	}
	ft_putstr("---------------------------------------\n");
	return (0);
}
