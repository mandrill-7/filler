/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_rush.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 18:50:59 by fchanal           #+#    #+#             */
/*   Updated: 2017/06/16 19:37:12 by fchanal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static t_coord	fl_find_cell_1(t_fl_env *fl_env)
{
	t_coord		pos;

	pos.y = 0;
	while (pos.y < fl_env->board_size.y)
	{
		pos.x = 0;
		while (pos.x < fl_env->board_size.x)
		{
			if (fl_can_set_piece(fl_env, pos) == true)
				return (pos);
			++pos.x;
		}
		++pos.y;
	}
	fl_env->game_is_not_over = false;
	return (pos);
}

static t_coord	fl_find_cell_2(t_fl_env *fl_env)
{
	t_coord		pos;

	pos.y = 0;
	while (pos.y < fl_env->board_size.y)
	{
		pos.x = fl_env->board_size.x - 1;
		while (pos.x >= 0)
		{
			if (fl_can_set_piece(fl_env, pos) == true)
				return (pos);
			--pos.x;
		}
		++pos.y;
	}
	fl_env->game_is_not_over = false;
	return (pos);
}

static t_coord	fl_find_cell_3(t_fl_env *fl_env)
{
	t_coord		pos;

	pos.y = fl_env->board_size.y - 1;
	while (pos.y >= 0)
	{
		pos.x = 0;
		while (pos.x < fl_env->board_size.x)
		{
			if (fl_can_set_piece(fl_env, pos) == true)
				return (pos);
			++pos.x;
		}
		--pos.y;
	}
	fl_env->game_is_not_over = false;
	return (pos);
}

static t_coord	fl_find_cell_4(t_fl_env *fl_env)
{
	t_coord		pos;

	pos.y = fl_env->board_size.y - 1;
	while (pos.y >= 0)
	{
		pos.x = fl_env->board_size.x - 1;
		while (pos.x >= 0)
		{
			if (fl_can_set_piece(fl_env, pos) == true)
				return (pos);
			--pos.x;
		}
		--pos.y;
	}
	fl_env->game_is_not_over = false;
	return (pos);
}

void			fl_set_rush(t_fl_env *fl_env)
{
	if (fl_env->enemy_pos.y <= (fl_env->board_size.y / 2) && \
			fl_env->enemy_pos.x <=
			(fl_env->board_size.x / 2))
		fl_env->rush_enemy = &fl_find_cell_1;
	else if (fl_env->enemy_pos.y <= (fl_env->board_size.y / 2) && \
			fl_env->enemy_pos.x > \
			(fl_env->board_size.x / 2))
		fl_env->rush_enemy = &fl_find_cell_2;
	else if (fl_env->enemy_pos.y > (fl_env->board_size.y / 2) && \
			fl_env->enemy_pos.x <= \
			(fl_env->board_size.x / 2))
		fl_env->rush_enemy = &fl_find_cell_3;
	else
		fl_env->rush_enemy = &fl_find_cell_4;
}
