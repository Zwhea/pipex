/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:10:05 by wangthea          #+#    #+#             */
/*   Updated: 2023/01/18 13:55:27 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	allocate_array_of_pids(t_pipex *data)
{
	data->process_ids = ft_calloc(data->nb_of_commands, sizeof(pid_t));
	if (!data->process_ids)
	{
		ft_dprintf(2, "Allocation Issue: process ids\n");
		exit(2);
	}
}

void	allocate_array_of_fds(t_pipex *data)
{
	int	i;

	data->fds = ft_calloc(data->nb_of_commands, sizeof(int *));
	if (!data->fds)
	{
		ft_dprintf(2, "Allocation Issue: fds\n");
		exit(2);
	}
	i = 0;
	while (i < data->nb_of_commands)
	{
		data->fds[i] = ft_calloc(2, sizeof(int));
		if (!data->fds[i])
		{
			ft_dprintf(2, "Allocation Issue: fds[i]\n");
			exit(2);
		}
		i++;
	}
}

void	fill_array_of_commands(t_pipex *data, char **av)
{
	int	i;

	data->commands = ft_calloc(data->nb_of_commands, sizeof(char ***));
	if (!data->commands)
	{
		ft_dprintf(2, "Allocation Issue: commands\n");
		exit(2);
	}
	i = 0;
	while (i < data->nb_of_commands)
	{
		data->commands[i] = ft_split(av[i + 2 + data->here_doc], ' ');
		if (!data->commands[i])
		{
			ft_dprintf(2, "Allocation Issue: commands[i]\n");
			exit(2);
		}
		i++;
	}
}

void	free_struct(t_pipex *data)
{
	int	i;

	free(data->process_ids);
	ft_free((void **) data->fds, data->nb_of_commands);
	i = 0;
	while (i < data->nb_of_commands)
	{
		ft_free((void **) data->commands[i], data->nb_of_commands);
		i++;
	}
	free(data->commands);
}
