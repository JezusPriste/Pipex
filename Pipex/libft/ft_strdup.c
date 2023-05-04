/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborgian <dborgian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:04:47 by dborgian          #+#    #+#             */
/*   Updated: 2023/05/04 17:36:26 by dborgian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;
	int		k;

	k = ft_strlen(s1) + 1;
	i = 0;
	s2 = (char *)malloc(sizeof(char) * k);
	if (!s2)
		return (NULL);
	while (s1[i] != '\0')
	{
		((char *)s2)[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
