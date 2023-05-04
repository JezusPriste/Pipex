/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborgian <dborgian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:37:29 by dborgian          #+#    #+#             */
/*   Updated: 2023/05/04 17:34:46 by dborgian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <signal.h>

typedef struct s_pipex
{
	int		fd_in;
	int		fd_out;
	char	*cmd1;
	char	*cmd2;
	int		pipedfd[2];
	char	*tmp;
	char	**tmp_matrix;
	char	**argv2;
	char	**argv3;
	char	*tmp1;
	char	**tmp_matrix1;
	int		pid1;
	int		pid2;
	char	**path_exec;
	char	*find_exec;
	int		flag;
	char	*slash;

}	t_pipex;

void			check_argv(t_pipex *pipex, char **argv, char **envp);
int				strlen_matrix(char **temp_matrix);
char			**moving_matrix(t_pipex *pipex, char **final_matrix,
					char **temp_matrix, char **envp);
void			handle_child1(t_pipex *pipex);
int				children(t_pipex *pipex);
char			*search_path(t_pipex *pipex, char *tmp, char **envp);
char			*extract_path(char *dst, char *src);
char			*finder_exec(t_pipex *pipex, char *tmp, char *path);
void			free_path_exec(char **path_exec);
char			*cleaner(char *temp);
void			assignment(t_pipex *pipex, int i, char *temp);
//cleaers
void			cleaner1(char **matrix);
void			cancel(t_pipex *pipex);
//libft
char			*ft_strjoin(char const *s1, char const *s2,
					int free1, int free2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			*ft_calloc(size_t count, size_t size);
void			ft_bzero(void *s, size_t n);
char			*ft_strdup(const char *s1);
size_t			ft_strlen(const char *str);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			ft_putstr_fd(char *s, int fd);
//split
int				ft_strcheck(char const *s, char c);
void			*ft_cicle(char const *s, char **str, char c,
					unsigned int count);
char			**ft_split(char const *s, char c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
unsigned int	ft_counter(char const *s, char c);

#endif