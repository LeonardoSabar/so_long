/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 09:18:05 by leobarbo          #+#    #+#             */
/*   Updated: 2024/01/25 17:06:41 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_chest_position(t_main *game)
{
	int	idx;
	int	odx;

	game->chest_position_x = -1;
	game->chest_position_y = -1;
	idx = 0;
	while (game->map[idx])
	{
		odx = 0;
		while (game->map[idx][odx])
		{
			if (game->map[idx][odx] == 'E')
			{
				game->chest_position_x = odx * 64;
				game->chest_position_y = idx * 64;
				return ;
			}
			odx++;
		}
		idx++;
	}
}

int	ft_count_exit(char **game)
{
	int	idx;
	int	odx;
	int	exit;

	exit = 0;
	idx = 0;
	while (game[idx])
	{
		odx = 0;
		while (game[idx][odx])
		{
			if (game[idx][odx] == 'E')
				exit++;
			odx++;
		}
		idx++;
	}
	if (exit > 1)
		return (FALSE);
	return (TRUE);
}

void	ft_exit_game(t_main *game)
{
	if ((game->collectable <= 0)
		&& (game->map[game->y / 64][game->x / 64] == 'E'))
		mlx_close_window(game->mlx);
}
