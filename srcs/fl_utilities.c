/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 18:52:00 by fchanal           #+#    #+#             */
/*   Updated: 2017/06/16 19:39:55 by fchanal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	fl_scale_board(t_fl_env *fl_env)
{
	int		count;

	count = 0;
	while (count < fl_env->board_size.y)
	{
		fl_env->board[count] += 4;
		++count;
	}
}

void	fl_find_piece_start(t_fl_env *fl_env)
{
	fl_env->piece_start.y = 0;
	while (fl_env->piece_start.y < fl_env->piece_size.y)
	{
		fl_env->piece_start.x = 0;
		while (fl_env->piece_start.x < fl_env->piece_size.x)
		{
			if (fl_env->piece[fl_env->piece_start.y][fl_env->piece_start.x] \
					== '*')
				return ;
			++fl_env->piece_start.x;
		}
		++fl_env->piece_start.y;
	}
}

bool	fl_check_cell(t_fl_env *fl_env, bool *just_you, t_coord pos)
{
	if (pos.x < 0 || pos.y >= fl_env->board_size.y || \
			pos.x >= fl_env->board_size.x ||
			(fl_env->board[pos.y][pos.x] != fl_env->player_sign &&
			fl_env->board[pos.y][pos.x] != '.'))
		return (false);
	if (fl_env->board[pos.y][pos.x] == fl_env->player_sign || \
			fl_env->board[pos.y][pos.x] == (fl_env->player_sign))
	{
		if (*just_you == false)
			*just_you = true;
		else
			return (false);
	}
	return (true);
}

bool	fl_can_set_piece(t_fl_env *fl_env, t_coord pos)
{
	t_coord		tmp;
	bool		just_you;

	tmp = fl_env->piece_start;
	just_you = false;
	while (tmp.y < fl_env->piece_size.y)
	{
		while (tmp.x < fl_env->piece_size.x)
		{
			if (fl_env->piece[tmp.y][tmp.x] == '*')
				if (fl_check_cell(fl_env, &just_you, pos) == false)
					return (false);
			++tmp.x;
			++pos.x;
		}
		pos.x -= fl_env->piece_size.x;
		tmp.x = 0;
		++pos.y;
		++tmp.y;
	}
	return (just_you);
}
