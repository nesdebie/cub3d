/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:00:12 by nesdebie          #+#    #+#             */
/*   Updated: 2023/10/03 15:54:39 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int args_error(int ac, char *filename)
{
	ft_putstr_fd("error: cub3d: ", 2);
	if (ac == 2)
	{
		ft_putstr_fd(filename, 2);
		ft_putendl_fd(" is not a valid file.", 2);
	}
	if (ac < 2)
		ft_putendl_fd("no argument", 2);
	if (ac > 2)
		ft_putendl_fd("too many arguments", 2);
	ft_putendl_fd("./cub3d <file>.cub", 2);
	return (1);
}

int checker_error(int error)
{
	if (error == NO_PLAYER)
		ft_putendl_fd("error: cub3d: player not found", 2);
	else if (error == TWO_PLAYER)
		ft_putendl_fd("error: cub3d: too many players found", 2);
	else if (error == NOT_WALLED)
		ft_putendl_fd("error: cub3d: map not walled", 2);
    else if (error == INVALID_CHAR)
		ft_putendl_fd("error: cub3d: invalid char", 2);  
    return (1);
}

int reader_error(int error)
{
	if (error == FILE_ERROR)
		ft_putendl_fd("error: cub3d: cannot open file", 2);
	else if (error == FORMAT_ERROR)
		ft_putendl_fd("error: cub3d: invalid file format", 2);
	else if (error == MALLOC_ERROR)
		ft_putendl_fd("error: cub3d: malloc failed", 2);
	return (1);
}
