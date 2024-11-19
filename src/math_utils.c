/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:29:17 by stdi-pum          #+#    #+#             */
/*   Updated: 2024/05/15 14:31:46 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/*consider the formula for Mandelbrot is zn = zn^2 + c
z = real number + imaginary number -> (x+y)=(x+y)^2 + c -> (x+y)^2=(x)
real	number = (x^2 - y^2) imag number = z*x*y*/

/* Julia set exchange c and z*/

static double	calculate_number(char *s)
{
	int		num;
	double	num_2;
	double	paw;

	num = 0;
	num_2 = 0;
	paw = 1;
	while (*s && *s >= 48 && *s <= 57 && *s != '.')
		num = num * 10 + (*s++ - 48);
	if (*s == '.')
		++s;
	while (*s)
	{
		paw /= 10;
		num_2 = num_2 + (*s++ - 48) * paw;
	}
	return (num + num_2);
}

double	atodbl(char *s)
{
	int		sign;
	double	num;

	sign = 1;
	if (!(*s == 45 || *s == 43) || (*s >= 48 && *s <= 57))
	{
		return (0);
	}
	if (*s == 45 || *s == 43)
	{
		if (*s == 45)
			sign *= -1;
		++s;
	}
	num = calculate_number(s);
	return (num * sign);
}

double	map(double unscaled_num, t_data *data, double old_min,
		double old_max)
{
	return ((data->max - data->min) * (unscaled_num - old_min) / (old_max - old_min)
		+ data->min);
}

t_data	sum_complex(t_data z1, t_data z2)
{
	t_data	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

t_data	square_complex(t_data z)
{
	t_data	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}