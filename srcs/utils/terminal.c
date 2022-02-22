/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 10:25:32 by mkamei            #+#    #+#             */
/*   Updated: 2022/02/22 10:39:57 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term3d.h"

void	clear_terminal(void)
{
	puts("\033[2J");
}

void	move_cursor_to_top(void)
{
	puts("\033[1;1H");
}

void	clear_terminal_behind_cursor(void)
{
	puts("\033[0J");
}
