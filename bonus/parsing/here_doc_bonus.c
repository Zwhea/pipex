/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:44:48 by wangthea          #+#    #+#             */
/*   Updated: 2023/01/18 13:41:07 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	is_here_doc(char *av, t_pipex *data)
{
	if (av && ft_strncmp("here_doc", av, 9) == 0)
		data->here_doc = true;
	data->here_doc = false;
}

void	get_here_doc(char *av, t_pipex *data)
{
	int file;
	char *buff;

	file = open("here_doc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (file == -1)
		perror("open");
	while(1)
	{
		ft_dprintf(1, "here_doc> ");
		if ((buff = get_next_line(0)) < 0)
			exit(1);
		if (!ft_strncmp(av, buff, ft_strlen(buff) - 1))
			break ;
		ft_dprintf(file,"%s\n", buff);
		free(buff);
	}
	free(buff);
	close(file);
	data->infile = open("here_doc", O_RDONLY);
	if (data->infile == -1)
	{
		unlink("here_doc");
		perror("open");
	}
}
