/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:44:59 by phijano-          #+#    #+#             */
/*   Updated: 2022/07/21 13:48:01 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpipex.h"

char	*ft_strdup(const char *s1)
{
	char	*pnt_str;
	int		count;

	count = 0;
	while (s1[count])
		count++;
	pnt_str = (char *)malloc(sizeof (*pnt_str) * (count + 1));
	if (!pnt_str)
		return (NULL);
	count = 0;
	while (s1[count])
	{
		pnt_str[count] = s1[count];
		count++;
	}
	pnt_str[count] = '\0';
	return (pnt_str);
}
