/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openassets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torsini <torsini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:30:49 by torsini           #+#    #+#             */
/*   Updated: 2024/10/22 09:55:32 by torsini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	cleanup_and_exit(t_data *game, const char *error_message)
{
	ft_printf("Erreur: %s\n", error_message);
	on_destroy(game);
	exit(EXIT_FAILURE);
}

void	open_images(t_data *game)
{
	game->textures.ground = mlx_xpm_file_to_image(game->mlx, "assets/black.xpm",
			&game->width, &game->height);
	game->textures.coin = mlx_xpm_file_to_image(game->mlx, "assets/ibm5150.xpm",
			&game->width, &game->height);
	game->textures.door = mlx_xpm_file_to_image(game->mlx,
			"assets/teleport_light.xpm", &game->width, &game->height);
	game->textures.wall = mlx_xpm_file_to_image(game->mlx, "assets/hole.xpm",
			&game->width, &game->height);
	game->textures.player = mlx_xpm_file_to_image(game->mlx,
			"assets/player.xpm", &game->width, &game->height);
	game->textures.player_left = mlx_xpm_file_to_image(game->mlx,
			"assets/player_left.xpm", &game->width, &game->height);
	game->textures.player_right = mlx_xpm_file_to_image(game->mlx,
			"assets/player_right.xpm", &game->width, &game->height);
	game->textures.player_back = mlx_xpm_file_to_image(game->mlx,
			"assets/player_back.xpm", &game->width, &game->height);
	game->textures.moves = mlx_xpm_file_to_image(game->mlx, "assets/moves.xpm",
			&game->width, &game->height);
}
