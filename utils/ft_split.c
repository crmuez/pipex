/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmunoz- <crmunoz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:32:41 by crmunoz-          #+#    #+#             */
/*   Updated: 2024/07/30 20:10:04 by crmunoz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static int	ft_count_words(char *s, char c)
{
	int	i;
	int	n_words;

	i = 0;
	n_words = 0;
	while (s[i] != '\0')
	{
		if ((s[i] != c) && ((s[i + 1] == c) || (s[i + 1] == '\0')))
			n_words++;
		i++;
	}
	return (n_words);
}

static char	**ft_memory(char *s, char c)
{
	char	**result;

	result = malloc (sizeof (char *) * (ft_count_words(s, c) + 1));
	if (result == NULL)
		return (NULL);
	return (result);
}

static int	ft_splot(char *s, char c, int *k, char **result)
{
	char	*tmp;
	int		j;

	j = 0;
	while (s[j] != '\0' && (s[j] != c))
		j++;
	tmp = ft_substr (s, 0, j);
	if (tmp == NULL)
	{
		while (*k > 0)
			free(result[--(*k)]);
		free(result);
		return (-1);
	}
	if (tmp[0] == '\0')
		free(tmp);
	if (tmp && tmp[0] != '\0')
		result[(*k)++] = tmp;
	return (j);
}

char	**ft_split(char *s, char c)
{
	unsigned int	i;
	char			**result;
	int				k;
	int				g;

	k = 0;
	result = ft_memory(s, c);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			g = ft_splot(s + i, c, &k, result);
			if (g == -1)
				return (NULL);
			i = i + g;
		}
	}
	result[k] = NULL;
	return (result);
}

/* int	main(void)
{
	printf("%d", ft_count_words("  patata frita  ", ' '));
}
 */