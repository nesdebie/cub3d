/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <nesdebie@marvin.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:00:12 by nesdebie          #+#    #+#             */
/*   Updated: 2023/10/03 00:48:51 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/cub3d.h>

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

int reader_error(int error)
{
    if (error == FILE_ERROR)
        ft_putendl_fd("error: cub3d: cannot open file", 2);
    else if (error == FORMAT)
        ft_putendl_fd("error: cub3d: invalid file format", 2);
    else if (error == MALLOC)
        ft_putendl_fd("error: cub3d: malloc failed", 2);
    return (1);
}
