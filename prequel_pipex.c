/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prequel_pipex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmunoz- <crmunoz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:48:20 by crmunoz-          #+#    #+#             */
/*   Updated: 2024/08/12 19:30:47 by crmunoz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_path(char **env)
{
	char	*big_pathito;
	char	**pathitos;
	int		nchar;
	int		i;
	char	*rest_pathito;

	pathitos = NULL;
	i = -1;
	while (env[++i])
	{
		if (ft_strnstr(env[i], "PATH=", 5) != 0)
		{
			big_pathito = ft_strnstr(env[i], "PATH=", 5);
			break ;
		}
	}
	if (big_pathito != NULL)
	{
		nchar = (ft_strlen(big_pathito) - 5);
		rest_pathito = ft_substr(big_pathito, 6, nchar);
		pathitos = ft_split(rest_pathito, ':');
		free(rest_pathito);
	}
	return (pathitos);
}

char	*command(char **pathitos, char **arg)
{
	int		i;
	char	*aux;
	char	*command;

	i = 1;
	aux = ft_strjoin("/", arg[0]);
	while (pathitos[i])
	{
		command = ft_strjoin(pathitos[i], aux);
		if (!access(command, X_OK))
		{
			free(aux);
			return (command);
		}
		i++;
		free(command);
	}
	free(aux);
	return (NULL);
}

char	**awk_split(char *argv, int i, int len)
{
	char	**awks;
	char	**flags;
	char	**final_split_arg;

	awks = ft_split(argv, '\'');
	flags = ft_split(awks[0], ' ');
	while (flags[++i])
		len++;
	if (awks[1])
		len++;
	final_split_arg = malloc(sizeof(char *) * len);
	i = 0;
	while (flags[i])
	{
		final_split_arg[i] = ft_strdup(flags[i]);
		i++;
	}
	if (awks[1])
		final_split_arg[i++] = ft_strdup(awks[1]);
	final_split_arg[i] = NULL;
	free_arrays(awks, flags);
	return (final_split_arg);
}

void	free_arrays(char **awks, char **flags)
{
	int	i;

	i = 0;
	if (awks)
	{
		while (awks[i])
		{
			free(awks[i]);
			i++;
		}
		free(awks);
	}
	if (flags)
	{
		while (flags[i])
		{
			free(flags[i]);
			i++;
		}
		free(flags);
	}
}

void	free_args(char	**args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	if (args)
		free(args);
}
