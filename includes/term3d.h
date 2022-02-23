/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:11:59 by mkamei            #+#    #+#             */
/*   Updated: 2022/02/23 10:46:38 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERM3D_H
# define TERM3D_H

# include "libft.h"
# include <stdbool.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>

// variable
# define CANVAS_WIDTH 80
# define CANVAS_HEIGHT 40
# define USLEEP_TIME 100000
# define ROT_ANGLE_DENOM 48.0
# define INIT_ROT_X_DENOM 4.0
# define INIT_ROT_Y_DENOM 0.0
# define INIT_ROT_Z_DENOM 0.0
# define TER_CHAR_Y_PER_X 2.0
# define LINE_DRAW_FLAG 1
# define MIN_SCALE_DENOM 2
# define ZOOM_IN_ADDITION 1.0

// constant
# define GNL_BUFFER_SIZE 1000
# define PI 3.141592653589793
# define Z_SCREEN -1

typedef struct s_p_3d
{
	double		x;
	double		y;
	double		z;
}				t_p_3d;

typedef struct s_p_2d
{
	double		x;
	double		y;
}				t_p_2d;

typedef enum e_axis
{
	X = 0,
	Y = 1,
	Z = 2
}			t_axis;

// main
t_p_3d	*read_p_3d_from_file(const char *file_path, int *p_num);
void	init_object(t_p_3d *p_3ds, const int p_num);
void	loop_draw_object(t_p_3d *p_3ds, const int p_num);
void	draw_object_to_canvas(t_p_3d *p_3ds,
			const int p_num, char canvas[CANVAS_HEIGHT][CANVAS_WIDTH]);

// utils
void	rotate_3d_object(t_p_3d *p_3ds,
			const int p_num, const t_axis axis, const double angle);
void	clear_terminal(void);
void	move_cursor_to_top(void);
void	clear_terminal_behind_cursor(void);
int		get_next_line(int fd, char **line);
void	exit_with_errout(const char *errmsg);
void	exit_with_perrout(const char *str);
void	print_p_3d(t_p_3d *p_3ds, const int p_num);

#endif
