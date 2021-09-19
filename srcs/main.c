#include "../includes/push_swap.h"
void	ft_puterr(void)
{
	ft_putendl_fd("\033[31mError\033[0m", 2);
}

/* If **argv is a digit or space - In case there is only 1 string of numbers*/
int	ft_is_valid_ps_args(char **argv)
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
				return (0);
			}
			pp_argv++;
		}
		p_argv++;
	}
	return (1);
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
			int	i = 0;
			int	j = 0;
			int	size = sizeof(*args[i]) * ft_strlen(args[i]) + 1;
			char	*doublon = NULL;
			while (args[i] && args[i + 1])
			{
				j = i;
				ft_putstr("size: [");
				ft_putnbr(size);
				ft_putendl("]");
				ft_putstr("\033[31m");
				doublon = ft_strnstr(args[j + 1], args[i], ft_strlen(args[i]));
				// Check si 2 doublons cote a cote mais pas separes
				while (!doublon)
				//while (args[j + 1])
	//			while (args[i])
				{
					doublon = ft_strnstr(args[j + 1], args[i], ft_strlen(args[i]));
					j++;
				}
				if (doublon)
				{
					ft_putstr("doublon: [");
					ft_putstr(doublon);
					ft_putendl("]");
					// ft_puterr();
					// liberer args avant d'exit si doublon
				}
				ft_putstr("\033[0m"); ft_putstr("\033[32m args[i]: ["); ft_putstr(args[i]); ft_putendl("]");
				ft_putstr("*argv + size: [");
				if (args[i + 1])
					ft_putstr(*argv + size);
				ft_putendl("]");
				ft_putchar('\n');
				ft_putstr("\033[0m");
				i++;
				if (args[i])
					size += (sizeof(*args[i]) * ft_strlen(args[i]) + 1);
			}
			while (i--)
			{
				free(args[i]);
			}
			free(args);
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
