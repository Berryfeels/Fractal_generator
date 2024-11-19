/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_define.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:30:18 by stdi-pum          #+#    #+#             */
/*   Updated: 2024/05/15 13:17:53 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	init_event(t_data *data)
{
	mlx_hook(data->win, 17, 1L << 17, click_close, data);
	mlx_hook(data->win, 02, 1L << 0, key_handle, data);
	mlx_hook(data->win, ButtonPress, ButtonPressMask, mouse_event, data);
}

void	initialize_variables(t_data *data)
{
	data->escape_value = 4;
	data->iteration_times = 5;
	data->shift_x = 0.0;
	data->shift_y = 0.0;
	data->cursor_shift_x = 0.0;
	data->cursor_shift_y = 0.0;
	data->zoom = 1.0;
	data->iterate = 0;
	data->min = -2;
	data->max= 2;
	data->current_color[13] = AQUA;
	data->current_color[12] = LIME;
	data->current_color[11] = TEAL;
	data->current_color[10] = PINK;
	data->current_color[9] = PURPLE;
	data->current_color[8] = ORANGE;
	data->current_color[7] = MAGENTA;
	data->current_color[6] = CYAN;
	data->current_color[5] = YELLOW;
	data->current_color[4] = BLUE;
	data->current_color[3] = GREEN;
	data->current_color[2] = RED;
	data->current_color[1] = BLACK;
	data->current_color[0] = WHITE;
}

int	exit_mlx(t_data *data)
{
	if (data == NULL)
		return (0);
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_loop_end(data->mlx);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	exit(0);
}