/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmunoz- <crmunoz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:48:20 by crmunoz-          #+#    #+#             */
/*   Updated: 2024/07/31 15:51:43 by crmunoz-         ###   ########.fr       */
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
