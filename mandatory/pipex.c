/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:30:32 by twang             #+#    #+#             */
/*   Updated: 2023/01/19 17:40:30 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	t_pipex	data;

	if (!checks_valid_args(ac, av, &data))
		return (1);
	allocate_array_of_pids(&data);
	allocate_array_of_fds(&data);
	fill_array_of_commands(&data, av);
	pipex(env, &data);
	wait_for_process_ids(&data);
	free_struct(&data);
	return (0);
}
