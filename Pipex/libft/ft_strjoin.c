/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborgian <dborgian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:52:48 by dborgian          #+#    #+#             */
/*   Updated: 2023/05/04 17:36:31 by dborgian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_strjoin(char const *s1, char const *s2, int free1, int free2)
{
	char	*s3;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	j = 0;
	i = 0;
	s3 = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1 * sizeof(char));
	if (!s3)
		return (NULL);
	while (s1 && s1[i] != '\0')
	{
		((char *)s3)[i] = s1[i];
		i++;
	}
	while (s2 && s2[j] != '\0')
		((char *)s3)[i++] = s2[j++];
	((char *)s3)[i] = '\0';
	if (s1 && free1 == 1)
		free((void *)s1);
	if (s2 && free2 == 1)
		free((void *)s2);
	return (s3);
}
