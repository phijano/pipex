/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:17:33 by phijano-          #+#    #+#             */
/*   Updated: 2022/07/12 14:46:04 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpipex.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	count_dst;
	size_t	count_src;

	count_dst = 0;
	count_src = 0;
	while (dst[count_dst])
		count_dst++;
	if (dstsize < count_dst)
	{
		while (src[count_src])
			count_src++;
		return (dstsize + count_src);
	}
	while (dstsize > 0 && count_dst < dstsize - 1 && src[count_src])
		dst[count_dst++] = src[count_src++];
	dst[count_dst] = '\0';
	while (src[count_src++])
		count_dst++;
	return (count_dst);
}
