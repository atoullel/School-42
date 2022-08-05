/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoullel <atoullel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 20:11:13 by atoullel          #+#    #+#             */
/*   Updated: 2022/08/02 14:31:38 by atoullel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static	char	*find_cmd_path(char **paths, char *command, char *cmd_path,
	char *tmp)
{
	while (paths && *paths)
	{
		cmd_path = ft_strjoin(*paths, command);
		free(tmp);
		tmp = cmd_path;
		if (access(cmd_path, 0) == 0)
		{
			free(command);
			return (cmd_path);
		}
		paths++;
	}
	free(command);
	return (cmd_path);
}

static	char	*check_cmd_path(t_pipex *pipex)
{
	char	**paths;
	char	*command;
	char	*cmd_path;
	char	*tmp;

	if (!(pipex->cmd_arguments) || !(pipex->cmd_arguments[0]))
	{
		cmd_path = ft_strjoin("", "");
		return (cmd_path);
	}
	command = ft_strjoin("/", pipex->cmd_arguments[0]);
	paths = pipex->path_list;
	cmd_path = ft_strjoin("", pipex->cmd_arguments[0]);
	tmp = cmd_path;
	if (access(cmd_path, 0) == 0)
	{
		free(command);
		return (cmd_path);
	}
	return (find_cmd_path(paths, command, cmd_path, tmp));
}

static int	fill_matrix(char **matrix, t_list *list, int i)
{
	while (list->next)
		matrix[i++] = (char *)list->content;
	matrix[i++] = (char *)list->content;
	return (i);
}
static void	create_cmd_args(t_command *var, t_pipex *pipex)
{
	int size;
	int i;

	i = 1;
	size = 1 + ft_lstsize(var->options) + ft_lstsize(var->arguments);
	pipex->cmd_arguments = (char **)malloc(sizeof(char *) * (size + 1));
	if (!(pipex->cmd_arguments))
		return ;
	pipex->cmd_arguments[size + 1] = NULL;
	pipex->cmd_arguments[0] = var->command;
	if (var->options)
		i = fill_matrix(pipex->cmd_arguments, var->options, i);
	if (var->arguments)
		fill_matrix(pipex->cmd_arguments, var->arguments i);
}

void	child(t_pipex pipex, t_command *var, char *envp[])
{
	/* Create a function to check for dup2 with the lines below*/
	int except1;
	int except2;

	except1 = -1;
	except2 = -1;
	if (var->infile)/*Checks if there's an infile to dup*//*Else just to regular dup*/
		dup2(var->infile_fd, 0);
	else
	{
		dup2(pipex.pipefd[2 * pipex.id - 2], 0);
		except1 = 2 * pipex.id - 2;
	}
	if (var->outfile)/*Check if there's an outfile to dup*//*Else just to regular dup unless it's the last command*/
		dup2(var->outfile_fd, 1);
	else if (var->next)
	{
		dup2(pipex.pipefd[2 * pipex.id + 1], 1);
		except2 = 2 * pipex.id + 1;
	}
	close_pipes(&pipex, except1, except2);
	pipex.cmd_arguments = create_cmd_args(var, pipex);
	pipex.cmd = check_cmd_path(&pipex);// ------------------------------------------------------------------------------------
	/* Create a function to check FD errors with the lines below*/
	if (var->infile)
	{
		if (var->infile_fd == -1)
		{
			free_c_process(&pipex);
			exit (1);
		}
	}
	if (var->outfile)
	{
		if (var->outfile_fd == -1)
		{
			free_c_process(&pipex);
			exit (1);
		}
	}// ----------------------------------------------------------------------------------------------------------------------
	execve(pipex.cmd, pipex.cmd_arguments, envp);
	perror(pipex.cmd);
	free_c_process(&pipex);
	exit(1);
}
