/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msato <msato@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:27:13 by msato             #+#    #+#             */
/*   Updated: 2022/05/27 18:35:45 by msato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "solong.h"

int	key_pressed(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->mlx_win);
		exit(0);
		return (0);
	}
	if (keycode == 1)
		keycode_s(vars);
	if (keycode == 0)
		keycode_a(vars);
	if (keycode == 2)
		keycode_d(vars);
	if (keycode == 13)
		keycode_w(vars);
	render(vars);
	return (0);
}

void	keycode_s(t_vars *vars)
{
	int	flag;

	flag = move_to_down(vars);
	if (flag == 0)
		printf("move counter = %d\n", vars->counter);
}

void	keycode_a(t_vars *vars)
{
	int	flag;

	flag = move_to_left(vars);
	if (flag == 0)
		printf("move counter = %d\n", vars->counter);
}

void	keycode_d(t_vars *vars)
{
	int	flag;

	flag = move_to_right(vars);
	if (flag == 0)
		printf("move counter = %d\n", vars->counter);
}

void	keycode_w(t_vars *vars)
{
	int	flag;

	flag = move_to_up(vars);
	if (flag == 0)
		printf("move counter = %d\n", vars->counter);
}
