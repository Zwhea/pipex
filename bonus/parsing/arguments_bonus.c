/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 09:56:06 by twang             #+#    #+#             */
/*   Updated: 2023/01/18 13:43:58 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static bool	check_args(int ac, t_pipex *data)
{	
	if (ac < 5)
	{
		ft_dprintf(2, "error: invalid number of arguments");
		ft_dprintf(2, "usage: ./pipex infile \"cmd1\" \"cmd2\" outfile");
		return (false);
	}
	data->nb_of_commands = ac - 3 - data->here_doc;
	return (true);
}

static void	checks_files(int ac, char **av, t_pipex *data)
{
	if (!ft_strncmp("here_doc", av[1], 9))
	{
		get_here_doc(av[2], data);
		data->outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (data->outfile == -1)
			perror("open");
	}
	else
	{
		data->infile = open(av[1], O_RDONLY, 0644);
		if (data->infile == -1)
			perror("open");
		data->outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (data->outfile == -1)
			perror("open");
	}
}

bool	checks_valid_args(int ac, char **av, t_pipex *data)
{
	if (!check_args(ac, data))
		return (false);
	checks_files(ac, av, data);
	return (true);
}
