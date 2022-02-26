/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 10:21:26 by mkamei            #+#    #+#             */
/*   Updated: 2022/02/26 16:17:10 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term3d.h"

static void	init_canvas(t_canvas canvas)
{
	int		i;

	i = 0;
	while (i < CANVAS_HEIGHT)
	{
		ft_memset(canvas[i], ' ', CANVAS_WIDTH);
		i++;
	}
}

static void	putchar_num(const char c, const int width)
{
	int		i;

	i = 0;
	while (i < width)
	{
		write(STDOUT_FILENO, &c, 1);
		i++;
	}
}

static void	print_canvas(t_canvas canvas)
{
	int		i;

	putchar_num('-', CANVAS_WIDTH + 2);
	write(STDOUT_FILENO, "\n", 1);
	i = 0;
	while (i < CANVAS_HEIGHT)
	{
		write(STDOUT_FILENO, "|", 1);
		write(STDOUT_FILENO, canvas[i], CANVAS_WIDTH);
		write(STDOUT_FILENO, "|\n", 2);
		i++;
	}
	putchar_num('-', CANVAS_WIDTH + 2);
	write(STDOUT_FILENO, "\n", 1);
}

static void	draw_object(t_p_3d *p_3ds, const int p_num)
{
	t_canvas	canvas;

	move_cursor_to_top();
	init_canvas(canvas);
	draw_object_to_canvas(p_3ds, p_num, canvas);
	print_canvas(canvas);
	clear_terminal_behind_cursor();
}

void	loop_draw_object(t_p_3d *p_3ds, const int p_num)
{
	t_axis	rotate_axis;
	double	total_rotate_angle;

	clear_terminal();
	draw_object(p_3ds, p_num);
	if (ROTATE_ANGLE == 0)
		return ;
	rotate_axis = X;
	while (rotate_axis < 3)
	{
		total_rotate_angle = 0;
		while (total_rotate_angle < 2 * PI)
		{
			usleep(USLEEP_TIME);
			rotate_3d_object(p_3ds, p_num, rotate_axis, ROTATE_ANGLE);
			total_rotate_angle += ROTATE_ANGLE;
			draw_object(p_3ds, p_num);
		}
		rotate_axis++;
	}
}
