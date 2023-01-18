/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:33:48 by wangthea          #+#    #+#             */
/*   Updated: 2023/01/12 19:55:35 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_fds(t_pipex *data, int i)
{
	if (i <= 0)
		return ;
	else if (i == 1)
		close(data->fds[i - 1][1]);
	else
	{
		close(data->fds[i - 1][1]);
		close(data->fds[i - 2][0]);
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
