/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:55:02 by phijano-          #+#    #+#             */
/*   Updated: 2022/07/26 13:17:02 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpipex.h"

int	ft_isalnum(int c)
{
	if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z') && (c < '0' || c > '9'))
		return (0);
	return (c);
}

void	ft_free_split(char **array)
{
	int	count;

	count = -1;
	while (array[++count])
		free(array[count]);
	free(array[count]);
	free(array);
}

char	*ft_fix_cmd(char *cmd)
{
	int		count;
	int		count_new;
	int		count_fix;
	char	*new;

	count = -1;
	count_fix = 0;
	while (cmd[++count])
	{
		if (cmd[count] == '\"')
			count_fix--;
	}
	new = (char *)malloc(sizeof(char) * (ft_strlen(cmd) + 1 + count_fix));
	count = -1;
	count_new = 0;
	while (cmd[++count])
	{
		if (cmd[count] != '\"' && cmd[count] != '\'')
			new[count_new++] = cmd[count];
		if (cmd[count] == '\"' && count > 0)
			if (cmd[count - 1] == '\\')
				new[count_new - 1] = '\"';
	}
	new[count_new] = '\0';
	return (new);
}

int	ft_has_path(char *cmd)
{
	int	count;
	int	bar;
	int	no_path;

	bar = 0;
	no_path = 0;
	count = -1;
	while (cmd[++count])
	{
		if (cmd[count] == '\"' || cmd[count] == '\'' || cmd[count] == ' ')
			no_path = 1;
		if (cmd[count] == '/' && no_path == 0)
			bar = 1;
	}
	return (bar);
}
