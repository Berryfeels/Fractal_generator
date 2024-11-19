/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:30:18 by stdi-pum          #+#    #+#             */
/*   Updated: 2024/04/15 18:31:19 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void init_event(t_data *data)
{
	mlx_loop_hook(data->mlx, handle_no_event, data);
	mlx_hook(data->win, 17, 1L<<17, click_close, data);
	mlx_hook(data->win, 02, 1L<<0, key_handle, data);
	mlx_hook(data->win, ButtonPress, ButtonPressMask, mouse_event, data);
}

void initialize_variables(t_data *data)
{
	data->escape_value = 4;
	data->iteration_times = 50;
	data->shift_x = 0.0;
	data->shift_y = 0.0;
	data->zoom = 1.0;
}

int data_init(t_data *data)
{
	 data->mlx = mlx_init();
    if (data->mlx == NULL)
        return(MALLOC_ERROR);
		
    data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "test");
    if (data->win == NULL)
    {
		mlx_destroy_window(data->mlx, data->win);
		free(data->win);
		return(MALLOC_ERROR);
    }
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (data->img == NULL)
	 {
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->win);
		return(MALLOC_ERROR);
    }
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	init_event(data);
	initialize_variables(data);
	return(0);
}