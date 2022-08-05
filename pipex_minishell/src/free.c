/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoullel <atoullel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 23:59:26 by atoullel          #+#    #+#             */
/*   Updated: 2022/08/02 14:38:09 by atoullel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_pipes(t_pipex *pipex, int except1, int except2)
{
	int	i;

	i = 0;
	while (i < (pipex->pipe_nbr))
	{
		if (pipex->pipefd[i] != except1 && pipex->pipefd[i] != except2)
			close(pipex->pipefd[i]);
		i++;
	}
}

void	free_p_process(t_pipex *pipex)
{
	int	x;

	x = 0;
	if (pipex->infile != -1)
		close(pipex->infile);
	if (pipex->outfile != -1)
		close(pipex->outfile);
	while (pipex->path_list && pipex->path_list[x])
	{
		free(pipex->path_list[x]);
		x++;
	}
	free(pipex->path_list);
	free(pipex->pipefd);
}

void	free_c_process(t_pipex *pipex)
{
	int	x;
	/*
	x = 0;

	while (pipex->cmd_arguments[x])
	{
		free(pipex->cmd_arguments[x]);
		x++;
	}
	 */
	free(pipex->cmd_arguments);
	free(pipex->cmd);
	x = 0;
	while (pipex->path_list && pipex->path_list[x])
	{
		free(pipex->path_list[x]);
		x++;
	}
	free(pipex->path_list);
	free(pipex->pipefd);
}
