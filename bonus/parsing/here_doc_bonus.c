/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:44:48 by wangthea          #+#    #+#             */
/*   Updated: 2023/01/23 10:59:42 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	is_here_doc(char *av, t_pipex *data)
{
	data->here_doc = (av && ft_strncmp("here_doc", av, 9) == 0);
}

void	get_here_doc(char *av, t_pipex *data)
{
	int		file;
	char	*buffer;

	file = open("here_doc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (file == -1)
		perror("open");
	while (1)
	{
		ft_dprintf(1, "here_doc> ");
		buffer = get_next_line(0);
		if (!buffer)
			exit(1);
		if (!ft_strncmp(av, buffer, ft_strlen(buffer) - 1))
			break ;
		ft_dprintf(file, "%s", buffer);
		free(buffer);
	}
	free(buffer);
	close(file);
	data->infile = open("here_doc", O_RDONLY);
	if (data->infile == -1)
	{
		unlink("here_doc");
		perror("open");
	}
}
