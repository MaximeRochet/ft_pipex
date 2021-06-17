/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 12:07:35 by mrochet           #+#    #+#             */
/*   Updated: 2021/06/17 13:33:10 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <errno.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct s_fd {
	int	fd1;
	int	fd2;
}				t_fd;

int		ft_pipex(t_fd fd, char *cmd1, char *cmd2, char **env);
int		ft_exec(char **command, char **env);
int		error(char *str);
void	free_tab(char **str);

#endif
