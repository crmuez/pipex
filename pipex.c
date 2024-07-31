/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmunoz- <crmunoz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:32:04 by crmunoz-          #+#    #+#             */
/*   Updated: 2024/07/31 20:29:39 by crmunoz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*command(char **pathitos, char **arg)
{
	int		i;
	char	*aux;
	char	*command;
	int		pid;

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

void	die_first(char	**pathitos, char	**argv, int	fd[2])
{
	int		pid;
	char	*command1;
	char	**arg1;
	int		input;

	arg1 = ft_split(argv[1], ' ');
	command1 = command(pathitos, arg1);
	pid = fork();
	input = open("pipex.c", O_RDONLY);
	if (pid == 0)
	{
		dup2 (fd[1], 1);
		dup2(input, 0);
		close(fd[0]);
		close(input);
		execve(command1, arg1, NULL);
		exit (127);
	}
	else
		return ;
}

void	die_second(char	**pathitos, char	**argv, int	fd[2])
{
	char	**arg2;
	char	*command2;
	int		pid;
	int		output;

	arg2 = ft_split(argv[2], ' ');
	command2 = command(pathitos, arg2);
	pid = fork();
	output = open("output", O_RDWR | O_CREAT, O_TRUNC, 0644);
	if (pid == 0)
	{
		dup2(output, 1);
		dup2(fd[0], 0);
		close(fd[1]);
		execve(command2, arg2, NULL);
		exit (127);
	}
	else
		return ;
}

int	main(int argc, char **argv, char **env)
{
	char	**pathitos;
	int		fd[2];

	pipe(fd);
	pathitos = get_path(env);
	die_first(pathitos, argv, fd);
	die_second(pathitos, argv, fd);
}
/*
	printf("%s\n", command);

	i = 0;
	while (pathitos[i])
	{
		printf("%s\n", pathitos[i]);
		i++;
	}

*/