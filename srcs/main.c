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
			return (e_true);
		i++;
	}
	return (e_false);
}

int	main(int argc, char **argv)
{
	ft_putnbr(argc);
	ft_putstr(" arguments.\n");
	if (argc > 1)
	{
		argv++;
		if (!ft_is_valid_ps_args(argv))
				return (-1);
		if (argc == 2)
		{
			ft_putnbr(ft_cntwds(*argv, 32));
			ft_putendl(" args.");
			// ----------------------------------------------------------------
			char **args = ft_split(*argv, 32);
			if (!args)
				return (-1);
			if (ft_has_duplicate_chars(args))
				ft_puterr();
		/*	int	i = 0;
			int	j = 0;
			char	*doublon = NULL;
			while (args[i] && args[i + 1] && !doublon)
			{
				j = i;
				while (args[j + 1] && !doublon)
				{
					doublon = ft_strnstr(args[i], args[j + 1], ft_strlen(args[j + 1]));
					j++;
				}
				if (doublon)
				{
					 -----------------------------------------------------
					ft_putstr("\033[31m");
					ft_putstr("doublon: ["); ft_putstr(doublon); ft_putendl("]");
					 -----------------------------------------------------
					 ft_puterr();
					 liberer args avant d'exit si doublon
				}
				 -----------------------------------------------------
				ft_putstr("\033[0m"); ft_putstr("\033[32margs[i]: ["); ft_putstr(args[i]); ft_putendl("]"); ft_putstr("\033[0m");
				 -----------------------------------------------------
				i++;
			}*/
			// Garder ca pour ne pas oublier de free le split
		/*	while (i--)
			{
				free(args[i]);
			}
			free(args);*/
			// ----------------------------------------------------------------
		}
		while (*argv)
		{
			while (**argv)
			{
				
				if (!ft_isdigit(**argv) && **argv != 32 && **argv != 45)
				{
					ft_puterr();
					return (-1);
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
		ft_puterr();
		return (-1);
	}
	ft_putstr("---------------------------------------\n");
	return (0);
}
