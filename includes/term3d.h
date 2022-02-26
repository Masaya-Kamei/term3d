/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:11:59 by mkamei            #+#    #+#             */
/*   Updated: 2022/02/25 12:12:59 by mkamei           ###   ########.fr       */
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
// 出力される２次元配列の幅と高さ
# define CANVAS_WIDTH 100
# define CANVAS_HEIGHT 40
// 追加の拡大・縮小
# define ZOOM_IN_ADDITION 1.0
// 初期の図形の向き
# define INIT_ROTATE_X (PI/4.0)
# define INIT_ROTATE_Y 0.0
# define INIT_ROTATE_Z 0.0
// 描画間隔
# define USLEEP_TIME 100000
// 1回分の回転角度
# define ROTATE_ANGLE (PI/48.0)
// 3dファイル上で連続している点と点を繋いだ直線を書くかどうか
# define LINE_DRAW_FLAG 1
// ターミナル上の文字の縦横比
# define TERMINAL_CHAR_Y_PER_X 2.5
// 1/2 の場合、スクリーン上にある点を等倍、スクリーンから一番遠い点を1/2倍
// 1/4 の場合、スクリーン上にある点を等倍、スクリーンから一番遠い点を1/4倍
# define MIN_SCALE (1/2.0)

// constant
# define GNL_BUFFER_SIZE 1000
# define PI 3.141592653589793
// スクリーン(xy平面) のz 座標 (固定)
# define SCREEN_Z -1

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
void	rotate_3d_object(t_p_3d *p_3ds,
			const int p_num, const t_axis axis, const double angle);

// utils
double	get_min_distance_from_canvas_center_to_end(void);
void	clear_terminal(void);
void	move_cursor_to_top(void);
void	clear_terminal_behind_cursor(void);
int		get_next_line(int fd, char **line);
void	exit_with_errout(const char *errmsg);
void	exit_with_perrout(const char *str);
void	print_p_3d(t_p_3d *p_3ds, const int p_num);

#endif
