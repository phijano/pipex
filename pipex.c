/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:35:40 by phijano-          #+#    #+#             */
/*   Updated: 2022/07/26 14:36:14 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpipex.h"

void	ft_child_read(int *fd, char **argv, char **envp)
{
	int		fd_infile;
	char	**cmd_args;
	char	**path;

	close(fd[0]);
	fd_infile = open(argv[1], O_RDONLY);
	if (fd_infile == -1)
		exit(0);
	dup2(fd_infile, STDIN_FILENO);
	close(fd_infile);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	cmd_args = ft_split(argv[2], ' ');
	if (ft_has_path(argv[2]))
		ft_do_script(&argv[2], cmd_args, envp);
	path = ft_get_path(envp);
	ft_do_cmd(path, cmd_args, envp);
	free(path);
	free(cmd_args);
}

void	ft_child_write(int *fd, char **argv, char **envp)
{
	int		fd_outfile;
	char	**cmd_args;
	char	**path;

	close(fd[1]);
	fd_outfile = open(argv[4], O_WRONLY | O_CREAT
			| O_TRUNC | O_APPEND, S_IRWXU);
	if (fd_outfile < 0)
		exit(1);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	dup2(fd_outfile, STDOUT_FILENO);
	cmd_args = ft_split(argv[3], ' ');
	if (ft_has_path(argv[3]))
		ft_do_script(&argv[3], cmd_args, envp);
	path = ft_get_path(envp);
	ft_do_cmd(path, cmd_args, envp);
	free(path);
	free(cmd_args);
}

int	ft_father(int *fd, int pid, int error)
{
	int		status;

	close(fd[0]);
	close(fd[1]);
	waitpid(pid, &status, 0);
	if (ft_exit(status))
		error = ft_exit_code(status);
	return (error);
}

int	ft_pipex(char **argv, char **envp)
{
	pid_t	pid;
	int		fd[2];
	int		error;

	error = 0;
	pipe(fd);
	pid = fork();
	if (pid == -1)
		perror("Error");
	else if (pid == 0)
		ft_child_read(fd, argv, envp);
	else
	{
		pid = fork();
		if (pid == -1)
			perror("Error");
		else if (pid == 0)
			ft_child_write(fd, argv, envp);
		else
			error = ft_father(fd, pid, error);
	}
	return (error);
}

int	main(int argc, char **argv, char **envp)
{
	int	error;

	error = 0;
	ft_check_arg(argc, argv, envp);
	error = ft_pipex(argv, envp);
	return (error);
}
