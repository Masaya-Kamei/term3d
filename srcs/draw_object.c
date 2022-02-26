/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:35:14 by mkamei            #+#    #+#             */
/*   Updated: 2022/02/26 16:16:03 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term3d.h"

// 透視投影
// カメラの位置を原点、投影されるスクリーンをz=-1 のときのxy 平面とする。
// z=-1 より 奥(zの負の方向) に図形を配置して、縮小のみ考える。
// 一番手前にある点を 1 倍 (ここは固定)、
// 一番奥にある点を 1/2 倍 (MIN_SCALE 最小縮尺 = 1/2) にしたい場合、
// 元々のz -> scaled_z [-0.5 ~ 0.5] -> shifted_z [-2 ~ -1] -> scale [1/2 ~ 1]

static t_p_2d	perspective_projection(t_p_3d p_3d)
{
	const double	max_abs_z = get_min_distance_from_canvas_center_to_end();
	const double	new_max_abs_z = ((1 / MIN_SCALE) - 1) / 2.0;
	const double	scaled_z = (p_3d.z / max_abs_z) * new_max_abs_z;
	const double	shifted_z = scaled_z - new_max_abs_z + SCREEN_Z;
	t_p_2d			p_2d;

	p_2d.x = (p_3d.x * SCREEN_Z) / shifted_z;
	p_2d.y = -(p_3d.y * SCREEN_Z) / shifted_z;
	return (p_2d);
}

static t_p_2d	get_canvas_p_2d_from_p_3d(t_p_3d p_3d)
{
	t_p_2d	canvas_p_2d;

	canvas_p_2d = perspective_projection(p_3d);
	canvas_p_2d.x *= TERMINAL_CHAR_Y_PER_X;
	canvas_p_2d.x += (CANVAS_WIDTH - 1) / 2;
	canvas_p_2d.y += (CANVAS_HEIGHT - 1) / 2;
	return (canvas_p_2d);
}

static void	draw_point_to_canvas(t_p_2d p, t_canvas canvas)
{
	if (p.x >= 0 && p.x < CANVAS_WIDTH && p.y >= 0 && p.y < CANVAS_HEIGHT)
	{
		canvas[(int)p.y][(int)p.x] = '.';
	}
}

static void	draw_line_to_canvas(t_p_2d p, t_p_2d q, t_canvas canvas)
{
	double	x_step;
	double	y_step;
	int		draw_count;

	draw_point_to_canvas(p, canvas);
	x_step = q.x - p.x;
	y_step = q.y - p.y;
	draw_count = ceil(fmax(fabs(x_step), fabs(y_step)));
	if (draw_count == 0)
		return ;
	x_step /= draw_count;
	y_step /= draw_count;
	while (draw_count > 0)
	{
		p.x += x_step;
		p.y += y_step;
		draw_point_to_canvas(p, canvas);
		draw_count--;
	}
}

void	draw_object_to_canvas(t_p_3d *p_3ds, const int p_num, t_canvas canvas)
{
	int		i;
	t_p_2d	canvas_p;
	t_p_2d	prev_canvas_p;

	i = 0;
	while (i < p_num)
	{
		canvas_p = get_canvas_p_2d_from_p_3d(p_3ds[i]);
		if (LINE_DRAW_FLAG)
		{
			if (i != 0)
				draw_line_to_canvas(prev_canvas_p, canvas_p, canvas);
			prev_canvas_p = canvas_p;
		}
		else
			draw_point_to_canvas(canvas_p, canvas);
		i++;
	}
}
