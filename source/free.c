/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torsini <torsini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:46:20 by torsini           #+#    #+#             */
/*   Updated: 2024/10/16 14:42:15 by torsini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_maps(t_data *game)
{
	int	i;

	i = 0;
	while (i < game->rows)
	{
		free(game->map[i]);
		free(game->map_dup[i]);
		game->map[i] = NULL;
		game->map_dup[i] = NULL;
		i++;
	}
	free(game->map);
	free(game->map_dup);
	game->map = NULL;
	game->map_dup = NULL;
}

void	free_textures(t_data *game)
{
	mlx_destroy_image(game->mlx, game->textures.coin);
	mlx_destroy_image(game->mlx, game->textures.door);
	mlx_destroy_image(game->mlx, game->textures.ground);
	mlx_destroy_image(game->mlx, game->textures.wall);
	mlx_destroy_image(game->mlx, game->textures.player);
	mlx_destroy_image(game->mlx, game->textures.player_left);
	mlx_destroy_image(game->mlx, game->textures.player_right);
	mlx_destroy_image(game->mlx, game->textures.player_back);
	mlx_destroy_image(game->mlx, game->textures.moves);
}

int	on_destroy(t_data *game)
{
	free_maps(game);
	free_textures(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}
