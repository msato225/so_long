/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msato <msato@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 18:35:52 by msato             #+#    #+#             */
/*   Updated: 2022/05/27 19:06:41 by msato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	put_background_window(t_vars vars)
{
	int		i;
	int		j;
	void	*img;
	int		image_wid[1];
	int		image_hig[1];

	i = 0;
	image_wid[0] = 78;
	image_hig[0] = 78;
	while (i < vars.width)
	{
		j = 0;
		while (j < vars.height)
		{
			img = mlx_xpm_file_to_image(vars.mlx, \
				"./back.xpm", image_wid, image_hig);
			mlx_put_image_to_window(vars.mlx, vars.mlx_win, \
				img, 75 * i, 75 * j);
			j++;
		}
		i++;
	}
	return (0);
}

void	screen_size_check(t_vars vars)
{
	int	width;
	int	height;

	width = vars.width * 75;
	height = vars.height * 75;
	if (width > 2560 || height > 1440)
	{
		printf("Your screen is too small for this game\n");
		exit(0);
	}
}

int	ft_free(t_vars vars)
{
	int	i;

	i = 0;
	while (i < vars.height)
	{
		free(vars.rectangle[i]);
		i++;
	}
	return (0);
}

int	arg_err(t_vars	vars)
{
	printf("You need 2 command line arguments\n");
	return (1);
}
