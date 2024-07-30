/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmunoz- <crmunoz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:32:04 by crmunoz-          #+#    #+#             */
/*   Updated: 2024/07/30 21:37:15 by crmunoz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	int		i;
	char	*big_pathito;
	size_t	nchar;
	char	**pathitos;

	(void) argc;
	(void) argv;
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
	i = 0;
	while (pathitos[i])
	{
		printf("%s\n", pathitos[i]);
		i++;
	}
}
/*

*/