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
		i = fill_table(pipex->cmd_arguments, var->options, i);
	if (var->arguments)
		fill_table(pipex->cmd_arguments, var->arguments i);
}
void	first_child(t_pipex pipex, char *argv[], char *envp[])
{
	dup2(pipex.pipefd[1], 1);
	dup2(pipex.infile, 0);
	close_pipes(&pipex, 1, -1);
	pipex.cmd_arguments = ft_split(argv[2], ' ');
	pipex.cmd = check_cmd_path(&pipex);
	if (pipex.infile == -1)
	{
		free_c_process(&pipex);
		exit (1);
	}
	execve(pipex.cmd, pipex.cmd_arguments, envp);
	perror(pipex.cmd);
	free_c_process(&pipex);
	exit(1);
}

void	child(t_pipex pipex, t_command *var, char *envp[])
{
	if (/*Checks if there's an infile to dup*/
		/*Else just to regular dup*/)
	{

	}
	else
		dup2(pipex.pipefd[2 * pipex.id - 2], 0);
	if (/*Check if there's an outfile to dup*/
		/*Else just to regular dup unless it's the last command*/)
	{

	}
	else
		dup2(pipex.pipefd[2 * pipex.id + 1], 1);
	close_pipes(&pipex, -1, -1);
	pipex.cmd_arguments = create_cmd_args(var, pipex);
	pipex.cmd = check_cmd_path(&pipex);
	/* Create a function to check FD errors with the lines below*/
	if (var->infile->filename)
	{
		if (pipex.outfile == -1)
		{
			free_c_process(&pipex);
			exit (1);
		}
	}
	if (var->outfile->filename)
	{
		if (pipex.outfile == -1)
		{
			free_c_process(&pipex);
			exit (1);
		}
	}
	execve(pipex.cmd, pipex.cmd_arguments, envp);
	perror(pipex.cmd);
	free_c_process(&pipex);
	exit(1);
}
void	inner_child(t_pipex pipex, char *arg, char *envp[])
{
	dup2(pipex.pipefd[2 * pipex.id - 2], 0);
	dup2(pipex.pipefd[2 * pipex.id + 1], 1);
	close_pipes(&pipex, -1, -1);
	pipex.cmd_arguments = ft_split(arg, ' ');
	pipex.cmd = check_cmd_path(&pipex);
	execve(pipex.cmd, pipex.cmd_arguments, envp);
	perror(pipex.cmd);
	free_c_process(&pipex);
	exit(1);
}

void	last_child(t_pipex pipex, char *argv[], char *envp[])
{
	dup2(pipex.pipefd[2 * pipex.id - 2], 0);
	dup2(pipex.outfile, 1);
	close_pipes(&pipex, (2 * pipex.id - 2), -1);
	pipex.cmd_arguments = ft_split(argv[pipex.cmd_nbr + 1], ' ');
	pipex.cmd = check_cmd_path(&pipex);
	if (pipex.outfile == -1)
	{
		free_c_process(&pipex);
		exit (1);
	}
	execve(pipex.cmd, pipex.cmd_arguments, envp);
	perror(pipex.cmd);
	free_c_process(&pipex);
	exit(1);
}
