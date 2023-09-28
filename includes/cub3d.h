/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <nesdebie@marvin.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:11:57 by nesdebie          #+#    #+#             */
/*   Updated: 2023/09/28 08:22:55 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include "../libft/libft.h"

# define NO_MOVE	0
# define DOWN		1
# define LEFT		2
# define UP			3
# define RIGHT		4

# define KEY_ESC	53
# define KEY_Q      12

# define KEY_W	13
# define KEY_A	0
# define KEY_S	1
# define KEY_D	2

# define KEY_LEFT	123
# define KEY_RIGHT	124

# define RED_CROSS 17
# define PRESS_KEY 2
# define RELEASE_KEY 3

typedef struct s_flags
{
	int		held_keys;
}			t_flags;

typedef struct s_check
{
	int				x;
	int				y;
	struct s_check	*next;
}			t_check;

typedef struct s_img
{
	void	*ptr;
	int		h;
	int		w;
}			t_img;

typedef struct s_coord
{
	int		x;
	int		y;
}			t_coord;

typedef struct s_tile
{
	t_img	N;
	t_img	S;
	t_img	E;
	t_img	W;
}			t_tile;

typedef struct s_player
{
	int		step;
	int		item;
}			t_player;

typedef struct s_map
{
	int		rows;
	int		cols;
	char	**coord;
	char	*file;
}			t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_img		img64;
	t_tile		tile;
	t_player	player;
	t_coord		dir2coord[5];
	t_map		maps;
	t_check		*check;
	t_flags		flag;
}				t_game;

#endif