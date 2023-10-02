/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <nesdebie@marvin.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 00:03:27 by nesdebie          #+#    #+#             */
/*   Updated: 2023/10/03 00:07:27 by nesdebie         ###   ########.fr       */
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
	if (game->flags.n_flag)
		free(game->sprites.no);
	if (game->flags.s_flag)
		free(game->sprites.so);
	if (game->flags.e_flag)
		free(game->sprites.ea);
	if (game->flags.w_flag)
		free(game->sprites.we);
	if (game->flags.f_flag)
		free(game->sprites.f);
	if (game->flags.c_flag)
		free(game->sprites.c);
}

void	clear_read(t_game *game)
{
    clear_temp_str(game);
	if (game->map)
		ft_freesplit(game->map);
	free(game);
}