/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:00:12 by nesdebie          #+#    #+#             */
/*   Updated: 2023/10/02 11:10:59 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/cub3d.h>

int args_error(int ac, char *filename)
{
    if (ac == 2)
    {
        ft_putstr_fd("error: cub3d: ", 2);
        ft_putstr_fd(filename, 2);
        ft_putendl_fd(" is not a valid file.", 2);
        ft_putendl_fd("./cub3d <file>.cub", 2);
    }
    if (ac < 2)
	    ft_putendl_fd("error: cub3d: no argument", 2);
    if (ac > 2)
	    ft_putendl_fd("error: cub3d: too many arguments", 2);
	return (1);
}