/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 12:12:53 by stdi-pum          #+#    #+#             */
/*   Updated: 2024/05/15 13:19:40 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	data_init(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (MALLOC_ERROR);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, data->name);
	if (data->win == NULL)
	{
		mlx_destroy_window(data->mlx, data->win);
		free(data->win);
		return (MALLOC_ERROR);
	}
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (data->img == NULL)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->win);
		return (MALLOC_ERROR);
	}
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	init_event(data);
	initialize_variables(data);
	return (0);
}

int	launch_window(t_data *data)
{
	data_init(data);
	fractal_render(data);
	mlx_loop(data->mlx);
	return (0);
}
