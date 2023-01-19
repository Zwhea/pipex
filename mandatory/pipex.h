/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:31:52 by twang             #+#    #+#             */
/*   Updated: 2023/01/19 17:41:59 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../libft/libft.h"
# include <sys/wait.h>
# include <errno.h>
# include <string.h>
# include <stdbool.h>
# include <stdio.h>

typedef struct s_pipex
{
	char	***commands;
	int		nb_of_commands;
	int		**fds;
	pid_t	*process_ids;
	int		infile;
	int		outfile;
}	t_pipex;

/*-------------------------------------------------------------------parsing--*/

bool	checks_valid_args(int ac, char **av, t_pipex *data);
char	*get_command_with_path(char **env, char *command);

/*------------------------------------------------------------fill structure--*/

void	fill_array_of_commands(t_pipex *data, char **av);
void	allocate_array_of_fds(t_pipex *data);
void	allocate_array_of_pids(t_pipex *data);
void	free_struct(t_pipex *data);

/*---------------------------------------------------------------------pipex--*/

void	pipex(char **env, t_pipex *data);
void	close_fds(t_pipex *data, int i);
void	close_all_fds(t_pipex *data, int i);
void	wait_for_process_ids(t_pipex *data);

#endif