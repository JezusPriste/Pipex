/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborgian <dborgian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:33:13 by dborgian          #+#    #+#             */
/*   Updated: 2023/05/04 17:27:24 by dborgian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*search_path(t_pipex *pipex, char *tmp, char **envp)
{
	int		i;
	char	*res;
	char	*final_path;

	i = 0;
	res = NULL;
	while (envp[i++])
	{
		if (ft_strncmp("PATH", envp[i], 4) == 0)
			break ;
	}
	res = extract_path(res, envp[i]);
	res = finder_exec(pipex, tmp, res);
	final_path = ft_strdup(res);
	free(res);
	return (final_path);
}

char	*extract_path(char *dst, char *src)
{
	size_t	i;
	size_t	j;
	size_t	k;

	j = 0;
	i = 0;
	k = 0;
	if (!dst && !src)
		return (NULL);
	while (src[i] != '=')
		i++;
	i++;
	while (src[k])
		k++;
	dst = ft_calloc((k - i + 1), sizeof(char));
	while (src[i])
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	return (dst);
}

char	*finder_exec(t_pipex *pipex, char *tmp, char *path)
{
	int		i;

	i = 0;
	pipex->path_exec = ft_split(path, ':');
	while (pipex->path_exec[i++])
	{
		assignment(pipex, i, tmp);
		if (!access(pipex->find_exec, 0))
		{
			free(pipex->path_exec[i]);
			pipex->path_exec[i] = ft_strdup(pipex->find_exec);
			free(pipex->find_exec);
			pipex->flag = 1;
			break ;
		}
		free(pipex->find_exec);
	}
	pipex->find_exec = ft_strdup(pipex->path_exec[i]);
	free_path_exec(pipex->path_exec);
	free(tmp);
	free(path);
	if (pipex->flag)
		return (pipex->find_exec);
	perror("command not found");
	return (NULL);
}

void	assignment(t_pipex *pipex, int i, char *temp)
{
	pipex->slash = "/";
	pipex->path_exec[i] = ft_strjoin(pipex->path_exec[i],
			pipex->slash, 1, 0);
	pipex->find_exec = ft_strjoin(pipex->path_exec[i],
			temp, 0, 0);
}
