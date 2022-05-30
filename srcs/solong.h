/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msato <msato@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:42:44 by msato             #+#    #+#             */
/*   Updated: 2022/05/30 20:01:30 by msato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H

# define	SOLONG_H

# include "../mlx/mlx.h"
# include "../gnl/get_next_line.h"
# include <math.h>

typedef struct s_vars
{
	void	*mlx;
	void	*mlx_win;
	int		p_flag;
	int		e_flag;
	int		collectable;
	int		collec_on_map;
	int		width;
	int		height;
	char	*map_file_name;
	char	*rectangle[100];
	int		x;
	int		y;
	int		player_x;
	int		player_y;
	void	*chest_xpm;
	void	*chara_xpm;
	void	*bush_xpm;
	void	*boat_xpm;
	int		image_wid[1];
	int		image_hig[1];
	int		xpm_width[4];
	int		img_height[4];
	int		counter;
}	t_vars;

int			put_background_window(t_vars vars);
void		screen_size_check(t_vars vars);
int			ft_free(t_vars vars);
int			arg_err(void);
int			funct_ptr(void);
void		keycode_s(t_vars *vars);
void		keycode_w(t_vars *vars);
void		keycode_d(t_vars *vars);
void		keycode_a(t_vars *vars);
int			key_pressed(int keycode, t_vars *vars);
void		*load_map(t_vars *vars);
size_t		strlen_without_n(const char *line);
void		map_err(void);
void		map_err_flag(t_vars vars);
void		invalid_map_msg(void);
int			get_map(t_vars *vars);
void		image_err(void);
void		xpm_loader(t_vars *vars);
void		render(t_vars *vars);
void		render_2(t_vars *vars);
int			put_background_window(t_vars vars);
int			go_to_down(t_vars *vars);
int			go_to_up(t_vars *vars);
int			go_to_right(t_vars *vars);
int			go_to_left(t_vars *vars);
int			move_to_right(t_vars *vars);
int			move_to_left(t_vars *vars);
int			move_to_down(t_vars *vars);
int			move_to_up(t_vars *vars);
void		wall_check(t_vars vars);
void		map_check(t_vars *vars);
int			mapfile_check(t_vars vars);
char		*ft_strrchr(const char *s, int c);
/*static int	cmp_char(char c1, char c2);*/
int			ft_strncmp(const char *s1, const char *s2, size_t n);

#endif