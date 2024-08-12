/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmunoz- <crmunoz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:55:19 by crmunoz-          #+#    #+#             */
/*   Updated: 2024/08/12 17:18:17 by crmunoz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>

size_t	ft_strlcat(char *dst, char *src, size_t dstsize);
size_t	ft_strlen(char *s);
char	*ft_strstr(char *str, char *to_find);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strnstr(char *stack, char *needle, size_t len);
char	**ft_split(char *s, char c);
char	**get_path(char **env);
char	*command(char **pathitos, char **arg);
char	**awk_split(char *argv, int i, int len);
void	free_args(char	**args);
void	free_arrays(char **awks, char **flags);

#endif