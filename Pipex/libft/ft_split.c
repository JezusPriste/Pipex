/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborgian <dborgian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:02:49 by dborgian          #+#    #+#             */
/*   Updated: 2023/05/04 17:36:17 by dborgian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"
#include <unistd.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len);

unsigned int	ft_counter(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

int	ft_strcheck(char const *s, char c)
{
	int			i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	*ft_cicle(char const *s, char **str, char c, unsigned int count)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (k < count)
		{
			str[k] = ft_substr(s, j, (size_t)(i - j));
			k++;
		}
	}
	str[k] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	i;
	char			**matrix;

	if (!s)
		return (NULL);
	i = ft_counter(s, c);
	matrix = (char **)malloc((i + 1) * sizeof (char *));
	if (!matrix)
		return (NULL);
	if (i == 0)
		matrix[0] = NULL;
	else if (i == 1 && !ft_strcheck(s, c))
	{
		matrix[0] = ft_substr(s, 0, ft_strlen(s));
		matrix[1] = NULL;
	}
	else
		ft_cicle(s, matrix, c, i);
	return (matrix);
}
