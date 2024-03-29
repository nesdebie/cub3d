/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:11:57 by nesdebie          #+#    #+#             */
/*   Updated: 2023/11/27 11:18:54 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"

# define X	1920
# define Y	1080

# define SPEED 7
# define ROTSPEED 0.07

# define SIZE	64

# define KEY_ESC	53
# define KEY_Q      12

# define KEY_W	13
# define KEY_A	0
# define KEY_S	1
# define KEY_D	2

# define KEY_SPACE	49
# define KEY_M 46

# define KEY_LEFT	123
# define KEY_RIGHT	124
# define KEY_UP	126
# define KEY_DOWN	125

# define RED_CROSS 17
# define PRESS_KEY 2
# define RELEASE_KEY 3

typedef enum s_error
{
	FILE_ERROR,
	FORMAT_ERROR,
	MALLOC_ERROR,
	NO_PLAYER,
	TWO_PLAYER,
	NOT_WALLED,
	INVALID_CHAR,
	TEXTURE_ACCESS,
	TEXTURE_EXTENSION,
	TEXTURE_OPEN,
	RGB_VALUE,
	RGB_FORMAT,
	MLX_WIN,
	MLX_INIT,
	MLX_XPM,
	MLX_IMG
}	t_error;

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		pixel_bits;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_player
{
	float	dir;
	float	pdx;
	float	pdy;
	int		up;
	int		down;
	int		left;
	int		right;
	int		turn_left;
	int		turn_right;
	int		speed_up;
	int		speed_down;
	int		speed;
	char	first_dir;
	float	pos_x;
	float	pos_y;
	float	dir_x;
	float	dir_y;
	float	plane_x;
	float	plane_y;
	int		map;
	t_img	img_player;
}				t_player;

typedef struct s_tx
{
	int				*n;
	int				*s;
	int				*w;
	int				*d;
	int				*e;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*f;
	char			*c;
	unsigned long	f_rgb;
	unsigned long	c_rgb;
}				t_tx;

typedef struct s_flag
{
	int	l_flag;
	int	p_flag;
	int	n_flag;
	int	s_flag;
	int	w_flag;
	int	e_flag;
	int	c_flag;
	int	f_flag;
	int	cnt;
	int	door;
	int	random;
}				t_flag;

typedef struct s_ray
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	wall_dist;
	double	wall_x;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_ray;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*img;
	char		**map;
	int			map_width;
	int			map_height;
	int			**pixels;
	char		*map_str;
	int			held_key;
	int			spacebar;
	int			mouse_x;
	int			mouse_y;
	t_img		wall;
	t_ray		ray;
	t_tx		tx;
	t_flag		flags;
	t_player	player;
}				t_game;

/* ERRORS */
int				args_error(int ac, char *filename);
int				error_msg(int error);
int				xpmfile_error(char *filename, int error);
int				mlx_error(int error);

/* READER */
int				read_file(t_game *game, char *filename, int fd, char *tmp);

/* PARSING */
int				parsing(t_game *game, char *map, int argc);
int				check_params(t_game *game);
int				check_extension(char *filename, char *ext);
int				check_textures(t_game *game);
int				check_nsew(t_game *game);

/* INIT */
int				init_pre_loop(t_game *game);
int				init_wall_textures(t_game *game);
void			init_raycasting(int x, t_ray *ray, t_player *player);
void			init_pov(t_ray *ray);
void			init_img(t_game *game, t_img *image, int width, int height);
void			init_pixels(t_game *game);
void			init_img_clean(t_img *img);

/* FREE */
void			ft_freesplit(char **arr);
int				clear_args(t_game *game);
void			free_tab(void **tab);
void			free_failed_tab(void **tab, int last);

/* TEMP */
int				add_ea(t_game *game, char **arr);
int				add_we(t_game *game, char **arr);
int				add_so(t_game *game, char **arr);
int				add_no(t_game *game, char **arr);
int				add_fc(t_game *game, char **arr, char flag);

/* SETTER */
unsigned long	set_rgb(int r, int g, int b);

/* UTILS */
int				isinset(char c, char *set);
int				resize_array(char **map);
int				onlyint(char *s);

/*Key event*/
void			wait_inputs(t_game *game);
int				key_press(int key_code, t_game *game);
int				key_release(int key_code, t_game *game);
int				close_game(t_game *game);

/* MAP (Hugo)*/
void			display_map(t_game *game, int color);
void			display_player(t_game *game, int x);

/* DISPLAYS (Nestor) */
void			display_pov(t_game *game);
void			set_image_pixel(t_img *image, int x, int y, int color);
void			ft_update_dir(t_game *game);
void			ft_move_player(t_game *game);
int				validate_move(t_game *data, double new_x, double new_y);
void			rotate(t_game *game);
void			raycasting(t_player *player, t_game *game);
void			set_dda(t_ray *ray, t_player *player);
void			dda(t_game *game, t_ray *ray);

#endif