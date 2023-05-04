/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborgian <dborgian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:58:34 by dborgian          #+#    #+#             */
/*   Updated: 2023/05/03 16:58:34 by dborgian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	children(t_pipex *pipex)
{
	pipex->pid1 = fork();
	if (pipex->pid1 < 0)
	{
		ft_putstr_fd("error forking 1\n", 1);
		return (-1);
	}
	if (pipex->pid1 == 0)
	{
		handle_child1(pipex);
	}
	pipex->pid2 = fork();
	if (pipex->pid2 < 0)
	{
		ft_putstr_fd("error forking 2\n", 1);
		return (-1);
	}
	if (pipex->pid2 == 0)
	{
		dup2(pipex->pipedfd[0], 0);
		dup2(pipex->fd_out, 1);
		close(pipex->pipedfd[1]);
		execve(pipex->argv3[0], pipex->argv3, NULL);
	}
	return (1);
}

void	cancel(t_pipex *pipex)
{
	close(pipex->fd_out);
	close(pipex->fd_in);
	free_path_exec(pipex->argv2);
	free_path_exec(pipex->argv3);
}

void	handle_child1(t_pipex *pipex)
{
	close(pipex->pipedfd[0]);
	dup2(pipex->pipedfd[1], 1);
	dup2(pipex->fd_in, 0);
	execve(pipex->argv2[0], pipex->argv2, NULL);
}
