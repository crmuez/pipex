/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmunoz- <crmunoz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:32:04 by crmunoz-          #+#    #+#             */
/*   Updated: 2024/08/08 21:12:15 by crmunoz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	die_first(char	**pathitos, char	**argv, int fd[2])
{
	int		pid;
	char	*command1;
	char	**arg1;
	int		input;

	arg1 = NULL;
	command1 = NULL;
	pid = fork();
	input = open(argv[1], O_RDONLY);
	if (pid == 0)
	{
		arg1 = awk_split(argv[2], -1, 1);
		command1 = command(pathitos, arg1);
		dup2 (fd[1], 1);
		dup2(input, 0);
		close(fd[0]);
		close(input);
		close(fd[1]);
		execve(command1, arg1, NULL);
		free_arrays(pathitos, arg1);
		free(command1);
		exit (127);
	}
	else
		return ;
}

void	die_second(char	**pathitos, char	**argv, int fd[2])
{
	char	**arg2;
	char	*command2;
	int		pid;
	int		output;

	arg2 = NULL;
	command2 = NULL;
	pid = fork();
	output = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (pid == 0)
	{
		arg2 = awk_split(argv[3], -1, 1);
		command2 = command(pathitos, arg2);
		dup2(output, 1);
		dup2(fd[0], 0);
		close(fd[1]);
		close(fd[0]);
		execve(command2, arg2, NULL);
		free_arrays(pathitos, arg2);
		free(command2);
		exit (127);
	}
	else
		return ;
}

int	main(int argc, char **argv, char **env)
{
	char	**pathitos;
	int		fd[2];

	if (argc != 5)
		return (0); //escribir error argumentos
	pipe(fd);
	pathitos = get_path(env);
	die_first(pathitos, argv, fd);
	die_second(pathitos, argv, fd);
	free_args(pathitos);
}
/*
	printf("%s\n", command);

	i = 0;
	while (arg[i])
	{
		printf("%s\n", arg[i]);
		i++;
	}

*/