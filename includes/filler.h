/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 18:14:22 by fchanal           #+#    #+#             */
/*   Updated: 2017/06/16 19:31:53 by fchanal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include "ft_printf.h"

typedef struct s_fl_env	t_fl_env;
typedef struct s_coord	t_coord;

# define FL_GET_NEXT_LINE(ptr) if (ft_get_next_line(0, ptr) != 1) return (1)

struct		s_coord
{
	int		x;
	int		y;
};

struct		s_fl_env
{
	char		player_sign;
	t_coord		enemy_pos;
	t_coord		(*rush_enemy)(t_fl_env *);
	char		**board;
	t_coord		board_size;
	char		**piece;
	t_coord		piece_size;
	t_coord		piece_start;
	bool		game_is_not_over;
};

t_coord		fl_play(t_fl_env *fl_env);
void		fl_reset_board_and_piece(t_fl_env *fl_env);
void		fl_find_piece_start(t_fl_env *fl_env);
void		fl_scale_board(t_fl_env *fl_env);
bool		fl_check_cell(t_fl_env *fl_env, bool *just_you, t_coord pos);
bool		fl_can_set_piece(t_fl_env *fl_env, t_coord pos);
void		fl_set_rush(t_fl_env *fl_env);

#endif
