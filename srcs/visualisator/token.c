/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 19:05:38 by fchanal           #+#    #+#             */
/*   Updated: 2017/06/16 19:18:38 by fchanal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static void		visu_del_token(char ***token)
{
	char	**init;

	init = *token;
	while (**token)
	{
		free(**token);
		++*token;
	}
	free(init);
}

static void		visu_put(const t_env *env, int x, int y, int color)
{
	visu_put_square(env, x, y, color);
	mlx_put_image_to_window(env->mlx, env->win, env->img.ptr, 0, 0);
}

static void		visu_insert_token(const t_env *env, t_coord pos, char **token, \
		char player)
{
	int			xtmp;
	int			color;
	int			i;

	xtmp = pos.x;
	color = (player == 'X') ? VISU_COLOR_P1 : VISU_COLOR_P2;
	i = 0;
	while (*token)
	{
		if (token[0][i] == '\0')
		{
			i = 0;
			++token;
			++pos.y;
			pos.x = xtmp;
		}
		else
		{
			if (token[0][i] == '*')
				visu_put(env, pos.x * VISU_SQUARE_AREA, \
						pos.y * VISU_SQUARE_AREA, color);
			++i;
			++pos.x;
		}
	}
}

static uint8_t	visu_fill(const t_env *env, int nb_token)
{
	char		**token;
	unsigned	i;
	char		player;
	t_coord		pos;
	char		*tmp;

	if (!(token = (char **)malloc(sizeof(*token) * (nb_token + 2))))
		return (1);
	token[nb_token + 1] = NULL;
	i = 0;
	while (ft_get_next_line(0, &token[i]) && token[i][0] != '<')
		++i;
	tmp = token[i];
	player = token[i][6];
	token[i] += 11;
	pos.y = ft_get((const char **)&token[i]);
	token[i] += 2;
	pos.x = ft_get((const char **)&token[i]);
	token[i] = tmp;
	visu_insert_token(env, pos, token, player);
	visu_del_token(&token);
	return (0);
}

int				visu_fill_grid(const t_env *env)
{
	char	*s;
	int8_t	ret;

	if (env->speed)
		usleep(env->speed);
	if (env->stop == true)
		return (0);
	while ((ret = ft_get_next_line(0, &s)) && (*s != 'P' || *(s + 1) != 'i'))
		free(s);
	if (ret > 0)
	{
		if ((visu_fill(env, ft_atoi(s + 5))) == 1)
		{
			free(s);
			exit(1);
		}
		free(s);
	}
	return (0);
}
