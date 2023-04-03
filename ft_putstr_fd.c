/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:27:53 by phijano-          #+#    #+#             */
/*   Updated: 2022/07/12 12:05:19 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpipex.h"

void	ft_putstr_fd(char *s, int fd)
{
	unsigned int	count;

	count = -1;
	while (s[++count])
		write(fd, &s[count], 1);
}
