/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborgian <dborgian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:49:20 by dborgian          #+#    #+#             */
/*   Updated: 2023/05/04 17:36:44 by dborgian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*res;
	unsigned int	k;

	if (!s)
		return (NULL);
	k = (unsigned int)ft_strlen(s);
	i = 0;
	if (k <= len)
		res = (char *)malloc(k + 1 * sizeof(char));
	else
		res = (char *)malloc(len + 1 * sizeof(char));
	if (!res)
		return (NULL);
	if (!(k < start))
	{
		while (s[start] != '\0' && i < len)
		{
			((char *)res)[i] = s[start];
			i++;
			start++;
		}
	}
	res[i] = '\0';
	return (res);
}
