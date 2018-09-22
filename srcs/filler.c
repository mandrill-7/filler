/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 18:05:42 by fchanal           #+#    #+#             */
/*   Updated: 2017/06/16 19:38:56 by fchanal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static bool		fl_get_info(t_fl_env *fl_env)
{
	char	*line;
	char	*tmp;

	FL_GET_NEXT_LINE(&line);
	if (*(line + 10) == '1')
		fl_env->player_sign = 'O';
	else
		fl_env->player_sign = 'X';
	free(line);
	FL_GET_NEXT_LINE(&line);
	tmp = line;
	line += 8;
	fl_env->board_size.y = ft_get_nbr((const char **)&line);
	fl_env->board_size.x = ft_get_nbr((const char **)&line);
	free(tmp);
	if (!(fl_env->board = (char **)malloc(sizeof(char *)\
					* fl_env->board_size.y)))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static void		fl_find_enemy(t_fl_env *fl_env)
{
	char	enemy_sign;

	enemy_sign = (fl_env->player_sign == 'O') ? 'X' : 'O';
	fl_env->enemy_pos.y = 0;
	while (fl_env->enemy_pos.y < fl_env->board_size.y)
	{
		fl_env->enemy_pos.x = 0;
		while (fl_env->enemy_pos.x < fl_env->board_size.x)
		{
			if (fl_env->board[fl_env->enemy_pos.y][fl_env->enemy_pos.x]\
					== (enemy_sign))
				return ;
			++fl_env->enemy_pos.x;
		}
		++fl_env->enemy_pos.y;
	}
}

static bool		fl_get_board(t_fl_env *fl_env, bool *is_first_call)
{
	char		*useless_line;
	int			count;

	if (*is_first_call == false)
	{
		FL_GET_NEXT_LINE(&useless_line);
		free(useless_line);
	}
	FL_GET_NEXT_LINE(&useless_line);
	free(useless_line);
	count = 0;
	while (count < fl_env->board_size.y)
	{
		FL_GET_NEXT_LINE(&fl_env->board[count]);
		++count;
	}
	fl_scale_board(fl_env);
	if (*is_first_call == true)
	{
		fl_find_enemy(fl_env);
		fl_set_rush(fl_env);
		*is_first_call = false;
	}
	return (EXIT_SUCCESS);
}

static bool		fl_get_piece(t_fl_env *fl_env)
{
	char	*info_piece;
	char	*tmp;
	int		count;

	FL_GET_NEXT_LINE(&info_piece);
	tmp = info_piece;
	info_piece += 6;
	fl_env->piece_size.y = ft_get_snbr((const char **)&info_piece);
	fl_env->piece_size.x = ft_get_snbr((const char **)&info_piece);
	free(tmp);
	if (!(fl_env->piece = (char **)malloc(sizeof(char *) *\
					fl_env->piece_size.y)))
		return (EXIT_FAILURE);
	count = 0;
	while (count < fl_env->piece_size.y)
	{
		FL_GET_NEXT_LINE(&fl_env->piece[count]);
		++count;
	}
	fl_find_piece_start(fl_env);
	return (EXIT_SUCCESS);
}

int				main(void)
{
	t_fl_env	fl_env;
	t_coord		coord;
	bool		is_first_call;

	if (fl_get_info(&fl_env) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	fl_env.game_is_not_over = true;
	is_first_call = true;
	while (1)
	{
		if (fl_get_board(&fl_env, &is_first_call) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		if (fl_get_piece(&fl_env) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		coord = fl_play(&fl_env);
		if (fl_env.game_is_not_over == false)
			break ;
		fl_reset_board_and_piece(&fl_env);
		ft_printf("%d %d\n", coord.y, coord.x);
	}
	free(fl_env.board);
	ft_printf("0 0\n");
	return (EXIT_SUCCESS);
}
