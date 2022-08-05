/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoullel <atoullel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 10:54:41 by atoullel          #+#    #+#             */
/*   Updated: 2022/08/02 19:03:15 by atoullel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_cmdlstsize(t_command *lst)
{
	int	size;

	size = 1;
	if (!lst)
		return (0);
	while (lst->next)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

static	void	find_env_path(t_pipex *pipex, char *envp[])
{
	if (!(*envp))
	{
		pipex->env_paths = NULL;
		return ;
	}
	while ((ft_strncmp(*envp, "PATH", 4) != 0) && *envp)
		envp++;
	pipex->env_paths = *envp + 5;
}

static	void	clean_parent(t_pipex *pipex)
{
	close_pipes(pipex, -1, -1);
	while (1)
	{
		pipex->pidn = wait(0);
		if (pipex->pidn <= 0)
			break ;
	}
	free_p_process(pipex);
}

static void	creat_pipes(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->cmd_nbr - 1)
	{
		if (pipe(pipex->pipefd + 2 * i) != 0)
			clean_parent(pipex);
		i++;
	}
}

static void	iterate_child(t_pipex pipex, t_command *var, char *envp[])
{
	/* IF BUILT IN COMMAND ==> execute that command and then begin iteration*/
	int	file_err;

	pipex.id = -1;
	while ((pipex.id)++ < pipex.cmd_nbr)
	{
		file_err = 0;
		if (var->infile)
		{
			var->infile_fd = open(var->infile->filename, O_RDONLY);
			if (access(var->infile->filename, R_OK))
			{
				perror(var->infile->filename);
				file_err = 1;
			}
		}
		if (var->outfile)
		{
			if (var->outfile->is_append)
				var->outfile_fd = open(var->outfile->filename, O_APPEND | O_CREAT | O_RDWR, 0000644);
			else
				var->outfile_fd = open(var->outfile->filename, O_TRUNC | O_CREAT | O_RDWR, 0000644);
			if (file_err && access(var->outfile->filename, W_OK))
				perror(var->outfile->filename);
		}
		pipex.pidn = fork();
		if (pipex.pidn == 0)
			child(pipex, var, envp);
		var = var->next;
	}
}

int	main(t_command *var, char *envp[])
{
	t_pipex	pipex;

	pipex.cmd_nbr = ft_cmdlstsize(var);
	pipex.pipe_nbr = 2 * (pipex.cmd_nbr - 1);
	/* Check if first command is a built in to know if I need to remove 1 command for the pipes*/
	while (built in list exists)/* -------------------------------------------------pseudo code */
	{
		if (ft_strncmp(var->command, built_in++, ft_strlen(var->command)) == 0)
		{
			execute command;
			pipex.cmd_nbr -= 1;
			pipex.pipe_nbr -= 1;
		}
	}/* ----------------------------------------------------------------------------------------*/
	pipex.pipefd = (int *)malloc(sizeof(int) * pipex.pipe_nbr);
	if (!pipex.pipefd)
		err_message(1, "Pipe malloc err\n");
	find_env_path(&pipex, envp);
	pipex.path_list = ft_split(pipex.env_paths, ':');
	creat_pipes(&pipex);
	iterate_child(pipex, var, envp);
	clean_parent(&pipex);
	return (0);
}
