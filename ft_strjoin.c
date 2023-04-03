/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:23:48 by phijano-          #+#    #+#             */
/*   Updated: 2022/07/13 12:56:39 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*pnt_str;
	int		length;

	length = ft_strlen(s1) + ft_strlen(s2);
	pnt_str = (char *)malloc(sizeof (*pnt_str) * (length + 1));
	if (!pnt_str)
		return (NULL);
	pnt_str[0] = '\0';
	ft_strlcat(pnt_str, s1, ft_strlen(s1) + 1);
	ft_strlcat(pnt_str, s2, length + 1);
	return (pnt_str);
}
