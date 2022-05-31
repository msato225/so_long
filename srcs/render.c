/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msato <msato@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 11:20:40 by msato             #+#    #+#             */
/*   Updated: 2022/05/31 15:03:27 by msato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	render(t_vars *vars)
{
	vars->image_wid[0] = 78;
	vars->image_hig[0] = 78;
	vars->y = 0;
	while (vars->y < vars->height)
	{
		vars->x = 0;
		while (vars->x < vars->width)
		{
			if (vars->rectangle[vars->y][vars->x] == 'P')
			{
				vars->player_x = vars->x;
				vars->player_y = vars->y;
				mlx_put_image_to_window(vars->mlx, vars->mlx_win, \
								vars->chara_xpm, 75 * vars->x, 75 * vars->y);
			}
			else if (vars->rectangle[vars->y][vars->x] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->mlx_win, \
								vars->chest_xpm, 75 * vars->x, 75 * vars->y);
			render_2(vars);
			vars->x++;
		}
		vars->y++;
	}	
}

void	render_2(t_vars *vars)
{
	void	*img;

	if (vars->rectangle[vars->y][vars->x] == '1')
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, \
						vars->bush_xpm, 75 * vars->x, 75 * vars->y);
	else if (vars->rectangle[vars->y][vars->x] == 'E')
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, \
						vars->boat_xpm, 75 * vars->x, 75 * vars->y);
	else if (vars->rectangle[vars->y][vars->x] == '0')
	{
		img = mlx_xpm_file_to_image(vars->mlx, "./image/back.xpm", \
								vars->image_wid, vars->image_hig);
		if (!img)
			image_err();
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, img, \
							75 * vars->x, 75 * vars->y);
	}
}
