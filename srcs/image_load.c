#include "solong.h"

void	xpm_loader(t_vars *vars)
{
	vars->chest_xpm = mlx_xpm_file_to_image(vars->mlx, "./image/chest.xpm", \
					&vars->xpm_width[0], &vars->img_height[0]);
	if(!vars->chest_xpm)
		image_err();
	vars->bush_xpm = mlx_xpm_file_to_image(vars->mlx, "./image/bush.xpm", \
					&vars->xpm_width[1], &vars->img_height[1]);
	if(!vars->bush_xpm)
		image_err();
	vars->boat_xpm = mlx_xpm_file_to_image(vars->mlx, "./image/boat.xpm", \
					&vars->xpm_width[2], &vars->img_height[2]);
	if(!vars->boat_xpm)
		image_err();
	vars->chara_xpm = mlx_xpm_file_to_image(vars->mlx, "./image/chara.xpm", \
					&vars->xpm_width[3], &vars->img_height[3]);
	if(!vars->chara_xpm)
		image_err();
}

void	image_err(void)
{
		printf("image doesn't exist");
		exit(0);
}
