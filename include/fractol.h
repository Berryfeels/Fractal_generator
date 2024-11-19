/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 18:54:47 by stdi-pum          #+#    #+#             */
/*   Updated: 2024/05/15 13:16:40 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include "minilibx/mlx.h"
# include <stdio.h>
# include "libft/libft.h"
# include <X11/keysym.h>
# include <X11/X.h>

# define ERROR_MESSAGE 1
# define HEIGHT 1000
# define WIDTH 	1000
# define MALLOC_ERROR 1
# define NUM_COLORS 14


//WINDOW STRUCTURE
//COLORS	


// Define color constants
#define WHITE           0xFFFFFF   // White
#define BLACK           0x000000   // Black
#define RED             0xFF0000   // Red
#define GREEN           0x00FF00   // Green
#define BLUE            0x0000FF   // Blue
#define YELLOW          0xFFFF00   // Yellow
#define CYAN            0x00FFFF   // Cyan
#define MAGENTA         0xFF00FF   // Magenta
#define ORANGE          0xFFA500   // Orange
#define PURPLE          0x800080   // Purple
#define PINK            0xFFC0CB   // Pink
#define TEAL            0x008080   // Teal
#define LIME            0x00FF00   // Lime
#define AQUA            0x00FFFF   // Aqua
#define INDIGO          0x4B0082   // Indigo

// Psychedelic Colors
#define NEON_PINK       0xF535AA   // Neon Pink
#define ELECTRIC_BLUE   0x7DF9FF   // Electric Blue
#define LASER_LEMON     0xFFFF54   // Laser Lemon
#define PSYCHEDELIC_PURPLE 0xDF00FF // Psychedelic Purple
#define ACID_GREEN      0xB0BF1A   // Acid Green
#define RAVE_RED        0xFF006E   // Rave Red
#define TRIPPY_TEAL     0x00FFC2   // Trippy Teal
#define GROOVY_GREEN    0x9ACD32   // Groovy Green
#define FUNKY_FUCHSIA   0xFF007F   // Funky Fuchsia
#define BLAZING_YELLOW  0xFFFF33   // Blazing Yellow

typedef struct s_data
{
	void 	*mlx;
	void 	*win;
	void 	*img;
	char 	*name;
	double	shift_x;
	double	shift_y;
	double	cursor_shift_x;
	double	cursor_shift_y;
	char	*addr;
	int		bits_per_pixel;
	int		endian;
	int		line_length;
	int		color;
	double escape_value;//hypotenuse
	int 	iteration_times;//value relative image quality and rendering speed
	double	x;
	double	y;
	double	julia_cx;
	double	julia_cy;
	double	zoom;
	int		new_x;
	int		new_y;
	int		current_color[NUM_COLORS];
	int		iterate;
	double	min;
	double	max;
}			t_data;

//MANDELBROT SET STRUCTURE. Determined by a complex number (determined by one real number and one imaginary number, Ex: 5, 6i)
//determined by the formula f(z) =z^z + c where z and c are complex numbeers.


//FUNCTIONS
int	launch_window(t_data *data);
int	click_close(t_data *data);
int	handle_no_event(void);
void	my_pixel_put(t_data *data, int x, int y, int color);
int	key_handle(int keysym, t_data *data);
double map (double unscaled_num, t_data *data, double old_min, double old_max);
t_data square_complex(t_data z);
t_data sum_complex(t_data z1, t_data z2);
void handle_pixel (int x, int y, t_data *data);
void fractal_render (t_data *data);
int data_init(t_data *data);
void initialize_variables(t_data *data);
void init_event(t_data *data);
int mouse_event(int button, int x, int y, t_data *data);
double atodbl (char *s);
int	exit_mlx(t_data *data);
int	ft_getcolor(int i, int iteration_times);

#endif 