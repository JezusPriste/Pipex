/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborgian <dborgian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:10:52 by dborgian          #+#    #+#             */
/*   Updated: 2023/05/04 17:35:22 by dborgian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;
	size_t	total;

	total = count * size;
	mem = malloc(total);
	if (!mem)
		return (NULL);
	ft_bzero(mem, total);
	return (mem);
}
