/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_play.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 18:34:02 by fchanal           #+#    #+#             */
/*   Updated: 2017/06/16 19:30:29 by fchanal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static uint8_t		fl_count_around(t_fl_env *fl_env, t_coord pos)
{
	uint8_t		collision;

	collision = 0;
	if (pos.y - 1 >= 0)
		if (fl_env->board[pos.y - 1][pos.x] != fl_env->player_sign \
				&& fl_env->board[pos.y - 1][pos.x] != '.')
			++collision;
	if (pos.x - 1 >= 0)
		if (fl_env->board[pos.y][pos.x - 1] != fl_env->player_sign && \
				fl_env->board[pos.y][pos.x - 1] != '.')
			++collision;
	if (pos.y + 1 < fl_env->board_size.y)
		if (fl_env->board[pos.y + 1][pos.x] != fl_env->player_sign && \
				fl_env->board[pos.y + 1][pos.x] != '.')
			++collision;
	if (pos.x + 1 < fl_env->board_size.x)
		if (fl_env->board[pos.y][pos.x + 1] != fl_env->player_sign && \
				fl_env->board[pos.y][pos.x + 1] != '.')
			++collision;
	return (collision);
}

static uint8_t		fl_count_collision(t_fl_env *fl_env, t_coord pos)
{
	t_coord		tmp;
	uint8_t		collision;

	tmp = fl_env->piece_start;
	collision = 0;
	while (tmp.y < fl_env->piece_size.y)
	{
		while (tmp.x < fl_env->piece_size.x)
		{
			if (fl_env->piece[tmp.y][tmp.x] == '*')
				collision += fl_count_around(fl_env, pos);
			++tmp.x;
			++pos.x;
		}
		pos.x -= fl_env->piece_size.x;
		tmp.x = 0;
		++pos.y;
		++tmp.y;
	}
	return (collision);
}

static t_coord		fl_find_best_cell(t_fl_env *fl_env)
{
	t_coord		pos;
	t_coord		best_cell;
	uint8_t		collision[2];

	best_cell.y = fl_env->board_size.y;
	collision[1] = 0;
	pos.y = 0;
	while (pos.y < fl_env->board_size.y)
	{
		pos.x = 0;
		while (pos.x < fl_env->board_size.x)
		{
			if (fl_can_set_piece(fl_env, pos) == true && (collision[0] = \
						fl_count_collision(fl_env, pos)) >= collision[1])
			{
				best_cell = pos;
				collision[1] = collision[0];
			}
			++pos.x;
		}
		++pos.y;
	}
	if (best_cell.y == fl_env->board_size.y)
		fl_env->game_is_not_over = false;
	return ((collision[1]) ? best_cell : fl_env->rush_enemy(fl_env));
}

t_coord				fl_play(t_fl_env *fl_env)
{
	t_coord		pos;

	pos = fl_find_best_cell(fl_env);
	pos.y -= fl_env->piece_start.y;
	pos.x -= fl_env->piece_start.x;
	return (pos);
}
