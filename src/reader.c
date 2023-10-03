/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:34:57 by nesdebie          #+#    #+#             */
/*   Updated: 2023/10/03 12:42:08 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	parse_texture(t_game *game, char *line, int ret)
{
	char	**arr;

	arr = ft_split(line, ' ');
	if (!arr)
		return (reader_error(MALLOC_ERROR));
	if (arr[1] == 0 || arr[2] != 0)
	{
		ft_freesplit(arr);
		return (reader_error(FORMAT_ERROR));
	}
	if (!ft_strncmp(arr[0], "NO", 3))
		ret = add_no(game, arr);
	else if (!ft_strncmp(arr[0], "SO", 3))
		ret = add_so(game, arr);
	else if (!ft_strncmp(arr[0], "WE", 3))
		ret = add_we(game, arr);
	else if (!ft_strncmp(arr[0], "EA", 3))
		ret = add_ea(game, arr);
	else if (!ft_strncmp(arr[0], "F", 2))
		ret = add_fc(game, arr, 'f');
	else if (!ft_strncmp(arr[0], "C", 2))
		ret = add_fc(game, arr, 'c');
	ft_freesplit(arr);
	return (ret);
}

static int	read_map(t_game *game, char *tmp, int fd)
{
	game->map_str = ft_calloc(1, 1); // TO NORM
	while (tmp && tmp[0] == '\n')
	{
		free (tmp);
		tmp = get_next_line(fd);
	}
    while (tmp)
    {
        if (tmp[0] == '\n')
        {
            free(tmp);
            return (reader_error(FORMAT_ERROR));
        }
		game->map_str = ft_strjoingnl(game->map_str, tmp);
		free(tmp);
		if (!game->map_str)
			return (reader_error(MALLOC_ERROR));
        tmp = get_next_line(fd);
    }
	free (tmp);
	close (fd);
	if (!game->map_str)
		return (reader_error(FORMAT_ERROR));
	return (0);
}

int read_file(t_game *game, char *filename)
{
	int fd;
	char *tmp;

	fd = open(filename, O_RDONLY);
	if (fd < 1)
		return (reader_error(FILE_ERROR));
	tmp = get_next_line(fd);
	while (tmp && game->flags.cnt != 6)
	{
		if (tmp[0] != '\n')
		{
			if (parse_texture(game, tmp, 1))
			{
				free(tmp);
				return (1);
			}
            game->flags.cnt++;
		}
		free (tmp);
		tmp = get_next_line(fd);
	}
	return (read_map(game, tmp, fd));
}
