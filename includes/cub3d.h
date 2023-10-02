/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:11:57 by nesdebie          #+#    #+#             */
/*   Updated: 2023/10/02 11:59:16 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <../mlx/mlx.h>
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

typedef	struct	s_spr
{
	void	*no;
	void	*so;
	void	*we;
	void	*ea;
	int		f[3];
	int		c[3];
}				t_spr;


typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	t_spr	sprites;

}				t_game;

/* ERRORS */
int args_error(int ac, char *filename);

#endif