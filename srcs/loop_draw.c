/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 10:21:26 by mkamei            #+#    #+#             */
/*   Updated: 2022/02/22 18:08:05 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term3d.h"

static void	init_canvas(char canvas[CANVAS_HEIGHT][CANVAS_WIDTH])
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

static void	print_canvas(char canvas[CANVAS_HEIGHT][CANVAS_WIDTH])
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

void	loop_draw_object(t_p_3d *p_3ds, const int p_num)
{
	char	canvas[CANVAS_HEIGHT][CANVAS_WIDTH];
	t_axis	rotate_axis;
	int		rotate_count;

	clear_terminal();
	rotate_axis = X;
	while (rotate_axis < 3)
	{
		rotate_count = 0;
		while (rotate_count <= ROT_ANGLE_DENOM * 2)
		{
			move_cursor_to_top();
			init_canvas(canvas);
			draw_object_to_canvas(p_3ds, p_num, canvas);
			print_canvas(canvas);
			clear_terminal_behind_cursor();
			if (ROT_ANGLE_DENOM == 0)
				return ;
			usleep(USLEEP_TIME);
			rotate_3d_object(p_3ds, p_num, rotate_axis, PI / ROT_ANGLE_DENOM);
			rotate_count++;
		}
		rotate_axis++;
	}
}
