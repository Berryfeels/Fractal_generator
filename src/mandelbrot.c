/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:25:31 by stdi-pum          #+#    #+#             */
/*   Updated: 2024/04/15 18:45:01 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
//zn = zn^2 + c

void	my_pixel_put(t_data *data, int x, int y, int color)
{
	int	offset;

	offset = (y * data->line_length) + (x * (data->bits_per_pixel / 8));
	*(unsigned int *)(data->addr + offset) = color;
}

void handle_pixel (int x, int y, t_data *data)
{
	t_data z;
	t_data c;	
	int i;
	
	z.x = 0.0;
	z.y = 0.0;
	i = 0;
	c.x = (map (x, -2, +2, 0, WIDTH) * data->zoom) + data->shift_x;
	c.y = (map (y, +2, -2, 0, HEIGHT) * data->zoom) + data->shift_y;
	while (i < data -> iteration_times)
	{
		z = sum_complex(square_complex(z), c);

		if ((z.x * z.x) + (z.y *z.y) > data -> escape_value)
		{
			data -> color = map(i, BLACK, WHITE, 0, data -> iteration_times);
			my_pixel_put(data, x, y, data -> color);
			return;
		}
		++i;
	}
	my_pixel_put(data, x, y, ELECTRIC_BLUE);
	
}

void fractal_render (t_data *data)
{
	int x;
	int y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pixel(x, y, data);
		}
	}
	mlx_put_image_to_window(data -> mlx, data -> win, data -> img, 0, 0);
}