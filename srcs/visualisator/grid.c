/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 18:54:37 by fchanal           #+#    #+#             */
/*   Updated: 2017/06/16 19:18:17 by fchanal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	visu_put_square(const t_env *env, int x, int y, int color)
{
	uint8_t		line;
	uint8_t		col;
	t_coord		pos;

	line = VISU_SQUARE_AREA;
	while (--line)
	{
		col = VISU_SQUARE_AREA;
		while (--col)
		{
			if (line != VISU_SQUARE_AREA && col != VISU_SQUARE_AREA)
			{
				pos.x = x + col;
				pos.y = y + line;
				visu_img_put(env->img.str, env->win_size.x, \
						pos, color);
			}
		}
	}
}

void	visu_put_grid(const t_env *env)
{
	int		c;
	int		c2;
	int		width;
	int		height;

	c = 0;
	c2 = 0;
	height = env->map.y;
	while (height--)
	{
		width = env->map.x;
		while (width--)
		{
			visu_put_square(env, c, c2, VISU_COLOR_GRID);
			c += VISU_SQUARE_AREA;
		}
		c = 0;
		c2 += VISU_SQUARE_AREA;
	}
}
