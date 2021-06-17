/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_second.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 16:41:34 by mrochet           #+#    #+#             */
/*   Updated: 2021/06/17 13:10:55 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

char	*join_path(char *path, char *fct_name)
{
	char	*full_path;
	int		size;
	int		i;
	int		y;

	i = 0;
	y = 0;
	size = ft_strlen(path) + ft_strlen(fct_name) + 2;
	full_path = (char *)malloc(size);
	while (path[i])
		full_path[y++] = path[i++];
	full_path[y++] = '/';
	i = 0;
	while (fct_name[i])
		full_path[y++] = fct_name[i++];
	full_path[y] = 0;
	return (full_path);
}

char	**get_path(char **env)
{
	char	**tab;
	char	*path;
	int		i;

	i = 0;
	while (env[i])
	{
		if ((ft_strncmp((const char *)env[i], "PATH=", 5)) == 0)
		{
			path = env[i] + 5;
			i = 0;
			tab = ft_split(path, ':');
			break ;
		}
		i++;
	}
	return (tab);
}

int	ft_exec(char **command, char **env)
{
	char	**line_path;
	char	*full_path;
	int		i;
	int		value;

	i = 0;
	line_path = get_path(env);
	while (line_path[i])
	{
		full_path = join_path(line_path[i], command[0]);
		value = execve(full_path, command, env);
		if (value != -1)
		{
			free_tab(line_path);
			return (0);
		}
		i++;
	}	
	free_tab(line_path);
	if (i >= 0)
		return (error("command not found\n"));
	return (0);
}
