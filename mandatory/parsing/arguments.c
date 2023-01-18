/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 09:56:06 by twang             #+#    #+#             */
/*   Updated: 2023/01/13 16:52:57 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static bool	check_args(int ac, t_pipex *data)
{	
	if (ac != 5)
	{
		ft_putendl_fd("error: invalid number of arguments", 2);
		ft_putendl_fd("usage: ./pipex infile \"cmd1\" \"cmd2\" outfile", 2);
		return (false);
	}
	data->nb_of_commands = ac - 3;
	return (true);
}

static void	checks_files(int ac, char **av, t_pipex *data)
{
	data->infile = open(av[1], O_RDONLY, 0644);
	if (data->infile == -1)
		perror("open");
	data->outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->outfile == -1)
		perror("open");
}

bool	checks_valid_args(int ac, char **av, t_pipex *data)
{
	if (!check_args(ac, data))
		return (false);
	checks_files(ac, av, data);
	return (true);
}
