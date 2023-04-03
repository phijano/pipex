/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:23:29 by phijano-          #+#    #+#             */
/*   Updated: 2022/07/12 14:05:17 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpipex.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*pnt_str;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		pnt_str = (char *)malloc(sizeof(*pnt_str));
		if (!pnt_str)
			return (NULL);
		pnt_str[0] = '\0';
		return (pnt_str);
	}
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	pnt_str = (char *)malloc(sizeof(*pnt_str) * (len + 1));
	if (!pnt_str)
		return (NULL);
	ft_strlcpy(pnt_str, &s[start], len + 1);
	return (pnt_str);
}
