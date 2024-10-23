/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printgame.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torsini <torsini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 11:03:50 by torsini           #+#    #+#             */
/*   Updated: 2024/10/22 10:15:51 by torsini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_player(t_data *game, int i, int index)
{
	if (!game->mlx || !game->win || !game->textures.ground)
		cleanup_and_exit
			(game, "MLX, window, or ground texture not initialized");
	mlx_put_image_to_window
		(game->mlx, game->win, game->textures.ground, i * 32, index * 32);
	if (game->p_pos.direction == FRONT && game->textures.player)
		mlx_put_image_to_window
			(game->mlx, game->win, game->textures.player, i * 32, index * 32);
	else if (game->p_pos.direction == BACK && game->textures.player_back)
		mlx_put_image_to_window
			(game->mlx, game->win,
			game->textures.player_back, i * 32, index * 32);
	else if (game->p_pos.direction == LEFT && game->textures.player_left)
		mlx_put_image_to_window
			(game->mlx, game->win,
			game->textures.player_left, i * 32, index * 32);
	else if (game->p_pos.direction == RIGHT && game->textures.player_right)
		mlx_put_image_to_window
			(game->mlx, game->win,
			game->textures.player_right, i * 32, index * 32);
	else
		cleanup_and_exit
			(game, "Player texture not initialized for the current direction");
}

void	print_coin(t_data *game, int i, int index)
{
	if (!game->textures.ground)
	{
		cleanup_and_exit(game, "Failed to load ground texture");
	}
	if (!game->textures.coin)
	{
		cleanup_and_exit(game, "Failed to load coin texture");
	}
	mlx_put_image_to_window(game->mlx, game->win, game->textures.ground, i * 32,
		index * 32);
	mlx_put_image_to_window(game->mlx, game->win, game->textures.coin, i * 32,
		index * 32);
}

void	print_exit(t_data *game, int i, int index)
{
	mlx_put_image_to_window(game->mlx, game->win, game->textures.ground, i * 32,
		index * 32);
	mlx_put_image_to_window(game->mlx, game->win, game->textures.door, i * 32,
		index * 32);
}

void	print_wall(t_data *game, int i, int index)
{
	mlx_put_image_to_window(game->mlx, game->win, game->textures.wall, i * 32,
		index * 32);
}
