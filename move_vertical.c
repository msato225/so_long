/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_vertical.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msato <msato@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:45:52 by msato             #+#    #+#             */
/*   Updated: 2022/05/27 16:47:19 by msato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "solong.h"

int	go_to_down(t_vars *vars)
{
	int	x;
	int	y;

	y = vars->player_y;
	x = vars->player_x;
	vars->rectangle[y][x] = '0';
	vars->rectangle[y + 1][x] = 'P';
	vars->counter += 1;
	y += 1;
	vars->player_x = x;
	vars->player_y = y;
	return (0);
}

int	move_to_down(t_vars *vars)
{
	int	y;
	int	x;

	y = vars->player_y;
	x = vars->player_x;
	if (vars->rectangle[y + 1][x] == '1')
		return (1);
	else if (vars->rectangle[y + 1][x] == 'C')
	{
		vars->collectable += 1;
		vars->rectangle[y + 1][x] = '0';
	}
	else if (vars->rectangle[y + 1][x] == 'E')
	{
		if (vars->collectable == vars->collec_on_map)
		{
			vars->rectangle[y][x] = '0';
			vars->rectangle[y + 1][x] = 'P';
			vars->counter += 1;
			exit(0);
		}
		return (1);
	}
	go_to_down(vars);
	return (0);
}

int	go_to_up(t_vars *vars)
{
	int	x;
	int	y;

	y = vars->player_y;
	x = vars->player_x;
	vars->rectangle[y][x] = '0';
	vars->rectangle[y - 1][x] = 'P';
	vars->counter += 1;
	y -= 1;
	vars->player_x = x;
	vars->player_y = y;
	return (0);
}

int	move_to_up(t_vars *vars)
{
	int	y;
	int	x;

	y = vars->player_y;
	x = vars->player_x;
	if (vars->rectangle[y - 1][x] == '1')
		return (1);
	else if (vars->rectangle[y - 1][x] == 'C')
	{
		vars->collectable += 1;
		vars->rectangle[y - 1][x] = '0';
	}
	else if (vars->rectangle[y - 1][x] == 'E')
	{
		if (vars->collectable == vars->collec_on_map)
		{
			vars->rectangle[y][x] = '0';
			vars->rectangle[y - 1][x] = 'P';
			vars->counter += 1;
			exit(0);
		}
		return (1);
	}
	go_to_up(vars);
	return (0);
}
