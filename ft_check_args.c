/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:50:38 by phijano-          #+#    #+#             */
/*   Updated: 2022/07/25 10:28:38 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpipex.h"

void	ft_arg_error(char *s, int error)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(s, 2);
	if (error == 0)
		ft_putstr_fd(": No such file or directory\n", 2);
	else
		ft_putstr_fd(": command not found\n", 2);
}

void	ft_check_cmd(char **path, char *cmd)
{
	int		count;
	int		exist;
	char	*path_cmd;
	char	*temp_cmd;

	count = -1;
	exist = 0;
	temp_cmd = ft_fix_cmd(cmd);
	if (access(temp_cmd, F_OK) != -1)
		exist = 1;
	while (path[++count] && exist == 0)
	{
		path_cmd = ft_strjoin(path[count], temp_cmd);
		if (access(path_cmd, F_OK) != -1)
			exist = 1;
		free(path_cmd);
	}
	if (exist == 0)
		ft_arg_error(temp_cmd, 1);
	free(temp_cmd);
}

void	ft_check_number_args(int argc)
{
	if (argc < 5)
	{
		ft_putstr_fd("Error not enough arguments\n", 2);
		exit(1);
	}
}

void	ft_check_files(char **argv)
{
	int		f1;
	int		f2;

	f1 = open(argv[1], O_RDONLY);
	f2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (f1 < 0)
		ft_arg_error(argv[1], 0);
	if (f2 < 0)
		ft_arg_error(argv[4], 0);
}

void	ft_check_arg(int argc, char **argv, char **envp)
{
	int		count;
	char	**split_cmd;
	char	**path;

	ft_check_number_args(argc);
	ft_check_files(argv);
	path = ft_get_path(envp);
	count = 1;
	while (++count < argc - 1)
	{
		if (argv[count][0] == '.')
			ft_check_cmd(path, argv[count]);
		else
		{
			split_cmd = ft_split(argv[count], ' ');
			if (split_cmd[0])
				ft_check_cmd(path, split_cmd[0]);
			else
				ft_arg_error("", 1);
			ft_free_split(split_cmd);
		}
	}
	ft_free_split(path);
}
