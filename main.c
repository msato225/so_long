/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msato <msato@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:27:25 by msato             #+#    #+#             */
/*   Updated: 2022/05/27 19:06:28 by msato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	funct_ptr(t_vars vars)
{
	exit (0);
}

int	main(int argc, char *argv[])
{
	t_vars	vars;
	void	*img;

	if (argc != 2)
		arg_err(vars);
	vars.map_file_name = argv[1];
	if (mapfile_check(vars) != 0)
		exit(0);
	load_map(&vars);
	screen_size_check(vars);
	map_check(&vars);
	wall_check(vars);
	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, vars.width * 75, \
					vars.height * 75, "mao's game");
	put_background_window(vars);
	xpm_loader(&vars);
	render(&vars);
	mlx_hook(vars.mlx_win, 2, 1L << 0, &key_pressed, &vars);
	mlx_hook(vars.mlx_win, 17, 1 << 17, &funct_ptr, &vars);
	mlx_loop(vars.mlx);
	ft_free(vars);
	return (0);
}
