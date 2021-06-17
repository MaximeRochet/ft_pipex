/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:35:21 by mrochet           #+#    #+#             */
/*   Updated: 2021/06/17 13:34:10 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	error(char *str)
{
	write(2, str, ft_strlen(str));
	return (0);
}

int	child_1(int fd_file, int *pipes, char *cmd, char **env)
{
	char	**command;

	command = ft_split(cmd, ' ');
	close(pipes[0]);
	dup2(pipes[1], 1);
	close(pipes[1]);
	dup2(fd_file, 0);
	close(fd_file);
	if (command[0][0] == '/')
	{
		if (execve(command[0], command, env) == -1)
		{
			free_tab(command);
			return (error("command 1 invalid\n"));
		}
	}
	else
		ft_exec(command, env);
	return (0);
}

int	child_2(int fd_file, int *pipes, char *cmd, char **env)
{
	char	**command;

	command = ft_split(cmd, ' ');
	close(pipes[1]);
	dup2(pipes[0], 0);
	close(pipes[0]);
	dup2(fd_file, 1);
	close(fd_file);
	if (command[0][0] == '/')
	{
		if (execve(command[0], command, env) == -1)
		{
			free_tab(command);
			return (error("command 2 invalid\n"));
		}
	}
	else
		ft_exec(command, env);
	return (0);
}

int	ft_pipex(t_fd fd, char *cmd1, char *cmd2, char **env)
{
	int	pid;
	int	status;
	int	pipes[2];
	int	fd1;
	int	fd2;

	fd1 = fd.fd1;
	fd2 = fd.fd2;
	pipe(pipes);
	pid = fork();
	if (pid == -1)
		return (error("Error first fork\n"));
	if (pid == 0)
	{
		child_1(fd1, pipes, cmd1, env);
		exit(0);
	}
	else
	{
		wait(&status);
		child_2(fd2, pipes, cmd2, env);
		exit(0);
	}
	return (0);
}

int	main(int ac, char **av, char **env)
{
	t_fd	fd;

	if (ac == 5)
	{
		fd.fd1 = open (av[1], O_DIRECTORY);
		if (fd.fd1 > 0)
		{
			close(fd.fd1);
			return (error("T'es un correcteur relou ! \n"));
		}
		close(fd.fd1);
		fd.fd1 = open(av[1], O_RDONLY);
		fd.fd2 = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
		if (fd.fd1 == -1 || fd.fd2 == -1)
		{
			close(fd.fd1);
			close(fd.fd2);
			return (error("file 1 or file2 invalid\n"));
		}
		ft_pipex(fd, av[2], av[3], env);
	}
	else
		return (error("command : ./pipex file1 \"cmd1\" \"cmd2\" file2\n"));
	return (0);
}
