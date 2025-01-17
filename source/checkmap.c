/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torsini <torsini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:30:35 by torsini           #+#    #+#             */
/*   Updated: 2024/10/11 17:41:55 by torsini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_closed_map(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->rows)
	{
		j = 0;
		while (j < game->cols)
		{
			if (i == 0 || i == game->rows - 1)
			{
				if (game->map[i][j] != '1')
					error_message("Invalid map.");
			}
			else if (j == 0 || j == game->cols - 1)
			{
				if (game->map[i][j] != '1')
					error_message("Invalid map.");
			}
			j++;
		}
		i++;
	}
}

void	check_rect(t_data *game)
{
	int	i;
	int	row_len;

	i = 0;
	while (i < game->rows - 1)
	{
		row_len = ft_strlen(game->map[i]) - 1;
		if (row_len != game->cols)
			error_message("Invalid map.");
		i++;
	}
	if (game->cols < 3 || game->rows < 3)
		error_message("Invalid map.");
	if (game->cols == game->rows)
		error_message("Invalid map.");
}

void	look_map(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->rows)
	{
		j = -1;
		while (++j < game->cols)
		{
			if (game->map[i][j] == 'P')
			{
				game->p_pos.row = i;
				game->p_pos.col = j;
				game->player++;
			}
			else if (game->map[i][j] == 'E')
				game->exit++;
			else if (game->map[i][j] == 'C')
				game->coins++;
			else if (game->map[i][j] != '1' && game->map[i][j] != '0')
				error_message("Invalid map.");
		}
		i++;
	}
}

void	check_map(t_data *game)
{
	check_closed_map(game);
	check_rect(game);
	look_map(game);
	if (game->exit != 1 || game->coins < 1 || game->player != 1)
		error_message("Invalid map.");
}
