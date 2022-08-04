/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoullel <atoullel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 10:54:52 by atoullel          #+#    #+#             */
/*   Updated: 2022/08/02 13:43:08 by atoullel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>

# include <stdio.h>

typedef struct s_pipex
{
	int		*pipefd;
	int		cmd_nbr;
	int		pipe_nbr;
	int		id;
	pid_t	pidn;
	char	*env_paths;
	char	**path_list;
	char	**cmd_arguments;
	char	*cmd;

}					t_pipex;
void	close_pipes(t_pipex *pipex, int except1, int except2);
/* FREE */
void	free_p_process(t_pipex *pipex);
void	free_c_process(t_pipex *pipex);
/* CHILDS */
void	first_child(t_pipex pipex, char *argv[], char *envp[]);
void	inner_child(t_pipex pipex, char *arg, char *envp[]);
void	last_child(t_pipex pipex, char *argv[], char *envp[]);
/*ERR*/
void	err_message(int fd, char *msg);
/*FUNCTIONS*/
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *str);
#endif //PIPEX_H