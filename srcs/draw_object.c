/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:35:14 by mkamei            #+#    #+#             */
/*   Updated: 2022/02/23 10:47:02 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term3d.h"

static t_p_2d	perspective_projection(t_p_3d p_3d)
{
	const double	max_abs_z = fmin(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2);
	const double	new_max_abs_z = (MIN_SCALE_DENOM - 1) / 2.0;
	const double	scaled_z = (p_3d.z / max_abs_z) * new_max_abs_z;
	const double	shifted_z = scaled_z + Z_SCREEN - new_max_abs_z;
	t_p_2d			p_2d;

	p_2d.x = (p_3d.x * Z_SCREEN) / shifted_z;
	p_2d.y = (p_3d.y * Z_SCREEN) / shifted_z;
	return (p_2d);
}

static t_p_2d	get_canvas_p_2d_from_p_3d(t_p_3d p_3d)
{
	t_p_2d	p_2d;

	p_2d = perspective_projection(p_3d);
	p_2d.x *= TER_CHAR_Y_PER_X;
	p_2d.y *= -1;
	p_2d.x += (CANVAS_WIDTH - 1) / 2;
	p_2d.y += (CANVAS_HEIGHT - 1) / 2;
	return (p_2d);
}

static void	draw_point_to_canvas(
	t_p_2d p, char canvas[CANVAS_HEIGHT][CANVAS_WIDTH])
{
	if (p.x >= 0 && p.x < CANVAS_WIDTH && p.y >= 0 && p.y < CANVAS_HEIGHT)
	{
		canvas[(int)p.y][(int)p.x] = '.';
	}
}

static void	draw_line_to_canvas(
	t_p_2d p, t_p_2d q, char canvas[CANVAS_HEIGHT][CANVAS_WIDTH])
{
	double	x_step;
	double	y_step;
	int		count;

	x_step = q.x - p.x;
	y_step = q.y - p.y;
	count = ceil(fmax(fabs(x_step), fabs(y_step)));
	if (count == 0)
		return ;
	x_step /= count;
	y_step /= count;
	while (count > 0)
	{
		draw_point_to_canvas(p, canvas);
		p.x += x_step;
		p.y += y_step;
		count--;
	}
}

void	draw_object_to_canvas(
	t_p_3d *p_3ds, const int p_num, char canvas[CANVAS_HEIGHT][CANVAS_WIDTH])
{
	int		i;
	t_p_2d	p_2d;
	t_p_2d	prev_p_2d;

	i = 0;
	while (i < p_num)
	{
		p_2d = get_canvas_p_2d_from_p_3d(p_3ds[i]);
		if (LINE_DRAW_FLAG)
		{
			if (i != 0)
				draw_line_to_canvas(prev_p_2d, p_2d, canvas);
			prev_p_2d = p_2d;
		}
		else
			draw_point_to_canvas(p_2d, canvas);
		i++;
	}
}
