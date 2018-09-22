/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 18:58:05 by fchanal           #+#    #+#             */
/*   Updated: 2017/06/16 19:19:09 by fchanal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H

# include "./../../includes/libft.h"
# include "./minilibx/mlx.h"
# define VISU_SQUARE_AREA	13
# define VISU_COLOR_GRID	0x424242
# define VISU_COLOR_P1		0x9456AB
# define VISU_COLOR_P2		0xFFD7B7

typedef struct s_img	t_img;
typedef struct s_env	t_env;
typedef struct s_coord	t_coord;

struct	s_coord
{
	int		x;
	int		y;
};

struct	s_img
{
	void	*ptr;
	char	*str;
	int		bpp;
	int		s_l;
	int		endian;
};

struct	s_env
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_coord		map;
	t_coord		win_size;
	bool		stop;
	useconds_t	speed;
};

void	visu_put_grid(const t_env *env);
void	visu_put_square(const t_env *env, int x, int y, int color);
int		visu_fill_grid(const t_env *env);
void	visu_img_put(char *img, int s_l, t_coord pos, int color);
int		visu_get_img_color(const char *str, int s_l, int x, int y);
int64_t	ft_get(const char **s);

#endif
