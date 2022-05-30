/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_err.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msato <msato@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:32:35 by msato             #+#    #+#             */
/*   Updated: 2022/05/30 18:41:58 by msato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	map_err_flag(t_vars vars)
{
	if (vars.p_flag != 1)
	{
		printf("You must have 1 player\n");
		exit(0);
	}
	if (vars.e_flag != 1)
	{
		printf("You must have 1 goal\n");
		exit(0);
	}
}

void	invalid_map_msg(void)
{
	printf("Invalid map\n");
	exit(0);
}

void	map_err(void)
{
	printf("Map width must be the same\n");
	exit(0);
}
