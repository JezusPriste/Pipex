/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborgian <dborgian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:41:03 by dborgian          #+#    #+#             */
/*   Updated: 2023/05/04 17:25:25 by dborgian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		write(1, "error argc\n", 11);
	if (pipe(pipex.pipedfd) == -1)
		write(1, "error pipe\n", 11);
	pipex.fd_in = open(argv[1], O_RDONLY);
	if (pipex.fd_in == -1)
		write(1, "fd_in error\n", 13);
	pipex.fd_out = open(argv[4], O_TRUNC | O_CREAT | O_RDWR, 0777);
	if (pipex.fd_out == -1)
		write(1, "error fd_out\n", 14);
	check_argv(&pipex, argv, envp);
	if (children(&pipex) < 0)
		return (1);
	close(pipex.pipedfd[0]);
	close(pipex.pipedfd[1]);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	cancel(&pipex);
	return (0);
}

void	check_argv(t_pipex *pipex, char **argv, char **envp)
{
	int	x;
	int	y;

	pipex->tmp = cleaner(argv[2]);
	pipex->tmp_matrix = ft_split(pipex->tmp, ' ');
	x = strlen_matrix(pipex->tmp_matrix);
	pipex->argv2 = ft_calloc((x + 1), sizeof(char *));
	pipex->argv2 = moving_matrix(pipex, pipex->argv2, pipex->tmp_matrix, envp);
	pipex->tmp1 = cleaner(argv[3]);
	pipex->tmp_matrix1 = ft_split(pipex->tmp1, ' ');
	y = strlen_matrix(pipex->tmp_matrix1);
	pipex->argv3 = ft_calloc((y + 1), sizeof(char *));
	pipex->argv3 = moving_matrix(pipex, pipex->argv3, pipex->tmp_matrix1, envp);
}

char	**moving_matrix(t_pipex *pipex, char **final_matrix,
							char **temp_matrix, char **envp)
{
	int		x;
	int		j;
	int		k;
	char	*path;

	x = 1;
	j = 1;
	path = search_path(pipex, temp_matrix[0], envp);
	final_matrix[0] = ft_calloc((ft_strlen(path) + 1), sizeof(char));
	final_matrix[0] = ft_memmove(final_matrix[0], path, ft_strlen(path));
	while (temp_matrix[j])
	{
		k = ft_strlen(temp_matrix[j]);
		final_matrix[x] = malloc((ft_strlen(temp_matrix[j])) * sizeof(char));
		final_matrix[x] = ft_memmove(final_matrix[x], temp_matrix[j], k);
		x++;
		j++;
	}
	final_matrix[j] = NULL;
	free_path_exec(temp_matrix);
	return (final_matrix);
}

char	*cleaner(char *temp)
{
	int	i;

	i = 0;
	while (temp[i++])
	{
		if (temp[i] == '\'' || temp[i] == '\"')
			temp[i] = ' ';
	}
	return (temp);
}

int	strlen_matrix(char **temp_matrix)
{
	int	i;

	i = 0;
	while (temp_matrix[i])
		i++;
	return (i);
}
