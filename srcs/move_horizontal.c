/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_horizontal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msato <msato@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:29:51 by msato             #+#    #+#             */
/*   Updated: 2022/05/28 12:11:38 by msato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

/*movement of player___________________________________________*/
int	go_to_right(t_vars *vars)
{
	int	y;
	int	x;

	y = vars->player_y;
	x = vars->player_x;
	vars->rectangle[y][x] = '0';
	vars->rectangle[y][x + 1] = 'P';
	vars->counter += 1;
	x += 1;
	vars->player_x = x;
	vars->player_y = y;
	return (0);
}

int	move_to_right(t_vars *vars)
{	
	int	y;
	int	x;

	y = vars->player_y;
	x = vars->player_x;
	if (vars->rectangle[y][x + 1] == '1')
		return (1);
	if (vars->rectangle[y][x + 1] == 'C')
	{
		vars->collectable += 1;
		vars->rectangle[y][x + 1] = '0';
	}
	if (vars->rectangle[y][x + 1] == 'E')
	{
		if (vars->collectable == vars->collec_on_map)
		{
			vars->rectangle[y][x] = '0';
			vars->rectangle[y][x + 1] = 'P';
			vars->counter += 1;
			exit(0);
		}
		return (1);
	}
	go_to_right(vars);
	return (0);
}

int	go_to_left(t_vars *vars)
{
	int	y;
	int	x;

	y = vars->player_y;
	x = vars->player_x;
	vars->rectangle[y][x] = '0';
	vars->rectangle[y][x - 1] = 'P';
	vars->counter += 1;
	x -= 1;
	vars->player_x = x;
	vars->player_y = y;
	return (0);
}

int	move_to_left(t_vars *vars)
{	
	int	y;
	int	x;

	y = vars->player_y;
	x = vars->player_x;
	if (vars->rectangle[y][x - 1] == '1')
		return (1);
	if (vars->rectangle[y][x - 1] == 'C')
	{
		vars->collectable += 1;
		vars->rectangle[y][x - 1] = '0';
	}
	if (vars->rectangle[y][x - 1] == 'E')
	{
		if (vars->collectable == vars->collec_on_map)
		{
			vars->rectangle[y][x] = '0';
			vars->rectangle[y][x - 1] = 'P';
			vars->counter += 1;
			exit(0);
		}
		return (1);
	}
	go_to_left(vars);
	return (0);
}
