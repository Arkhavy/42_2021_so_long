/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:03:06 by ljohnson          #+#    #+#             */
/*   Updated: 2021/12/14 08:54:50 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../sl_inc/so_long.h"

char	*sl_build_map(t_prog *mlx, t_vstock *vars)
{
	while (!mlx->stock)
	{
		mlx->stock = get_next_line(mlx->fd);
		if (!mlx->stock || !mlx->stock[0])
		{
			free (mlx->stock);
			return (mlx->map);
		}
		if (!mlx->map)
			mlx->map = ft_substr(mlx->stock, 0, ft_strlen(mlx->stock));
		else
		{
			vars->temp = mlx->map;
			mlx->map = ft_strjoin(mlx->map, mlx->stock);
			free (vars->temp);
		}
		ft_free(&mlx->stock);
	}
	return (mlx->map);
}

int	sl_check_tile(t_prog *mlx, char tile)
{
	if (tile == 'E')
	{
		if (ft_int_strchr(mlx->map, 'C') == -1)
		{
			sl_close_window(&*mlx);
			return (0);
		}
		else
			return (sl_err2(17));
	}
	else if (tile == '1')
		return (sl_err2(18));
	return (1);
}
