/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alellouc <alellouc@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:54:45 by alellouc          #+#    #+#             */
/*   Updated: 2021/09/21 15:55:12 by alellouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

t_bool	ft_check_arg_is_int(char **args)
{
	long	value;

	if (!args)
		return (e_false);
	while (*args)
	{
		value = ft_atol(*args);
		if (!ft_is_int(value))
		{
			ft_puterr();
			return (e_false);
		}
		args++;
	}
	return (e_true);
}
