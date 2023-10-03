/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 00:03:27 by nesdebie          #+#    #+#             */
/*   Updated: 2023/10/03 13:12:16 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_freesplit(char **arr)
{
	int i;

	i = 0;
	while (arr[i] != 0)
		free(arr[i++]);
	free(arr[i]);
	free(arr);
}

void    clear_temp_str(t_game *game)
{
	if (game->flags.n_flag > 0)
		free(game->sprites.no);
	if (game->flags.s_flag > 0)
		free(game->sprites.so);
	if (game->flags.e_flag > 0)
		free(game->sprites.ea);
	if (game->flags.w_flag > 0)
		free(game->sprites.we);
	if (game->flags.f_flag > 0)
		free(game->sprites.f);
	if (game->flags.c_flag > 0)
		free(game->sprites.c);
    if (game->map_str)
		free(game->map_str);
}