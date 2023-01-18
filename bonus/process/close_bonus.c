/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:33:48 by wangthea          #+#    #+#             */
/*   Updated: 2023/01/13 18:48:36 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	close_fds(t_pipex *data, int i)
{
	int	j;

	j = 0;
	while (j < data->nb_of_commands - 1)
	{
		if (j != i - 1)
			close(data->fds[j][0]);
		if (j != i)
			close(data->fds[j][1]);
		j++;
	}
}

void	close_all_fds(t_pipex *data, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		close(data->fds[j][0]);
		close(data->fds[j][1]);
		j++;
	}
}
