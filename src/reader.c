/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:34:57 by nesdebie          #+#    #+#             */
/*   Updated: 2023/10/02 14:38:37 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	ft_freesplit(char **arr)
{
	int i;

	i = 0;
	while (arr[i] != 0)
		free(arr[i++]);
	free(arr[i]);
	free(arr);
}

static int	parse_texture(t_game *game, char *line)
{
	char	**arr;
	int		ret;

	ret = 0;
	arr = ft_split(line, ' ');
	if (!arr)
		return(1);
	if (arr[2] != 0)
	{
		ft_freesplit(arr);
		return (1);
	}
	if (!ft_strncmp(arr[0], "NO", 3))
		ret = add_no(game, arr); //ADD NO
	else if (!ft_strncmp(arr[0], "SO", 3))
		ret = add_so(game, arr); // ADD SO
	else if (!ft_strncmp(arr[0], "WE", 3))
		ret = add_we(game, arr); // ADD WE
	else if (!ft_strncmp(arr[0], "EA", 3))
		ret = add_ea(game, arr); // ADD EA
	else if (!ft_strncmp(arr[0], "f", 2))
		ret = add_fc(game, arr, 'f'); // ADD f
	else if (!ft_strncmp(arr[0], "c", 2))
		ret = add_fc(game, arr, 'c'); // ADD c
	ft_freesplit(arr);
	return (ret);
}

int read_file(t_game *game, char *filename)
{
	int fd;
	char *tmp;

	fd = open(filename, O_RDONLY);
	if (fd < 1)
		return (1);
	tmp = get_next_line(fd);
	while (tmp && game->flags.cnt < 6)
	{
		if (tmp[0] != '\n')
		{
			if (parse_texture(game, tmp))
			{
				free(tmp);
				return (1);
			}
		}
		free (tmp);
		tmp = get_next_line(fd);
	}
	free (tmp);
	close(fd);
	return (0);
}