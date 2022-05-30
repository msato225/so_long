/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msato <msato@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:41:53 by msato             #+#    #+#             */
/*   Updated: 2022/05/30 19:57:09 by msato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

size_t	strlen_without_n(const char *line)
{
	size_t	i;

	if (!line)
		return (0);
	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	return (i);
}

int	get_map(t_vars *vars)
{
	char	*line;
	int		fd;
	int		map_height;

	fd = open(vars->map_file_name, O_RDONLY);
	if (fd < 0)
	{
		printf("This file doesn't exist\n");
		exit(0);
	}
	line = get_next_line(fd);
	vars->width = strlen_without_n(line);
	map_height = 0;
	while (line)
	{
		if ((int)strlen_without_n(line) != vars->width)
			map_err();
		vars->rectangle[map_height] = line;
		map_height++;
		line = get_next_line(fd);
	}
	vars->height = map_height;
	close(fd);
	return (0);
}

void	*load_map(t_vars *vars)
{	
	get_map(vars);
	return (0);
}
