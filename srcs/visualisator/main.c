/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 19:01:47 by fchanal           #+#    #+#             */
/*   Updated: 2017/06/16 19:03:05 by fchanal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static void		visu_get_board_size(int *width, int *height)
{
	char	*s;
	char	*tmp;

	while (ft_get_next_line(0, &s) && *s != 'P')
		free(s);
	tmp = s;
	s += 7;
	*height = ft_get_nbr((const char **)&s);
	*width = ft_get_nbr((const char **)&s);
	free(tmp);
}

static int		visu_key_event(int keycode, void *params)
{
	t_env	*env;

	env = params;
	if (keycode == 53)
		exit(0);
	else if (keycode == 35)
		env->stop = true;
	else if (keycode == 1)
		env->stop = false;
	else if (keycode == 27)
	{
		if (!env->speed)
			env->speed = 1;
		env->speed *= 10;
	}
	else if (keycode == 24)
		env->speed /= 10;
	return (0);
}

static void		visu_handle_speed(int argc, char **argv, useconds_t *speed)
{
	if (argc > 1)
		*speed = 1000000 - (ft_get_nbr((const char **)argv + 1) * 100000);
	else
		*speed = 10000;
}

int				main(int argc, char **argv)
{
	t_env		env;

	env.stop = false;
	visu_handle_speed(argc, argv, &env.speed);
	visu_get_board_size(&env.map.x, &env.map.y);
	env.win_size.x = env.map.x * (VISU_SQUARE_AREA) + 1;
	env.win_size.y = env.map.y * (VISU_SQUARE_AREA) + 1;
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, env.win_size.x, env.win_size.y, \
			"Filler Arena");
	env.img.ptr = mlx_new_image(env.mlx, env.win_size.x, env.win_size.y);
	env.img.str = mlx_get_data_addr(env.img.ptr, &env.img.bpp, &env.img.s_l, \
			&env.img.endian);
	visu_put_grid((const t_env *)&env);
	mlx_put_image_to_window(env.mlx, env.win, env.img.ptr, 0, 0);
	mlx_key_hook(env.win, &visu_key_event, &env);
	mlx_loop_hook(env.mlx, &visu_fill_grid, &env);
	mlx_loop(env.mlx);
	return (0);
}
