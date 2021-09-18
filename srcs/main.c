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
			if (!ft_isdigit(*pp_argv) && *pp_argv != 32)
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
		}
		while (*argv)
		{
			while (**argv)
			{
				if (!ft_isdigit(**argv) && **argv != 32)
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
