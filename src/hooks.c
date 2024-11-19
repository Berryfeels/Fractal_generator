/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 12:09:32 by stdi-pum          #+#    #+#             */
/*   Updated: 2024/05/15 13:00:28 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	change_color(t_data *data)
{
	if (data->iterate == NUM_COLORS)
		data->iterate = 0;
	else
		(data->iterate)++;
}

int	mouse_event(int button, int mouse_x, int mouse_y, t_data *data)
{
	if (button == 4)
	{
		data->zoom *= 0.95;
	}
	else if (button == 5)
	{
		data->zoom *= 1.05;
	}
	else if (button == 1)
	{
		data->shift_x = -(data->zoom) * (map(mouse_x, data, 0, WIDTH));
		data->shift_y = (data->zoom) * map(mouse_y, data, 0, HEIGHT);
	}
	fractal_render(data);
	return (0);
}

static int	more_keyevent(int keycode, t_data *data)
{
	if (keycode == 65364)
	{
		data->shift_y += (0.1 * data->zoom);
	}
	else if (keycode == 65451)
	{
		data->iteration_times += 10;
	}
	else if (keycode == 65453)
	{
		data->iteration_times -= 10;
	}
	else if (keycode == 99)
	{
		change_color(data);
	}
	return (0);
}

int	key_handle(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		exit_mlx(data);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == 65361)
	{
		data->shift_x += (0.1 * data->zoom);
	}
	else if (keycode == 65363)
	{
		data->shift_x -= (0.1 * data->zoom);
	}
	else if (keycode == 65362)
	{
		data->shift_y -= (0.1 * data->zoom);
	}
	more_keyevent(keycode, data);
	fractal_render(data);
	return (0);
}

int	click_close(t_data *data)
{
	exit_mlx(data);
	exit(0);
}
