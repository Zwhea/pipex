/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:34:34 by wangthea          #+#    #+#             */
/*   Updated: 2023/01/19 17:47:33 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	duplicate_fds(t_pipex *data, int i)
{
	if (i == 0)
	{
		if (dup2(data->infile, STDIN_FILENO) == -1)
			exit(3);
		close(data->infile);
	}
	else
	{
		if (dup2(data->fds[i - 1][0], STDIN_FILENO) == -1)
			exit(3);
		close(data->fds[i - 1][0]);
	}
	if (i == data->nb_of_commands - 1)
	{
		if (dup2(data->outfile, STDOUT_FILENO) == -1)
			exit(3);
		close(data->outfile);
	}
	else
	{
		if (dup2(data->fds[i][1], STDOUT_FILENO) == -1)
			exit(3);
		close(data->fds[i][1]);
	}
}

void	wait_for_process_ids(t_pipex *data)
{
	int	i;
	int status;

	i = 0;
	status = 0;
	while (i < data->nb_of_commands)
	{
 		waitpid(data->process_ids[i], &status, 0);
 		if (WEXITSTATUS(status) && i == data->nb_of_commands - 1)
 			exit(127);
		i++;
	}
}

void	pipex(char **env, t_pipex *data)
{
	int		i;
	char	*command;

	i = 0;
	while (i < data->nb_of_commands)
	{
		if (pipe(data->fds[i]) == -1)
			exit(ft_dprintf(2, "Pipe Issue\n"));
		data->process_ids[i] = fork();
		if (data->process_ids[i] == 0)
		{
			close_fds(data, i);
			duplicate_fds(data, i);
			command = get_command_with_path(env, data->commands[i][0]);
			execve(command, data->commands[i], env);
			exit(1);
		}
		else if (data->process_ids[i] < 0)
		{
			ft_dprintf(2, "Fork Issue: Resource temporarily unavailable\n");
			break ;
		}
		i++;
	}
	close_all_fds(data, i);
}
