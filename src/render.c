/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:25:31 by stdi-pum          #+#    #+#             */
/*   Updated: 2024/05/15 13:16:17 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

// zn = zn^2 + c
int	ft_getcolor(int i, int iteration_times)
{
	return ((BLACK - WHITE) * (i - 0) / (iteration_times - 0)
		+ WHITE);
}

void	my_pixel_put(t_data *data, int x, int y, int color)
{
	int	offset;

	offset = (y * data->line_length) + (x * (data->bits_per_pixel / 8));
	*(unsigned int *)(data->addr + offset) = color;
}

static void	calculate_c(t_data *z, t_data *c, t_data *data)
{
	if (!ft_strncmp(data->name, "Julia", 5))
	{
		c->x = data->julia_cx;
		c->y = data->julia_cy;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

void	handle_pixel(int x, int y, t_data *data)
{
	t_data	z;
	t_data	c;
	int		i;

	i = 0;
	z.x = (map(x, data, 0, WIDTH) * data->zoom) + data->shift_x;
	z.y = (-1 * map(y, data, 0, HEIGHT) * data->zoom) + data->shift_y;
	calculate_c(&z, &c, data);
	while (i < data->iteration_times)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > data->escape_value)
		{
			data->color = ft_getcolor(i, data->iteration_times);
			my_pixel_put(data, x, y, data->color);
			return ;
		}
		++i;
	}
	my_pixel_put(data, x, y, data->current_color[data->iterate]);
}

void	fractal_render(t_data *data)
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
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}