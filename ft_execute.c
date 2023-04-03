/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 10:26:00 by phijano-          #+#    #+#             */
/*   Updated: 2022/07/26 14:36:57 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpipex.h"

void	ft_do_script(char **cmd, char **cmd_args, char **envp)
{
	char	*fix_cmd;
	int		exist_cmd;

	exist_cmd = 0;
	fix_cmd = ft_fix_cmd(cmd[0]);
	if (access(fix_cmd, F_OK) != -1)
	{
		exist_cmd = 1;
		if (access(fix_cmd, X_OK) == -1)
			exit(0);
		else if (execve(fix_cmd, cmd_args, envp) == -1)
			exit(1);
	}
	free(fix_cmd);
	if (exist_cmd == 0)
		exit(127);
}

void	ft_do_cmd(char **path, char **cmd_args, char **envp)
{
	int		count;
	char	*path_cmd;
	int		cmd;

	cmd = 0;
	count = -1;
	while (path[++count])
	{
		path_cmd = ft_strjoin(path[count], cmd_args[0]);
		if (access(path_cmd, F_OK) != -1)
		{	
			cmd = 1;
			if (execve(path_cmd, cmd_args, envp) == -1)
				exit(1);
		}
		free(path_cmd);
	}
	if (cmd == 0)
		exit(127);
}
