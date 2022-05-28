/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msato <msato@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 18:04:50 by msato             #+#    #+#             */
/*   Updated: 2022/05/27 19:31:31 by msato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "solong.h"

void	map_check(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (y < vars->height)
	{
		x = 0;
		while (x < vars->width)
		{
			if (vars->rectangle[y][x] == 'P')
				vars->p_flag++;
			if (vars->rectangle[y][x] == 'C')
				vars->collec_on_map += 1;
			else if (vars->rectangle[y][x] == 'E')
				vars->e_flag++;
			else if (vars->rectangle[y][x] != 'P' && vars->rectangle[y][x] != \
				'E' && vars->rectangle[y][x] != '1' && vars->rectangle[y][x] != \
				'0' && vars->rectangle[y][x] != 'C')
				invalid_map_msg(*vars);
			x++;
		}
		y++;
	}
	map_err_flag(*vars);
}

void	wall_check(t_vars vars)
{
	int	x;
	int	y;

	y = 0;
	while (y < vars.height)
	{
		x = 0;
		while (x < vars.width)
		{
			if (vars.rectangle[0][x] != '1' || vars.rectangle[y][0] != '1')
			{
				printf("Your map has wall error\n");
				exit(0);
			}
			if (vars.rectangle[y][vars.width - 1] != '1' || \
				vars.rectangle[vars.height - 1][x] != '1')
			{
				printf("Your map has wall error\n");
				exit(0);
			}
			x++;
		}
		y++;
	}
	return ;
}

int	mapfile_check(t_vars vars)
{
	char	*s;
	char	*str;

	s = ".ber";
	str = ft_strrchr(vars.map_file_name, '.');
	if (!str)
	{
		printf("Invalid map file\n");
		return (-1);
	}
	if (ft_strncmp(str, s, 4))
	{
		printf("Invalid map file\n");
		return (-1);
	}
	return (0);
}
