/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:56:29 by phijano-          #+#    #+#             */
/*   Updated: 2022/07/22 12:26:49 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_exit(int status)
{
	int	exit;

	exit = 0;
	if (((status) & 0x7f) == 0)
		exit = 1;
	return (exit);
}

int	ft_exit_code(int status)
{
	return (((status) & 0xff00) >> 8);
}
