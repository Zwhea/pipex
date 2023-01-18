/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:30:32 by twang             #+#    #+#             */
/*   Updated: 2023/01/18 14:07:06 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int ac, char **av, char **env)
{
	t_pipex	data;

	is_here_doc(av[1], &data);
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
