/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 20:41:48 by stdi-pum          #+#    #+#             */
/*   Updated: 2024/05/15 12:35:20 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../include/libft/libft.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if ((argc == 2 && !ft_strncmp("Mandelbrot", argv[1], 10)) || (argc == 4
			&& !ft_strncmp("Julia", argv[1], 5)))
	{
		data.name = argv[1];
		if (!ft_strncmp("Julia", argv[1], 5))
		{
			data.julia_cx = atodbl(argv[2]);
			data.julia_cy = atodbl(argv[3]);
		}
		launch_window(&data);
	}
	else
	{
		return (write(1,
				"Define Name of the fractal and z/c value. Try again.", 96), 0);
	}
	return (0);
}
