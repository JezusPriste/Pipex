/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborgian <dborgian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:07:51 by dborgian          #+#    #+#             */
/*   Updated: 2023/05/04 17:24:25 by dborgian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_path_exec(char **matrix)
{
	int	x;

	x = -1;
	while (matrix[++x])
		free (matrix[x]);
	free(matrix);
}
