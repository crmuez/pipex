/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prequel_pipex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmunoz- <crmunoz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:48:20 by crmunoz-          #+#    #+#             */
/*   Updated: 2024/08/01 13:51:36 by crmunoz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_path(char **env)
{
	char	*big_pathito;
	char	**pathitos;
	int		nchar;
	int		i;

	pathitos = NULL;
	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH=", 5) != 0)
		{
			big_pathito = ft_strnstr(env[i], "PATH=", 5);
			break ;
		}
		i++;
	}
	if (big_pathito != NULL)
	{
		nchar = (ft_strlen(big_pathito) - 5);
		big_pathito = ft_substr(big_pathito, 6, nchar);
		pathitos = ft_split(big_pathito, ':');
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
			break ;
		i++;
	}
	return (command);
}

char	*remove_awk(char **argv)
{
	size_t	len;
	char	*result;
	char	*str;

	str = ft_strdup(argv[2]);
	len = ft_strlen(str);
	result = malloc(len -2);
	if (!result)
		return (0);
	str += 3;
	while (*str != '\0')
	{
		if (*str != '\'' && *str != '\"')
		{
			result = str;
			result++;
		}
		str++;
	}
	result = '\0';
	printf("%s", result);
	return (result);
}

char	**split_awk(char **argv)
{
	char	**awk;
	int		len;

	awk = malloc(sizeof(char *) * 3);
	if (!awk)
		return (NULL);
	awk[2] = NULL;
	awk[0] = ft_strdup("awk\0");
	if (!awk[0])
		return (NULL);
	len = ft_strlen(remove_awk(argv));
	awk[1] = malloc(sizeof(char *) * len);
	awk[1] = remove_awk(argv);
	return (awk);
}
