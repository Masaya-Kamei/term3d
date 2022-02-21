/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 17:49:33 by mkamei            #+#    #+#             */
/*   Updated: 2022/01/24 15:48:13 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	const size_t	d_len = ft_strlen(dst);

	if (d_len >= size)
		return (size + ft_strlen(src));
	return (d_len + ft_strlcpy(&dst[d_len], src, size - d_len));
}
