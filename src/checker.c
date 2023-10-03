/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:07:18 by nesdebie          #+#    #+#             */
/*   Updated: 2023/10/03 16:40:27 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int isinset(char c, char *set)
{
    int i;

    i = 0;
    while (set[i])
    {
        if (c == set[i])
            return (0);
        i++;
    }
    return (1);
}

int check_chars(char *str)
{
    int i;
    int nb_pl;

    i = 0;
    nb_pl = 0;
    while (str[i])
    {
        if (isinset(str[i], " \n01NSEW"))
            return (checker_error(INVALID_CHAR));
        if (!isinset(str[i], "NSEW"))
            nb_pl++;
        if (nb_pl > 1)
            return (checker_error(TWO_PLAYER));
        i++;
    }
    if (!nb_pl)
        return (checker_error(NO_PLAYER));
    return (0);
}

int check_walls(char **map)
{
    (void)map;
    return (0);
}

char    *ft_space_line(size_t size)
{
    size_t     i;
    char    *line;

    i = 0;
    line = malloc(sizeof(char) * size + 1);
    if (!line)
        return (NULL);
    while (i < size)
    {
        line[i] = ' ';
        i++;
    }
    line[i] = 0;
    return (line);
}

void    ft_resize(char **arr, size_t size)
{
    size_t     i;
    char    *tmp;

    i = 0;
    while (arr[i])
    {
        tmp = ft_space_line(size - ft_strlen(arr[i]));
        if (!tmp)
        {
            ft_freesplit(arr);
            break ;
        }
        arr[i] = ft_strjoingnl(arr[i], tmp);
        free (tmp);
        if (!arr[i])
            break ;
        i++;
    }
}

int resize_array(char **map)
{
    int     i;
    size_t  biggest;
    size_t  tmp;

    i = 0;
    biggest = 0;
    while (map[i])
    {
        tmp = ft_strlen(map[i]);
        if (tmp > biggest)
            biggest = tmp;
        i++;
    }
    ft_resize(map, biggest);
    if (!map)
        return (1);
    return (0);
}

int check_params(t_game *game)
{
    if (check_chars(game->map_str))
        return (1);
    game->map = ft_split(game->map_str, '\n');
    if (!game->map)
        return (reader_error(MALLOC_ERROR));
    if (resize_array(game->map))
        return (reader_error(MALLOC_ERROR));
    if (check_walls(game->map))
        return (checker_error(NOT_WALLED));
    return (0);
}