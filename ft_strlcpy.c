/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:17:05 by phijano-          #+#    #+#             */
/*   Updated: 2022/07/19 11:57:53 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpipex.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	count_dst;
	size_t	count_src;
	size_t	src_size;

	src_size = 0;
	while (src[src_size])
		src_size++;
	if (dstsize == 0)
		return (src_size);
	count_src = -1;
	count_dst = 0;
	while (src[++count_src] && count_src < (dstsize - 1))
	{
		if (count_src > 0)
			if (src[count_src] == '\"' && src[count_src -1] == '\\')
				count_dst--;
		dst[count_dst++] = src[count_src];
	}
	dst[count_dst] = '\0';
	return (src_size);
}
