/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:44:48 by wangthea          #+#    #+#             */
/*   Updated: 2023/01/26 13:43:42 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	is_here_doc(char *av, t_pipex *data)
{
	data->here_doc = (av && ft_strncmp("here_doc", av, 9) == 0);
}

void	here_doc_to_file(char *av, int file)
{
	char	*buffer;
	int		av_length;
	int		buffer_length;

	while (1)
	{
		ft_dprintf(1, "here_doc> ");
		buffer = get_next_line(0);
		if (!buffer)
			exit(1);
		av_length = ft_strlen(av);
		buffer_length = ft_strlen(buffer);
		if (!ft_strncmp(av, buffer, buffer_length - 1) \
			&& av_length == buffer_length - 1)
			break ;
		ft_dprintf(file, "%s", buffer);
		free(buffer);
	}
	free(buffer);
}

void	get_here_doc(char *av, t_pipex *data)
{
	int		file;

	file = open("here_doc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (file == -1)
		perror("open");
	here_doc_to_file(av, file);
	close(file);
	data->infile = open("here_doc", O_RDONLY);
	if (data->infile == -1)
	{
		unlink("here_doc");
		perror("open");
	}
}
