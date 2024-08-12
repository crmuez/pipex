/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmunoz- <crmunoz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:32:04 by crmunoz-          #+#    #+#             */
/*   Updated: 2024/08/12 18:37:35 by crmunoz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	die_first(char	**pathitos, char	**argv, int fd[2])
{
	char	*command1;
	char	**arg1;
	int		input;

	input = open(argv[1], O_RDONLY);
	if (input < 0)
		perror(NULL);
	arg1 = awk_split(argv[2], -1, 1);
	command1 = command(pathitos, arg1);
	dup2(fd[1], 1);
	dup2(input, 0);
	close(fd[0]);
	close(input);
	close(fd[1]);
	if (execve(command1, arg1, NULL) == -1)
	{
		perror("Command syntax error");
		exit(1);
	}
	free_arrays(pathitos, arg1);
	free(command1);
	exit (127);
}

void	die_second(char	**pathitos, char	**argv, int fd[2])
{
	char	**arg2;
	char	*command2;
	int		output;

	output = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0666);
	arg2 = awk_split(argv[3], -1, 1);
	command2 = command(pathitos, arg2);
	dup2(output, 1);
	dup2(fd[0], 0);
	close(fd[1]);
	close(fd[0]);
	if (execve(command2, arg2, NULL) == -1)
	{
		perror("Command syntax error");
		exit(1);
	}
	free_arrays(pathitos, arg2);
	free(command2);
	exit (127);
}

int	main(int argc, char **argv, char **env)
{
	char	**pathitos;
	int		fd[2];
	int		pid1;
	int		pid2;

	if (argc != 5)
		exit(1);
	pipe(fd);
	pathitos = get_path(env);
	pid1 = fork();
	if (pid1 == 0)
		die_first(pathitos, argv, fd);
	pid2 = fork();
	if (pid2 == 0)
		die_second(pathitos, argv, fd);
	wait(NULL);
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