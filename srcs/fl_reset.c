/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_reset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 18:44:58 by fchanal           #+#    #+#             */
/*   Updated: 2017/06/16 19:28:40 by fchanal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		fl_delete_board_line(t_fl_env *fl_env)
{
	int		count;

	count = 0;
	while (count < fl_env->board_size.y)
	{
		free(fl_env->board[count] - 4);
		fl_env->board[count] = NULL;
		++count;
	}
}

static void		fl_delete_piece(t_fl_env *fl_env)
{
	int		count;

	count = 0;
	while (count < fl_env->piece_size.y)
	{
		free(fl_env->piece[count]);
		fl_env->piece[count] = NULL;
		++count;
	}
	free(fl_env->piece);
	fl_env->piece = NULL;
}

void			fl_reset_board_and_piece(t_fl_env *fl_env)
{
	fl_delete_board_line(fl_env);
	fl_delete_piece(fl_env);
}
